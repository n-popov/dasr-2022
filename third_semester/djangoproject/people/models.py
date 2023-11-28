from django.db import models

class Person(models.Model):
    name = models.CharField(max_length=30)
    group = models.CharField(max_length=30)
    age = models.IntegerField()
    fav_manufacturer = models.CharField(max_length=30)



