from django.urls import path, include
from . import views


urlpatterns = [
    path('electricity/', views.introduction, name="electricity-introduction"),
    path('electricity/introduction/', views.introduction, name="electricity-introduction"),
    path('electricity/description/', views.description, name="electricity-description"),
    path('electricity/suppliers/', views.suppliers, name="electricity-suppliers"),
    path('electricity/resilience/', views.resilience, name="electricity-resilience"),
    path('electricity/bia/', views.bia, name="electricity-bia"),
    path('electricity/threat/', views.threat, name="electricity-threat"),
    path('electricity/vulnerability/', views.vulnerability, name="electricity-vulnerability"),
    path('electricity/insurance/', views.insurance, name="electricity-insurance"),
    path('electricity/solutions/', views.solutions, name="electricity-solutions"),
    path('electricity/strategy/', views.strategy, name="electricity-strategy"),
    path('electricity/bia-running/', views.bia_running, name="electricity-bia-running"),
    path('electricity/strategy-running/', views.strategy_running, name="electricity-strategy-running"),
    path('electricity/results-table/', views.results_table, name="electricity-results-table"),
    path('electricity/clear-table/', views.clear_table, name="electricity-clear-table"),
   ]