#! Python3
# client

import socket

sock = socket.socket()
sock.connect(('localhost', 9090))
text = input('Что хотите отправить серверу: ')
sock.send(text.encode('utf-8'))

data = sock.recv(1024)
sock.close()

print(data.decode('utf-8'))
