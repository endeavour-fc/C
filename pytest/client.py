import socket
import sys
import codecs
import hashlib

def echo_client():
  s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
  host=socket.gethostname()
  port=8080
  s.connect((host,port))
  while(1):
    data=input("Client:")
    s.sendall(data.encode('utf-8'))
    rdata=s.recv(2048)
    print("Server:",rdata.decode("utf-8"))
  s.close()
echo_client()