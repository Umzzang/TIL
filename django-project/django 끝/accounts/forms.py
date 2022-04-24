from django.contrib.auth import get_user_model
from django.contrib.auth.forms import UserChangeForm, UserCreationForm, AuthenticationForm



class CustomUserCreationFrom(UserCreationForm):
    class Meta:
        model = get_user_model()
        fields = ('username', 'first_name', 'last_name', 'img')


class CustomUserChangeForm(UserChangeForm):
    class Meta:
        model = model = get_user_model()
        fields = ('username', 'first_name', 'last_name', 'img')


class DeleteUser(AuthenticationForm):
    exclude = ('username')