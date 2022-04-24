from . import views
from django.urls import path

app_name = "accounts"
urlpatterns = [
    path('signup/', views.signup, name='signup'),
    path('login/', views.login, name='login'),
    path('logout/', views.logout, name='logout'),
    path('delete/', views.delete, name='delete'),
    path('update/', views.update, name='update'),
    path('password_change/', views.password_change, name='password_change'),
    path('profile/<username>/', views.profile, name='profile'),
    path('follow/<int:pk>', views.follow, name="follow"),
]
