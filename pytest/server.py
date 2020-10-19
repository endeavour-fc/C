import socket
import sys

def echo_server():
  sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
  sock.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
  host=socket.gethostname()
  sock.bind((host,8080))
  sock.listen(5)
  client,address=sock.accept()
  while(1):
    print("Waiting to recevie message from client")
    data=client.recv(2048)
    if(data):
      client.send(data)
  client.close()
  sock.close()

echo_server()
