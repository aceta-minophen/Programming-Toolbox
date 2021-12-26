
'''
import requests

url = 'http://192.168.29.243'
query = {'NodeMCU': 'hello'}
res = requests.post(url, data=query)
print(res.text)
'''
import socket

clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

clientSocket.connect(("192.168.29.243", 80))

data = "Hello Server NodeMCU!"
clientSocket.send(data.encode())

dataFromServer = clientSocket.recv(1024)

print(dataFromServer.decode())