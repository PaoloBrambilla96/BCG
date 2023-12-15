from django.shortcuts import render, redirect
import numpy as np


import electricity.db.electricity_db_management as db


# Create your views here.
[electricity_bia_running, electricity_strategy_running] = np.load("02_electricity_running.npy", allow_pickle=True)


def bia_running(request):
	global electricity_bia_running, electricity_strategy_running
	electricity_bia_running =  not electricity_bia_running
	np.save("02_electricity_running.npy", [electricity_bia_running, electricity_strategy_running])
	return redirect("common-control")


def strategy_running(request):
	global electricity_bia_running, electricity_strategy_running
	electricity_strategy_running =  not electricity_strategy_running
	np.save("02_electricity_running.npy", [electricity_bia_running, electricity_strategy_running])
	return redirect("common-control")


def introduction(request):
	return render(request,
				'electricity/00_introduction.html',
				{'electricity_bia_running': electricity_bia_running,
				'electricity_strategy_running': electricity_strategy_running})


def description(request):
	return render(request,
				'electricity/01_description.html',
				{'electricity_bia_running': electricity_bia_running,
				'electricity_strategy_running': electricity_strategy_running})


def suppliers(request):
	return render(request,
				'electricity/02_suppliers.html',
				{'electricity_bia_running': electricity_bia_running,
				'electricity_strategy_running': electricity_strategy_running})


def resilience(request):
	return render(request,
				'electricity/03_resilience.html',
				{'electricity_bia_running': electricity_bia_running,
				'electricity_strategy_running': electricity_strategy_running})


def bia(request):
	if "el-impacts" in request.session and "el-MTPDs" in request.session and "el-RTOs" in request.session:
		pass
	else:
		request.session["el-impacts"] = np.zeros(140).tolist()
		request.session["el-MTPDs"] = (np.ones(7)*10).tolist()
		request.session["el-RTOs"] = (np.ones(7)*10).tolist()

	if request.method == "POST":
		print("entered in POST METHOD")
		impacts=[]
		MTPDs=[]
		RTOs=[]
		for k in range(14):
			for i in range(10):
				impacts.append(int(request.POST["table_"+str(k)+"_"+str(i)]))
		for j in range(7):
			MTPDs.append(int(request.POST["MTPD_"+str(j)]))
			RTOs.append(int(request.POST["RTO_"+str(j)]))
		request.session["el-impacts"] = impacts
		request.session["el-MTPDs"] = MTPDs
		request.session["el-RTOs"] = RTOs

		return redirect("electricity-bia")

	else:
		selectnames=[]
		for m in range(14):
			for n in range(10):
				selectnames.append("table_"+str(m)+"_"+str(n))
		mtpdnames=[]
		for j in range(7):
			mtpdnames.append(str(j))
		impacts = request.session["el-impacts"]
		MTPDs = request.session["el-MTPDs"]
		RTOs = request.session["el-RTOs"]

		return render(request,
				'electricity/04_bia.html',
				{'cols': [0,1,2,3,4,5,6,7,8,9],
				'cols_MN': [10,20,30,40,60,80,120,160,200,0],
				'selectnames': zip(selectnames, impacts),
				'mtpdnames': zip(mtpdnames, MTPDs),
				'rtonames': zip(mtpdnames, RTOs),
				'electricity_bia_running': electricity_bia_running,
				'electricity_strategy_running': electricity_strategy_running})


def threat(request):
	return render(request,
				'electricity/05_threat.html',
				{'electricity_bia_running': electricity_bia_running,
				'electricity_strategy_running': electricity_strategy_running})



def vulnerability(request):
	return render(request,
				'electricity/06_vulnerability.html',
				{'electricity_bia_running': electricity_bia_running,
				'electricity_strategy_running': electricity_strategy_running})


def insurance(request):
	return render(request,
				'electricity/07_insurance.html',
				{'electricity_bia_running': electricity_bia_running,
				'electricity_strategy_running': electricity_strategy_running})


def solutions(request):
	return render(request,
				'electricity/08_solutions.html',
				{'electricity_bia_running': electricity_bia_running,
				'electricity_strategy_running': electricity_strategy_running})


def strategy(request):
	if 'solution_data' in request.session:
		pass
	else:		
		request.session["solution_data"] = [0, 0, 0, 10, 1, 0, 0, 0, 0]
	if 'insurance' in request.session:
		pass
	else:
		request.session["insurance"] = 0
	if 'investment' in request.session:
		pass
	else:
		request.session["investment"] = 0

	if request.method == "POST":
		v0 = int(request.POST["solution1"])
		v1 = int(request.POST["solution2"])
		v2 = int(request.POST["solution3"])
		v3 = int(request.POST["solution4"])
		v4 = int(request.POST["solution5"])
		v5 = int(request.POST["solution6_1"])
		v6 = int(request.POST["solution6_2"])
		v7 = int(request.POST["solution7"])
		v8 = int(request.POST["solution8"])

		request.session["solution_data"] = [v0, v1, v2, v3, v4, v5, v6, v7, v8]
		request.session["insurance"] = int(request.POST["insurance"])

		print(request.session["solution_data"], request.session["insurance"], request.POST["investment"])
		return redirect("electricity-strategy")

	else:
		return render(request,
			"electricity/09_strategy.html",
			{'electricity_bia_running': electricity_bia_running,
			'electricity_strategy_running': electricity_strategy_running})











def results_table(request):
	data = db.show_table()
	return render(request,
				"electricity/electricity_table.html",
				{
				'data' : data,
				})


def clear_table(request):
	db.create_sqlite3_DB()
	return redirect("common-control")