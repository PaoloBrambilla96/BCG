from django.shortcuts import render, redirect
import numpy as np
#from scipy.io import loadmat
import pandas as pd
import plotly
import plotly.express as px
import json
import time
import subprocess
import os
import shutil
from datetime import datetime
#import matlab.engine

from django.http import FileResponse
from django.contrib import messages
from django.contrib.auth import authenticate, login, logout

import io
from reportlab.pdfgen import canvas
from reportlab.lib.units import inch
from reportlab.lib.pagesizes import A4
from reportlab.lib import colors
from reportlab.platypus import SimpleDocTemplate, Table, TableStyle

import autoparts.db.autoparts_db_management as db
import platform

OS = platform.system()
if OS == "Windows":
	ABSOLUTE_PATH = "C:/BCG/bcg_website/"
	ORIGINAL_MODEL_ZIP_PATH = "C:/BCG/bcg_website/autoparts/simulation_files/Carware_final2.zip"
elif OS == "Linux":
	ABSOLUTE_PATH = "/home/ubuntu/BCG/bcg_website/"
	ORIGINAL_MODEL_ZIP_PATH = "/home/ubuntu/BCG/bcg_website/autoparts/simulation_files/Carware_final2.zip"




[bia_running_v, strategy_running_v] = np.load("01_autoparts_running.npy", allow_pickle=True)


def bia_running(request):
	global bia_running_v, strategy_running_v
	bia_running_v =  not bia_running_v
	np.save("01_autoparts_running.npy", [bia_running_v, strategy_running_v])
	return redirect("common-control")



def strategy_running(request):
	global bia_running_v, strategy_running_v
	strategy_running_v =  not strategy_running_v
	np.save("01_autoparts_running.npy", [bia_running_v, strategy_running_v])
	return redirect("common-control")


def introduction(request):
	return render(request,
		"autoparts/00_introduction.html",
		{'bia_running': bia_running_v,
		'strategy_running': strategy_running_v})


def description(request):
	return render(request,
		"autoparts/01_description.html",
		{'bia_running': bia_running_v,
		'strategy_running': strategy_running_v})


def suppliers(request):
	return render(request,
		"autoparts/02_suppliers.html",
		{'bia_running': bia_running_v,
		'strategy_running': strategy_running_v})


def resilience(request):
	return render(request,
		"autoparts/03_resilience.html",
		{'bia_running': bia_running_v,
		'strategy_running': strategy_running_v})


def bia(request):
	if "impacts" in request.session and "MTPDs" in request.session and "RTOs" in request.session:
		pass
	else:
		request.session["impacts"] = np.zeros(100).tolist()
		request.session["MTPDs"] = [3,3,3,3]
		request.session["RTOs"] = [3,3,3,3]

	if request.method == "POST":
		print("entered in POST METHOD")
		impacts=[]
		MTPDs=[]
		RTOs=[]
		for k in range(10):
			for i in range(10):
				impacts.append(int(request.POST["table_"+str(k)+"_"+str(i)]))
		print("entered in POST METHOD")
		for j in range(4):
			MTPDs.append(int(request.POST["MTPD_"+str(j)]))
			RTOs.append(int(request.POST["RTO_"+str(j)]))
		print("entered in POST METHOD")
		request.session["impacts"] = impacts
		request.session["MTPDs"] = MTPDs
		request.session["RTOs"] = RTOs

		return redirect("autoparts-bia")

	else:
		selectnames=[]
		for m in range(10):
			for n in range(10):
				selectnames.append("table_"+str(m)+"_"+str(n))
		mtpdnames=[]
		for j in range(4):
			mtpdnames.append(str(j))
		impacts = request.session["impacts"]
		MTPDs = request.session["MTPDs"]
		RTOs = request.session["RTOs"]
		return render(request,
			"autoparts/04_bia.html",
			{'cols': [0,1,2,3,4,5,6,7,8,9],
			'selectnames': zip(selectnames, impacts),
			'mtpdnames': zip(mtpdnames, MTPDs),
			'rtonames': zip(mtpdnames, RTOs),
			'bia_running': bia_running_v,
			'strategy_running': strategy_running_v
			})




def threat(request):
	return render(request,
		"autoparts/05_threat.html",
		{'bia_running': bia_running_v,
		'strategy_running': strategy_running_v})


def vulnerability(request):
	return render(request,
		"autoparts/06_vulnerability.html",
		{'bia_running': bia_running_v,
		'strategy_running': strategy_running_v})


def insurance(request):
	return render(request,
		"autoparts/07_insurance.html",
		{'bia_running': bia_running_v,
		'strategy_running': strategy_running_v})


def solutions(request):
	return render(request,
		"autoparts/08_solutions.html",
		{'bia_running': bia_running_v,
		'strategy_running': strategy_running_v})


def strategy(request):
	if 'inputs_data' in request.session:
		pass
	else:		
		request.session["inputs_data"] = [5, 10, 10, 10, 10, 5, 10, 10, 10, 10]
	if 'radio_state' in request.session:
		pass
	else:
		request.session["radio_state"] = [0, 0, 0, 0, 0]
	if 'insurance' in request.session:
		pass
	else:
		request.session["insurance"] = 0
	if 'investment' in request.session:
		pass
	else:
		request.session["investment"] = 0

	if request.method == "POST":
		v0 = int(request.POST["input0"])
		v1 = int(request.POST["input1"])
		v2 = int(request.POST["input2"])
		v3 = int(request.POST["input3"])
		v4 = int(request.POST["input4"])
		v5 = int(request.POST["input5"])
		v6 = int(request.POST["input6"])
		v7 = int(request.POST["input7"])
		v8 = int(request.POST["input8"])
		v9 = int(request.POST["input9"])
		r0 = int(request.POST["radio0"])
		r1 = int(request.POST["radio1"])
		r2 = int(request.POST["radio2"])
		r3 = int(request.POST["radio3"])
		r4 = int(request.POST["radio4"])
		request.session["inputs_data"] = [v0, v1, v2, v3, v4, v5, v6, v7, v8, v9]
		request.session["radio_state"] = [r0, r1, r2, r3, r4]
		request.session["insurance"] = int(request.POST["insurance"])
		print(request.POST["investment"])
		return redirect("autoparts-strategy")

	else:
		return render(request,
			"autoparts/09_strategy.html",
			{'bia_running': bia_running_v,
			'strategy_running': strategy_running_v})


def loading(request):
	if request.user.is_authenticated and strategy_running_v:
		return render(request,
				"autoparts/loading.html",
				{'bia_running': bia_running_v,
				'strategy_running': strategy_running_v})
	else:
		return redirect("autoparts-login")


def simulation(request):

	if request.user.is_authenticated and strategy_running_v:

		request.session["simulation_done"] = False
		request.session["pdf_server_saved"] = False
		clear_tmp_files(request)

		request.session["timestamp"] = datetime.now().strftime("%d/%m/%Y - %H:%M:%S")
		request.session["date"] = datetime.now().strftime("%Y-%m-%d")
		request.session["time"] = datetime.now().strftime("%H:%M:%S")
		request.session["timestamp2"] = datetime.now().strftime("%d-%m-%Y-%H-%M-%S")

		results={}
		magnitudes = [8.5, 7.5, 6.5, 5.5, 4.5]
		mag_names = ["eight", "seven", "six", "five", "four"]


		tmp_sim_folder = ABSOLUTE_PATH+"autoparts/simulation_files/tmp_sim_"+str(request.user)+"/"
		if os.path.exists(tmp_sim_folder):
			shutil.rmtree(tmp_sim_folder)
		if not os.path.exists(tmp_sim_folder):
			os.mkdir(tmp_sim_folder)

		comando_unzip = f'unzip {ORIGINAL_MODEL_ZIP_PATH} -d {tmp_sim_folder}'
		result = subprocess.run(comando_unzip, shell=True, stdout=subprocess.PIPE, text=True)

		for magnitude, magnitude_name in zip(magnitudes, mag_names):

			matlab_vector = []
			matlab_vector.append(request.session["insurance"])
			matlab_vector.append(magnitude)
			matlab_vector.extend(request.session["inputs_data"][0:7])
			matlab_vector.extend(request.session["radio_state"][0:2])
			matlab_vector.extend(request.session["inputs_data"][7:])
			matlab_vector.extend(request.session["radio_state"][2:])
			print(matlab_vector)

			c_data_string = '#include "Carware_final2.h" \nP_Carware_final2_T Carware_final2_P = {\n'
			for param in matlab_vector:
				c_data_string = c_data_string + f"{param:.1f}" + ",\n"
			additional_params = "1.0, 0.9, 0.0, 0.9, 1.7, 0.9, 1.0, 0.0, 0.9, 1.7, 0.9, 1.0, 0.9, 0.0, 1.7, 1.75, 0.5, 1.75, 0.25, 0.25, 1.75, 1.75, 1.75, 0.0, 0.0, 0.0, 1.0, 0.03, 0.04, 0.05, 1.0, 1.0, 0.075, 0.05, 0.0, 0.05, 0.05, 0.09, 0.125, 0.05, 0.002, 0.001, 0.002, 0.003, 3.0, 3.0, 1.0, 0.0, 1.0, 1.0, 0.0, 0.5, 1.0, 3.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 10.0, 1.0, 0.0, 0.2, 0.0, 0.2, 0.5, 0.8, 10.0, 1.0, 1.0, 3.0, 3.0, 0.4, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 10.0, 3.0, 20.0, 0.0, 0.0, 0.0, 0.002, 0.003, 1.0, 0.0, 1.0, 0.002, 0.0, 0.005"
			
			c_data_string = c_data_string + additional_params+ "\n};"

			os.remove(tmp_sim_folder+"carware_model/Carware_final2_grt_rtw/Carware_final2_data.c")
			textfile = open(tmp_sim_folder+"carware_model/Carware_final2_grt_rtw/Carware_final2_data.c", "w")
			textfile.write(c_data_string)
			textfile.close()

			comando_cd = f'cd {tmp_sim_folder}carware_model/Carware_final2_grt_rtw/'
			comando_cmake = f'cmake .'
			comando_make = f'make'

			comando_in_sequenza = f'{comando_cd} && {comando_cmake} && {comando_make}'
			result = subprocess.run(comando_in_sequenza, shell=True, stdout=subprocess.PIPE, text=True)

			exe_dir = f'{tmp_sim_folder}carware_model/Carware_final2'
			exe_folder = f'{tmp_sim_folder}carware_model/'

			while not os.path.exists(exe_dir):
				time.sleep(1)

			comando_cd = f'cd {exe_folder}'
			comando_exe = f'./Carware_final2'
			comando_in_sequenza = f'{comando_cd} && {comando_exe}'
			result = subprocess.run(comando_in_sequenza, shell=True, stdout=subprocess.PIPE, text=True)

			dati = loadmat(f'{exe_folder}results.mat')
			variabile = dati["result_values"]

			results[magnitude_name]=variabile

		scores = np.array([np.transpose(results["eight"][1:,-1]),
			np.transpose(results["seven"][1:,-1]),
			np.transpose(results["six"][1:,-1]),
			np.transpose(results["five"][1:,-1]),
			np.transpose(results["four"][1:,-1])
			])

		charts = np.vstack((results["eight"][9:11,:],
			results["eight"][18:22,:],
			results["seven"][9:11,:],
			results["seven"][18:22,:],
			results["six"][9:11,:],
			results["six"][18:22,:],
			results["five"][9:11,:],
			results["five"][18:22,:],
			results["four"][9:11,:],
			results["four"][18:22,:],
			))


		scores = np.around(np.array(scores),3)
		charts = np.around(np.array(charts),3)


		if os.path.exists(tmp_sim_folder):
			shutil.rmtree(tmp_sim_folder)



		##################################################################################
		
		request.session["scores_M8"] = scores[0,:].tolist()
		request.session["sums_M8"] = np.around(np.array([np.sum(request.session["scores_M8"][0:3]), np.sum(request.session["scores_M8"][3:8]), np.sum(request.session["scores_M8"][0:10])]),3).tolist()
		request.session["scores_M7"] = scores[1,:].tolist()
		request.session["sums_M7"] = np.around(np.array([np.sum(request.session["scores_M7"][0:3]), np.sum(request.session["scores_M7"][3:8]), np.sum(request.session["scores_M7"][0:10])]),3).tolist()
		request.session["scores_M6"] = scores[2,:].tolist()
		request.session["sums_M6"] = np.around(np.array([np.sum(request.session["scores_M6"][0:3]), np.sum(request.session["scores_M6"][3:8]), np.sum(request.session["scores_M6"][0:10])]),3).tolist()
		request.session["scores_M5"] = scores[3,:].tolist()
		request.session["sums_M5"] = np.around(np.array([np.sum(request.session["scores_M5"][0:3]), np.sum(request.session["scores_M5"][3:8]), np.sum(request.session["scores_M5"][0:10])]),3).tolist()
		request.session["scores_M4"] = scores[4,:].tolist()
		request.session["sums_M4"] = np.around(np.array([np.sum(request.session["scores_M4"][0:3]), np.sum(request.session["scores_M4"][3:8]), np.sum(request.session["scores_M4"][0:10])]),3).tolist()

		request.session["total_expected_loss"] = np.round(request.session["scores_M8"][16]*0.0033 + request.session["scores_M7"][16]*0.0109 + request.session["scores_M6"][16]*0.0325 + request.session["scores_M5"][16]*0.8721 + request.session["scores_M4"][16], 3) 
		request.session["total_implementation_cost"] = request.session["scores_M8"][10]
		request.session["total_insurance_price"] = request.session["scores_M8"][-1]

		request.session["total_expected_cost"] = np.round(request.session["total_expected_loss"] + request.session["total_implementation_cost"] + request.session["total_insurance_price"], 3)

		request.session["charts"] = charts.tolist()


		"""while not os.path.exists("autoparts/tmp_data/output_M4.txt"):
									time.sleep(1)"""

		request.session["simulation_done"] = True
		matlab_vector = []
		matlab_vector.extend(request.session["inputs_data"][0:7])
		matlab_vector.extend(request.session["radio_state"][0:2])
		matlab_vector.extend(request.session["inputs_data"][7:])
		matlab_vector.extend(request.session["radio_state"][2:])
		matlab_vector.append(request.session["insurance"])

		#db.new_sqlite3_data_line(date=request.session["date"], time=request.session["time"], group=str(request.user), in_data=matlab_vector, res=request.session["total_expected_cost"])

		print("FINE SIMULAZIONE")
		return redirect("autoparts-results")
	else:
		return redirect("autoparts-login")




def results_table(request):
	data = db.show_table()
	return render(request,
				"autoparts/autoparts_table.html",
				{
				'data' : data,
				})


def clear_table(request):
	db.create_sqlite3_DB()
	return redirect("common-control")





def results(request):
	print("RISULTATI")
	charts = np.array(request.session["charts"])

	loss_from_business_income_DF = pd.DataFrame({
			        't': np.arange(0,721),
			        'magnitude 8': charts[0,:],
			        'magnitude 7': charts[6,:],
			        'magnitude 6': charts[12,:],
			        'magnitude 5': charts[18,:],
			        'magnitude 4': charts[24,:],
			    })
	business_recovery_DF = pd.DataFrame({
			        't': np.arange(0,721),
			        'magnitude 8': charts[1,:],
			        'magnitude 7': charts[7,:],
			        'magnitude 6': charts[13,:],
			        'magnitude 5': charts[19,:],
			        'magnitude 4': charts[25,:],
			    })
	stock_raw_material_DF = pd.DataFrame({
			        't': np.arange(0,721),
			        'magnitude 8': charts[2,:],
			        'magnitude 7': charts[8,:],
			        'magnitude 6': charts[14,:],
			        'magnitude 5': charts[20,:],
			        'magnitude 4': charts[26,:],
			    })
	stock_internal_parts_DF = pd.DataFrame({
			        't': np.arange(0,721),
			        'magnitude 8': charts[3,:],
			        'magnitude 7': charts[9,:],
			        'magnitude 6': charts[15,:],
			        'magnitude 5': charts[21,:],
			        'magnitude 4': charts[27,:],
			    })
	stock_external_parts_DF = pd.DataFrame({
			        't': np.arange(0,721),
			        'magnitude 8': charts[4,:],
			        'magnitude 7': charts[10,:],
			        'magnitude 6': charts[16,:],
			        'magnitude 5': charts[22,:],
			        'magnitude 4': charts[28,:],
			    })
	stock_finished_products_DF = pd.DataFrame({
			        't': np.arange(0,721),
			        'magnitude 8': charts[5,:],
			        'magnitude 7': charts[11,:],
			        'magnitude 6': charts[17,:],
			        'magnitude 5': charts[23,:],
			        'magnitude 4': charts[29,:],
			    })

	fig_loss_from_business_income = px.line(loss_from_business_income_DF, x='t', y=['magnitude 8','magnitude 7', 'magnitude 6','magnitude 5', 'magnitude 4'], title="Loss from business income")
	fig_loss_from_business_income.update_layout(paper_bgcolor="rgba(0,0,0,0)")
	fig_business_recovery = px.line(business_recovery_DF, x='t', y=['magnitude 8','magnitude 7', 'magnitude 6','magnitude 5', 'magnitude 4'], title="Business recovery")
	fig_business_recovery.update_layout(paper_bgcolor="rgba(0,0,0,0)")
	fig_stock_raw_material = px.line(stock_raw_material_DF, x='t', y=['magnitude 8','magnitude 7', 'magnitude 6','magnitude 5', 'magnitude 4'], title="Raw material stock level")
	fig_stock_raw_material.update_layout(paper_bgcolor="rgba(0,0,0,0)")
	fig_stock_internal_parts = px.line(stock_internal_parts_DF, x='t', y=['magnitude 8','magnitude 7', 'magnitude 6','magnitude 5', 'magnitude 4'], title="Internal parts stock level")
	fig_stock_internal_parts.update_layout(paper_bgcolor="rgba(0,0,0,0)")
	fig_stock_external_parts = px.line(stock_external_parts_DF, x='t', y=['magnitude 8','magnitude 7', 'magnitude 6','magnitude 5', 'magnitude 4'], title="External parts stock level")
	fig_stock_external_parts.update_layout(paper_bgcolor="rgba(0,0,0,0)")
	fig_stock_finished_products = px.line(stock_finished_products_DF, x='t', y=['magnitude 8','magnitude 7', 'magnitude 6','magnitude 5', 'magnitude 4'], title="Finished products stock level")
	fig_stock_finished_products.update_layout(paper_bgcolor="rgba(0,0,0,0)")
	graphJSON0 = json.dumps(fig_loss_from_business_income, cls=plotly.utils.PlotlyJSONEncoder)
	graphJSON1 = json.dumps(fig_business_recovery, cls=plotly.utils.PlotlyJSONEncoder)
	graphJSON2 = json.dumps(fig_stock_raw_material, cls=plotly.utils.PlotlyJSONEncoder)
	graphJSON3 = json.dumps(fig_stock_internal_parts, cls=plotly.utils.PlotlyJSONEncoder)
	graphJSON4 = json.dumps(fig_stock_external_parts, cls=plotly.utils.PlotlyJSONEncoder)
	graphJSON5 = json.dumps(fig_stock_finished_products, cls=plotly.utils.PlotlyJSONEncoder)


	print("saving chart on disk")
	group = str(request.user)
	if not os.path.exists("autoparts/tmp_data/"+group+"/"):
			os.mkdir("autoparts/tmp_data/"+group+"/")
	print("directory created")
			
	if not os.path.exists("autoparts/tmp_data/"+group+"/figure1.png"):
		fig_loss_from_business_income.write_image("autoparts/tmp_data/"+group+"/figure1.png", width=400, height=300)
	if not os.path.exists("autoparts/tmp_data/"+group+"/figure2.png"):
		fig_business_recovery.write_image("autoparts/tmp_data/"+group+"/figure2.png", width=400, height=300)
	if not os.path.exists("autoparts/tmp_data/"+group+"/figure3.png"):
		fig_stock_raw_material.write_image("autoparts/tmp_data/"+group+"/figure3.png", width=400, height=300)
	if not os.path.exists("autoparts/tmp_data/"+group+"/figure4.png"):
		fig_stock_internal_parts.write_image("autoparts/tmp_data/"+group+"/figure4.png", width=400, height=300)
	if not os.path.exists("autoparts/tmp_data/"+group+"/figure5.png"):
		fig_stock_external_parts.write_image("autoparts/tmp_data/"+group+"/figure5.png", width=400, height=300)
	if not os.path.exists("autoparts/tmp_data/"+group+"/figure6.png"):
		fig_stock_finished_products.write_image("autoparts/tmp_data/"+group+"/figure6.png", width=400, height=300)

	print("generating pdf")


	
	if request.session["pdf_server_saved"]:
		pass
	else:
		pdf(request, download=0)

	print("finish")

	return render(request,
			"autoparts/10_results.html",
			{
			'graphJSON0': graphJSON0,
			'graphJSON1': graphJSON1,
			'graphJSON2': graphJSON2,
			'graphJSON3': graphJSON3,
			'graphJSON4': graphJSON4,
			'graphJSON5': graphJSON5,
			'bia_running': bia_running_v,
			'strategy_running': strategy_running_v
			})




def pdf(request, download):
	buf = io.BytesIO()
	c = canvas.Canvas(buf, pagesize=A4, bottomup=0)

	textob1 = c.beginText()
	textob1.setTextOrigin(50,260)
	textob1.setFont("Helvetica", 14)
	textob2 = c.beginText()
	textob2.setTextOrigin(50,330)
	textob2.setFont("Helvetica", 12)
	textob3 = c.beginText()
	textob3.setTextOrigin(50,80)
	textob3.setFont("Helvetica", 14)
	textob4 = c.beginText()
	textob4.setTextOrigin(50,80)
	textob4.setFont("Helvetica", 14)
	lines1=[]
	lines2=[]
	lines3=[]
	lines4=[]
	w, h = A4
	title = "Business Continuity Game - Auto parts manufacturer company"
	group = str(request.user)

	lines1.extend([title, group, request.session["timestamp"]])

	strategy0 = "Additional stocking capacity for finisched products: " + str(request.session["inputs_data"][0])
	strategy1 = "Additional stocking capacity for raw material: " + str(request.session["inputs_data"][1])
	strategy2 = "Additional stocking capacity for internal parts: " + str(request.session["inputs_data"][2])
	strategy3 = "Additional stocking capacity for external parts: " + str(request.session["inputs_data"][3])
	strategy4 = "Default stocking level for internal parts: " + str(request.session["inputs_data"][4])
	strategy5 = "Default stocking level for raw material: " + str(request.session["inputs_data"][5])
	strategy6 = "Default stocking level for external parts: " + str(request.session["inputs_data"][6])
	strategy7 = "Yes" if (request.session["radio_state"][0] == 1) else "No"
	strategy8 = "Yes" if (request.session["radio_state"][1] == 1) else "No"
	strategy9 = "Alternative outbound transport (Finished products): " + str(request.session["inputs_data"][7])
	strategy10 = "Alternative inbound transport (Raw material): " + str(request.session["inputs_data"][8])
	strategy11 = "Alternative inbound transport (Raw material): " + str(request.session["inputs_data"][9])
	strategy12 = "Yes" if (request.session["radio_state"][2] == 1) else "No"
	strategy13 = "Yes" if (request.session["radio_state"][3] == 1) else "No"
	strategy14 = "Yes" if (request.session["radio_state"][4] == 1) else "No"
	if request.session["insurance"]==6:
		strategy15 = "FULL insurance"
	elif request.session["insurance"]==0:
		strategy15 = "NO insurance"
	else:
		strategy15 = "Package " + str(request.session["insurance"])

	lines2.extend(["", "Solution 1", strategy0])
	lines2.extend(["", "Solution 2", strategy1, strategy2, strategy3, strategy4, strategy5, strategy6])
	lines2.extend(["", "Solution 3", "Backup manufacturing equipment: "+strategy7, "Backup assembly equipment: "+ strategy8] )
	lines2.extend(["", "Solution 4", strategy9, strategy10, strategy11])
	lines2.extend(["", "Solution 5", "Earthquake-proof Main Facility: "+strategy12, "Warehouse reinforcement: "+ strategy13, "Logistics Center reinforcement: "+ strategy14] )
	lines2.extend(["", "Solution 6", "Insurance: "+ strategy15])
	

	lines3.append("RESULTS")

	loss_from_business_disruption=  [
		['TOTAL [M€]',                              request.session["sums_M8"][2],   request.session["sums_M7"][2],   request.session["sums_M6"][2],   request.session["sums_M5"][2],   request.session["sums_M4"][2]   ],
        ['Business recovery [M€]',                  request.session["scores_M8"][9], request.session["scores_M7"][9], request.session["scores_M6"][9], request.session["scores_M5"][9], request.session["scores_M4"][9] ],
        ['Loss from business income [M€]',          request.session["scores_M8"][8], request.session["scores_M7"][8], request.session["scores_M6"][8], request.session["scores_M5"][8], request.session["scores_M4"][8] ],
        ['Damage to other properties [M€]',         request.session["sums_M8"][1],   request.session["sums_M7"][1],   request.session["sums_M6"][1],   request.session["sums_M5"][1],   request.session["sums_M4"][1]   ],
        ['Damage to physical infrastructures [M€]', request.session["sums_M8"][0],   request.session["sums_M7"][0],   request.session["sums_M6"][0],   request.session["sums_M5"][0],   request.session["sums_M4"][0]   ],
        ['Magnitude', '8+', '7-8', '6-7', '5-6', '5-'],
        ['EXPECTED LOSSES FROM BUSINESS DISRUPTION', '', '', '', '', '']
        ]
	t1=Table(loss_from_business_disruption, style= [('VALIGN',(0,0),(-1,-1),'MIDDLE'),
													('SPAN',(0,-1),(-1,-1)),
													('FONTSIZE',(0,0),(-1,-1), 12),
													('GRID', (0,0), (-1,-1), 1, colors.black),
												    ('LEFTPADDING', (0, 0), (-1, -1), 5),
												    ('RIGHTPADDING', (0, 0), (-1, -1), 5),
												    ('TOPPADDING', (0, 0), (-1, -1), -6),
												    ('BOTTOMPADDING', (0, 0), (-1, -1), 18),
                									('BACKGROUND',(0,-1),(-1,-1),colors.lightskyblue),
                									('BACKGROUND',(0,-2),(-1,-2),colors.lightsteelblue),
                									('BACKGROUND',(0,0),(-1,0),colors.aqua),
													])
	net_loss=  [
		['TOTAL [M€]',                    request.session["scores_M8"][16], request.session["scores_M7"][16], request.session["scores_M6"][16], request.session["scores_M5"][16], request.session["scores_M4"][16] ],
        ['Business recovery [M€]',        request.session["scores_M8"][15], request.session["scores_M7"][15], request.session["scores_M6"][15], request.session["scores_M5"][15], request.session["scores_M4"][15] ],
        ['Loss of business income [M€]',  request.session["scores_M8"][14], request.session["scores_M7"][14], request.session["scores_M6"][14], request.session["scores_M5"][14], request.session["scores_M4"][14] ],
        ['Other property [M€]',           request.session["scores_M8"][13], request.session["scores_M7"][13], request.session["scores_M6"][13], request.session["scores_M5"][13], request.session["scores_M4"][13] ],
        ['Physical infrastructure [M€]',  request.session["scores_M8"][12], request.session["scores_M7"][12], request.session["scores_M6"][12], request.session["scores_M5"][12], request.session["scores_M4"][12] ],
        ['Magnitude', '8+', '7-8', '6-7', '5-6', '5-'],
        ['NET LOSS (AFTER INSURANCE)', '', '', '', '', '']
        ]
	t2=Table(net_loss, style= [('VALIGN',(0,0),(-1,-1),'MIDDLE'),
								('SPAN',(0,-1),(-1,-1)),
								('FONTSIZE',(0,0),(-1,-1), 12),
								('GRID', (0,0), (-1,-1), 1, colors.black),
							    ('LEFTPADDING', (0, 0), (-1, -1), 5),
							    ('RIGHTPADDING', (0, 0), (-1, -1), 5),
							    ('TOPPADDING', (0, 0), (-1, -1), -6),
							    ('BOTTOMPADDING', (0, 0), (-1, -1), 18),
								('BACKGROUND',(0,-1),(-1,-1),colors.lightskyblue),
								('BACKGROUND',(0,-2),(-1,-2),colors.lightsteelblue),
                				('BACKGROUND',(0,0),(-1,0),colors.aqua),
								])

	final_results = [
					['Total insurance price [M€]', request.session["total_insurance_price"]],
					['Total BCP implementation cost [M€]', request.session["total_implementation_cost"]],
					['Total expected loss [M€]', request.session["total_expected_loss"]],
					]

	t3_B=Table(final_results, style= [('VALIGN',(0,0),(-1,-1),'MIDDLE'),
									('FONTSIZE',(0,0),(-1,-1), 12),
									('GRID', (0,0), (-1,-1), 1, colors.black),
								    ('LEFTPADDING', (0, 0), (-1, -1), 5),
								    ('RIGHTPADDING', (0, 0), (-1, -1), 5),
								    ('TOPPADDING', (0, 0), (-1, -1), -6),
								    ('BOTTOMPADDING', (0, 0), (-1, -1), 18),
									('BACKGROUND',(0,0),(0,-1),colors.lightskyblue),
									])

	total_results = [
					['TOTAL EXPECTED COST OF BC STRATEGY [M€]', request.session["total_expected_cost"]],
					]

	t3_C=Table(total_results, style= [('VALIGN',(0,0),(-1,-1),'MIDDLE'),
									('FONTSIZE',(0,0),(-1,-1), 12),
									('GRID', (0,0), (-1,-1), 1, colors.black),
								    ('LEFTPADDING', (0, 0), (-1, -1), 5),
								    ('RIGHTPADDING', (0, 0), (-1, -1), 5),
								    ('TOPPADDING', (0, 0), (-1, -1), -6),
								    ('BOTTOMPADDING', (0, 0), (-1, -1), 18),
									('BACKGROUND',(0,0),(0,-1),colors.lightskyblue),
                					('BACKGROUND',(1,0),(1,0),colors.aqua),
									])


	"""stock_level=  [
					['Finished products [M€]', request.session["scores_M8"][20], request.session["scores_M7"][20], request.session["scores_M6"][20], request.session["scores_M5"][20], request.session["scores_M4"][20] ],
			        ['External parts [M€]',    request.session["scores_M8"][19], request.session["scores_M7"][19], request.session["scores_M6"][19], request.session["scores_M5"][19], request.session["scores_M4"][19] ],
			        ['Internal parts [M€]',    request.session["scores_M8"][18], request.session["scores_M7"][18], request.session["scores_M6"][18], request.session["scores_M5"][18], request.session["scores_M4"][18] ],
			        ['Raw material [M€]',      request.session["scores_M8"][17], request.session["scores_M7"][17], request.session["scores_M6"][17], request.session["scores_M5"][17], request.session["scores_M4"][17] ],
			        ['Magnitude', '8+', '7-8', '6-7', '5-6', '5-'],
			        ['FINAL STOCK LEVEL', '', '', '', '', '']
			        ]
				t3=Table(stock_level, style= [('VALIGN',(0,0),(-1,-1),'MIDDLE'),
											('SPAN',(0,-1),(-1,-1)),
											('FONTSIZE',(0,0),(-1,-1), 12),
											('GRID', (0,0), (-1,-1), 1, colors.black),
										    ('LEFTPADDING', (0, 0), (-1, -1), 5),
										    ('RIGHTPADDING', (0, 0), (-1, -1), 5),
										    ('TOPPADDING', (0, 0), (-1, -1), -6),
										    ('BOTTOMPADDING', (0, 0), (-1, -1), 18),
											('BACKGROUND',(0,-1),(-1,-1),colors.lightskyblue),
											('BACKGROUND',(0,-2),(-1,-2),colors.lightsteelblue),
											])"""

	try:
		bia_data = np.array(request.session["impacts"]).reshape((10,10))
	except:
		bia_data = np.zeros((10,10))
	
	try:
		mtpd_data = np.array(request.session["MTPDs"])
	except:
		mtpd_data = np.zeros((4,1))

	try:
		rto_data = np.array(request.session["RTOs"])
	except:
		rto_data = np.zeros((4,1))

		
	bia_table = [
				['IT systems', 'Online sales',bia_data[9,0], bia_data[9,1], bia_data[9,2], bia_data[9,3], bia_data[9,4], bia_data[9,5], bia_data[9,6], bia_data[9,7], bia_data[9,8], bia_data[9,9], mtpd_data[3], rto_data[3]],
				['Order acq.', 'Online sales',bia_data[8,0], bia_data[8,1], bia_data[8,2], bia_data[8,3], bia_data[8,4], bia_data[8,5], bia_data[8,6], bia_data[8,7], bia_data[8,8], bia_data[8,9], mtpd_data[2], rto_data[2]],
			    ['Assembly', 'Contractual penal.',bia_data[7,0], bia_data[7,1], bia_data[7,2], bia_data[7,3], bia_data[7,4], bia_data[7,5], bia_data[7,6], bia_data[7,7], bia_data[7,8], bia_data[7,9], mtpd_data[1], rto_data[1]],
			    ['Assembly', 'Non-delivery sales',bia_data[6,0], bia_data[6,1], bia_data[6,2], bia_data[6,3], bia_data[6,4], bia_data[6,5], bia_data[6,6], bia_data[6,7], bia_data[6,8], bia_data[6,9], mtpd_data[1], rto_data[1]],
			    ['Assembly', 'Offline sales',bia_data[5,0], bia_data[5,1], bia_data[5,2], bia_data[5,3], bia_data[5,4], bia_data[5,5], bia_data[5,6], bia_data[5,7], bia_data[5,8], bia_data[5,9], mtpd_data[1], rto_data[1]],
			    ['Assembly', 'Contarctual sales',bia_data[4,0], bia_data[4,1], bia_data[4,2], bia_data[4,3], bia_data[4,4], bia_data[4,5], bia_data[4,6], bia_data[4,7], bia_data[4,8], bia_data[4,9], mtpd_data[1], rto_data[1]],
			    ['Manufacturing', 'Contractual penal.',bia_data[3,0], bia_data[3,1], bia_data[3,2], bia_data[3,3], bia_data[3,4], bia_data[3,5], bia_data[3,6], bia_data[3,7], bia_data[3,8], bia_data[3,9], mtpd_data[0], rto_data[0]],
			    ['Manufacturing', 'Non-delivery sales',bia_data[2,0], bia_data[2,1], bia_data[2,2], bia_data[2,3], bia_data[2,4], bia_data[2,5], bia_data[2,6], bia_data[2,7], bia_data[2,8], bia_data[2,9], mtpd_data[0], rto_data[0]],
			    ['Manufacturing', 'Offline sales',bia_data[1,0], bia_data[1,1], bia_data[1,2], bia_data[1,3], bia_data[1,4], bia_data[1,5], bia_data[1,6], bia_data[1,7], bia_data[1,8], bia_data[1,9], mtpd_data[0], rto_data[0]],
			    ['Manufacturing', 'Contarctual sales',bia_data[0,0], bia_data[0,1], bia_data[0,2], bia_data[0,3], bia_data[0,4], bia_data[0,5], bia_data[0,6], bia_data[0,7], bia_data[0,8], bia_data[0,9], mtpd_data[0], rto_data[0]],
			    ['CW. activities', 'days','1-3', '3-7', '7-14', '14-30', '30-45', '45-60', '60-90', '90-180', '180-360', '>360','MTPD', 'RTO'],
			    ['CW. activities', 'Impacts evaluation', 'MTPD', 'RTO'],
			    ['BUSINESS IMPACTS TABLE', '', '', '', '', '', '', '', '']
				]
	t4=Table(bia_table, style= [('VALIGN',(0,0),(-1,-1),'MIDDLE'),
								('SPAN',(0,-1),(-1,-1)),
								('SPAN',(1,-2),(11,-2)),
								('SPAN',(0,2),(0,5)),
								('SPAN',(0,6),(0,9)),
								('SPAN',(0,10),(0,11)),
								('SPAN',(12,10),(12,11)),
								('SPAN',(13,10),(13,11)),
								('SPAN',(12,6),(12,9)),
								('SPAN',(13,6),(13,9)),
								('SPAN',(12,2),(12,5)),
								('SPAN',(13,2),(13,5)),
								('FONTSIZE',(0,0),(-1,-1), 9),
								('GRID', (0,0), (-1,-1), 1, colors.black),
							    ('LEFTPADDING', (0, 0), (-1, -1), 3),
							    ('RIGHTPADDING', (0, 0), (-1, -1), 3),
							    ('TOPPADDING', (0, 0), (-1, -1), -6),
							    ('BOTTOMPADDING', (0, 0), (-1, -1), 10),
								('BACKGROUND',(0,-1),(-1,-1),colors.lightskyblue),
								('BACKGROUND',(0,-2),(-1,-2),colors.lightsteelblue),
								('BACKGROUND',(0,-3),(-1,-3),colors.lightsteelblue),
								])


	lines4.append("CHARTS")

	for line in lines1:
		textob1.textLine(line)
	for line in lines2:
		textob2.textLine(line)
	for line in lines3:
		textob3.textLine(line)
	for line in lines4:
		textob4.textLine(line)

	c.saveState()
	c.scale(1,-1)
	c.drawImage("autoparts/static/logo.png", 50, -210, width=169, height=130, mask="auto")
	c.drawImage("autoparts/static/pdf_style.png", -120, -100, width=790, height=200, mask="auto")
	c.drawImage("autoparts/static/pdf_style_2.png", w-130, -h-70, width=200, height=180, mask="auto")
	c.restoreState()
	c.drawText(textob1)
	c.drawText(textob2)
	c.showPage()

	c.drawText(textob3)
	c.saveState()
	t1.wrapOn(c, 500, 170)
	t1.drawOn(c, 50, 100)
	t2.wrapOn(c, 500, 170)
	t2.drawOn(c, 50, 290)
	#t3.wrapOn(c, 500, 170)
	#t3.drawOn(c, 50, 480)
	t3_B.wrapOn(c, 300, 100)
	t3_B.drawOn(c, 50, 480)
	t3_C.wrapOn(c, 300, 100)
	t3_C.drawOn(c, 50, 570)
	c.scale(1,-1)
	c.drawImage("autoparts/static/pdf_style_2.png", w-130, -h-70, width=200, height=180, mask="auto")
	c.restoreState()
	c.showPage()

	c.saveState()
	t4.wrapOn(c, 500, 270)
	t4.drawOn(c, 50, 100)
	c.scale(1,-1)
	c.drawImage("autoparts/static/pdf_style_2.png", w-130, -h-70, width=200, height=180, mask="auto")
	c.restoreState()
	c.showPage()

	c.drawText(textob4)
	c.saveState()
	c.scale(1,-1)
	c.drawImage("autoparts/static/pdf_style_2.png", w-130, -h-70, width=200, height=180, mask="auto")
	c.drawImage("autoparts/tmp_data/"+group+"/figure1.png", 40, -280, width=260, height=200, mask="auto")
	c.drawImage("autoparts/tmp_data/"+group+"/figure2.png", 300, -280, width=260, height=200, mask="auto")
	c.drawImage("autoparts/tmp_data/"+group+"/figure3.png", 40, -480, width=260, height=200, mask="auto")
	c.drawImage("autoparts/tmp_data/"+group+"/figure4.png", 300, -480, width=260, height=200, mask="auto")
	c.drawImage("autoparts/tmp_data/"+group+"/figure5.png", 40, -680, width=260, height=200, mask="auto")
	c.drawImage("autoparts/tmp_data/"+group+"/figure6.png", 300, -680, width=260, height=200, mask="auto")
	c.restoreState()
	c.showPage()

	c.save()
	#buf.seek(0)
	if not download:
		if not os.path.exists("autoparts/PDFs/"+group+"/"):
			os.mkdir("autoparts/PDFs/"+group+"/")
		request.session["pdf_server_saved"] = True
		file = open("autoparts/PDFs/"+group+"/"+group+"_"+request.session["timestamp2"]+".pdf", "wb")
		file.write(buf.getvalue())
		return

	else:

		buf.seek(0)
		return FileResponse(buf, as_attachment=True, filename=group+"_"+request.session["timestamp2"]+".pdf")




def clear_tmp_files(request):

	"""if os.path.exists("autoparts/tmp_data/output_M4.txt"):
			   		os.remove("autoparts/tmp_data/output_M4.txt") 
			   	if os.path.exists("autoparts/tmp_data/output_M5.txt"):
			   		os.remove("autoparts/tmp_data/output_M5.txt") 
			   	if os.path.exists("autoparts/tmp_data/output_M6.txt"):
			   		os.remove("autoparts/tmp_data/output_M6.txt") 
			   	if os.path.exists("autoparts/tmp_data/output_M7.txt"):
			   		os.remove("autoparts/tmp_data/output_M7.txt") 
			   	if os.path.exists("autoparts/tmp_data/output_M8.txt"):
			   		os.remove("autoparts/tmp_data/output_M8.txt")  
			   
			   	if os.path.exists("autoparts/tmp_data/output.mat"):
			   		os.remove("autoparts/tmp_data/output.mat")   
			   	if os.path.exists("autoparts/tmp_data/input.mat"):
			   		os.remove("autoparts/tmp_data/input.mat")     
			   	if os.path.exists("autoparts/tmp_data/matlab_vector.txt"):
			   		os.remove("autoparts/tmp_data/matlab_vector.txt")"""   

	group = str(request.user)
	if os.path.exists("autoparts/tmp_data/"+group+"/figure1.png"):
		os.remove("autoparts/tmp_data/"+group+"/figure1.png")     
	if os.path.exists("autoparts/tmp_data/"+group+"/figure2.png"):
		os.remove("autoparts/tmp_data/"+group+"/figure2.png")     
	if os.path.exists("autoparts/tmp_data/"+group+"/figure3.png"):
		os.remove("autoparts/tmp_data/"+group+"/figure3.png")     
	if os.path.exists("autoparts/tmp_data/"+group+"/figure4.png"):
		os.remove("autoparts/tmp_data/"+group+"/figure4.png")     
	if os.path.exists("autoparts/tmp_data/"+group+"/figure5.png"):
		os.remove("autoparts/tmp_data/"+group+"/figure5.png")     
	if os.path.exists("autoparts/tmp_data/"+group+"/figure6.png"):
		os.remove("autoparts/tmp_data/"+group+"/figure6.png")


def clear_session(request):
	request.session["simulation_done"] = False
	request.session["pdf_server_saved"] = False
	request.session["inputs_data"] = [5, 10, 10, 10, 10, 5, 10, 10, 10, 10]
	request.session["radio_state"] = [0, 0, 0, 0, 0]
	request.session["insurance"] = 0
	request.session["investment"] = 0
	request.session["impacts"] = np.zeros(100).tolist()
	request.session["MTPDs"] = [3,3,3,3]
	request.session["RTOs"] = [3,3,3,3]

