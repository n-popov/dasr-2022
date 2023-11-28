from django.urls import path

from . import views

urlpatterns = [
    path('all/', views.all),
    path('add/', views.add),
    path('remove/<int:idtf>/', views.remove),
    path('update/', views.update),
]
