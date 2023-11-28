from django.shortcuts import render
import json
from .models import Person
from django.http import JsonResponse
from django.views.decorators.csrf import csrf_exempt

# Create your views here.

def all(request):
    people = list(Person.objects.all().values())

    return render(request, template_name='all.html', 
                  context={'people': people})

def remove(request, idtf):
    p = Person.objects.get(id=idtf)
    p.delete()

    return JsonResponse({})

def update(request):
    person = json.loads(request.body.decode())
    p = Person.objects.get(id=person['id'])
    p.name = person['name']
    p.group = person['group']
    p.age = person['age']
    p.fav_manufacturer = person['fav_manufacturer']
    p.save()

    return JsonResponse(person, status=200)
    

def add(request):
    if request.method == 'POST':
        person = json.loads(request.body.decode())
        p = Person(name=person['name'],
                   age=person['age'],
                   group=person['group'],
                   fav_manufacturer=person['fav_manufacturer'])
        p.save()
        return JsonResponse(person, status=201)
