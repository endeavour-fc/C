import os
import socket
import threading
import SocketServer
import codecs
def client(ip,port,message):
  sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
  sock.connect((ip,port))
  try:
    sock.sendall(message.encode("utf-8"))
    response=sock.recv(1024)
    print("Client received:%s"%response.decode("utf-8"))
  finally:
    sock.close()

class ThreadedTCPRequestHandler(SocketServer.BaseRequestHandler):
  def handle(self):
    data=self.request.recv(1024)
    current_thread=threading.current_thread()
    response="%s: %s"%(current_thread,data)
    self.request.sendall(response)

class ThreadedTCPServer(SocketServer.ThreadingMixIn,SocketServer.TCPServer):
  pass

if __name__=='__main__':
  server=ThreadedTCPServer((socket.gethostname(),8080),ThreadedTCPRequestHandler)
  ip,port=server.server_address
  server_thread=threading.Thread(target=server.serve_forever)
  server_thread.daemon=True
  server_thread.start()
  print("Server loop running on thread: ",server_thread.name)
  client(ip,port,"Hello from client 1")
  client(ip,port,"Hello from client 2")
  client(ip,port,"Hello from client 3")
  server.shutdown()