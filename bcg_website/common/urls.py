from django.urls import path, include
from . import views


urlpatterns = [
    path('', views.home, name='common-home'),
    path('common/', views.home, name='common-home'),
    path('common/home/', views.home, name='common-home'),
    path('common/control/', views.control, name="common-control"),
    path('common/logout/', views.common_logout, name="logout"),
    path('common/login/', views.common_login, name="login"),
   ]