import os
import threading
import SocketServer
import socket
import codecs

ECHO_MSG='Hello echo server!'

class ForkingClient:
  def __init__(self,ip,port):
    self.sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    self.sock.connect((ip,port))
  def run(self):
    current_process_id=os.getpid()
    print("PID:",current_process_id,"Sending echo message to the server:",ECHO_MSG)
    sent_data_length=self.sock.send(ECHO_MSG.encode("utf-8"))
    print("Sent:",sent_data_length,"characters, so far...")
    response=self.sock.recv(1024)
    print("PID",current_process_id,"received:",response.decode("utf-8"))
  def shutdown(self):
    self.sock.close()

class ForkingServerRequestHandler(SocketServer.BaseRequestHandler):
  def handle(self):
    data=self.request.recv(1024)
    current_process_id=os.getpid()
    response="%s:%s"%(current_process_id,data)
    print("Server sending response: ",response)
    self.request.send(response)
    return

class ForkingServer(SocketServer.ForkingMixIn,SocketServer.TCPServer):
  pass

def main1():
  server=ForkingServer((socket.gethostname(),8080),ForkingServerRequestHandler)
  ip,port=server.server_address
  server_thread=threading.Thread(target=server.serve_forever)
  server_thread.setDaemon(True)
  server_thread.start()
  print("Server loop running PID: ",os.getpid())
  client1=ForkingClient(ip,port)
  client1.run()
  client2=ForkingClient(ip,port)
  client2.run()

  server.shutdown()
  client1.shutdown()
  client2.shutdown()
  server.socket.close()

if __name__=='__main__':
  main1()
    