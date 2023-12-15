from django.shortcuts import render, redirect
from django.contrib.auth import authenticate, login, logout
import numpy as np
import time
import autoparts.views as apv
# Create your views here.


def home(request):
	return render(request,
		'common/common_home.html',
		{})



def control(request):
	[bia_running_v, strategy_running_v] = np.load("01_autoparts_running.npy", allow_pickle=True)
	[electricity_bia_running, electricity_strategy_running] = np.load("02_electricity_running.npy", allow_pickle=True)
	[logistics_bia_running, logistics_strategy_running] = np.load("03_logistics_running.npy", allow_pickle=True)
	return render(request,
				"common/common_control.html",
				{'autoparts_bia_running': bia_running_v,
				'autoparts_strategy_running': strategy_running_v,
				'electricity_bia_running': electricity_bia_running,
				'electricity_strategy_running': electricity_strategy_running,
				'logistics_bia_running': logistics_bia_running,
				'logistics_strategy_running': logistics_strategy_running})



def common_logout(request):
	apv.clear_tmp_files(request)
	logout(request)
	return redirect("login")



def common_login(request):
	if request.method == "POST":
		username = request.POST["username"]
		password = request.POST["password"]
		user = authenticate(request, username=username, password=password)
		if user is not None:
			login(request, user)
			return redirect("autoparts-introduction")
		else:
			return redirect("login")


	else:
		if request.user.is_authenticated:
			return redirect("autoparts-introduction")
		else:
			return render(request,
			'common/login.html',
			{})