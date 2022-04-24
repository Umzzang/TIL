from django.shortcuts import get_object_or_404, render, redirect
from django.contrib.auth import get_user_model, update_session_auth_hash
from django.contrib.auth import login as auth_login
from django.contrib.auth import logout as auth_logout
from django.contrib.auth.decorators import login_required
from django.views.decorators.http import require_POST, require_http_methods
from django.contrib.auth.forms import AuthenticationForm, PasswordChangeForm
from .forms import CustomUserCreationFrom, DeleteUser, CustomUserChangeForm



# Create your views here.
def signup(request):
    if request.method == 'POST':
        form = CustomUserCreationFrom(request.POST, request.FILES)
        if form.is_valid():
            user = form.save()
            auth_login(request, user)
            return redirect('accounts:profile', user.username)
    else:
        form = CustomUserCreationFrom()
    context = {
        'form' : form
    }
    return render(request, 'accounts/signup.html', context)



def login(request):
    if request.user.is_authenticated:
        return redirect('articles:index')
    if request.method == 'POST':
        form = AuthenticationForm(request, request.POST)
        if form.is_valid():
            auth_login(request, form.get_user())
            print(form.get_user())
            return redirect(request.GET.get('next')  or 'articles:index')
    else:
        form = AuthenticationForm()
    context = {
        'form' : form
    }
    return render(request, 'accounts/login.html', context)

@require_POST
def logout(request):
    if request.user.is_authenticated:
        auth_logout(request)
        return redirect('articles:index')
    return redirect('articles:index')




def delete(request):
    if request.method == "POST":
        form = DeleteUser(request, request.POST)
        if form.is_valid():
            if form.get_user() == request.user:
                form.get_user().delete()
                auth_logout(request)
                return redirect('articles:index')
        else:
            # 메세지 나오게 나중에 바꾸자
            return redirect('articles:index')
    else:
        form = DeleteUser()
    context = {
        'form' : form
    }
    return render(request, 'accounts/delete.html', context)



@login_required
def update(request):
    if request.method == 'POST':
        form = CustomUserChangeForm(request.POST, instance=request.user)
        if form.is_valid():
            user = form.save()
            return redirect('accounts:profile', user.username)
    else:
        form = CustomUserChangeForm(instance=request.user)
    context = {
        'form' : form
    }
    return render(request, 'accounts/update.html', context)




@login_required
def profile(request, username):
    user = get_object_or_404(get_user_model(), username=username)
    context = {
        'user' : user
    }
    return render(request, 'accounts/profile.html', context)


@login_required
def password_change(request):
    if request.method == 'POST':
        form = PasswordChangeForm(request.user, request.POST)
        if form.is_valid():
            user = form.save()
            update_session_auth_hash(request, user)
            return redirect('accounts:profile', user.username)
    else:
        form = PasswordChangeForm(request.user)
    context = {
        'form' : form
    }
    return render(request, 'accounts/password.html', context)

@require_POST
def follow(request, pk):
    user = get_object_or_404(get_user_model(), pk=pk)
    if request.user.is_authenticated:
        if user != request.user:
            if user.followers.filter(pk=request.user.pk).exist():
                user.followers.remove(request.user)
            else:
                user.followers.add(request.user)
        return redirect('accounts:profile', user.username )
    return redirect('accounts:login')