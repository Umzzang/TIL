from django.db import models
from django.conf import settings

# Create your models here.
User = settings.AUTH_USER_MODEL



class Movie(models.Model):
    title = models.CharField(max_length=30)
    overview = models.TextField()
    img = models.ImageField(upload_to='articles/movie')
    release_date = models.DateTimeField()
    created_at = models.DateTimeField(auto_now_add=True)
    updated_at = models.DateTimeField(auto_now=True)
    like_user = models.ManyToManyField(User, related_name='like_Movie')

class Actor(models.Model):
    name = models.CharField(max_length=10)
    img = models.ImageField(upload_to='articles/actor')
    movies = models.ManyToManyField(Movie, related_name='actors')
    like_user = models.ManyToManyField(User, related_name='like_Actor')


class Comment(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    like_user = models.ManyToManyField(User, related_name='like_comment')
    content = models.CharField(max_length=150)
    movie = models.ForeignKey(Movie, on_delete=models.CASCADE, related_name='comments')