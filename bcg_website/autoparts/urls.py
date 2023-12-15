from django.urls import path, include
from . import views


urlpatterns = [
    path('autoparts/', views.introduction, name="autoparts-introduction"), 
    path('autoparts/introduction/', views.introduction, name="autoparts-introduction"), 
    path('autoparts/description/', views.description, name="autoparts-description"),    
    path('autoparts/suppliers/', views.suppliers, name="autoparts-suppliers"),
    path('autoparts/resilience/', views.resilience, name="autoparts-resilience"),
    path('autoparts/bia/', views.bia, name="autoparts-bia"),
    path('autoparts/threat/', views.threat, name="autoparts-threat"),
    path('autoparts/vulnerability/', views.vulnerability, name="autoparts-vulnerability"),
    path('autoparts/insurance/', views.insurance, name="autoparts-insurance"),
    path('autoparts/solutions/', views.solutions, name="autoparts-solutions"),
    path('autoparts/strategy/', views.strategy, name="autoparts-strategy"),
    path('autoparts/loading/', views.loading, name="autoparts-loading"),
    path('autoparts/simulation/', views.simulation, name="autoparts-simulation"),
    path('autoparts/results/', views.results, name="autoparts-results"),
    path('autoparts/pdf/<int:download>', views.pdf, name="autoparts-pdf"),
    path('autoparts/bia-running/', views.bia_running, name="autoparts-bia-running"),
    path('autoparts/strategy-running/', views.strategy_running, name="autoparts-strategy-running"),
    path('autoparts/results-table/', views.results_table, name="autoparts-results-table"),
    path('autoparts/clear-table/', views.clear_table, name="autoparts-clear-table"),
   ]