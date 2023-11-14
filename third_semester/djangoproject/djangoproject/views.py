import requests

from django.shortcuts import render
from django.http import HttpRequest, HttpResponse

def hello(request: HttpRequest) -> HttpResponse:
    hello_string = 'HELLO, DASR'
    hello_bytes = hello_string.encode()
    return HttpResponse(hello_bytes)

def btc_rub(request):
    external_api_response = requests.get('https://api.binance.com/api/v3/ticker/price?symbol=BTCRUB')
    response_dict = external_api_response.json()

    return render(request, template_name='price.html',
                  context={'pair': response_dict['symbol'],
                           'price': response_dict['price']})

