#获取远程设备的IP地址
import socket
import sys
import argparse

def get_remote_machine_info():
  err_msg = ''
  remote_host ='www.runoob.com'
  try:
    print("IP address: %s"%socket.gethostbyname(remote_host))
  except (socket.error, err_msg):
    print("%s: %s"%(remote_host,err_msg))

#将IPV4地址转换为不同的格式
from binascii import hexlify
def convert_ip4_address():
  for ip_addr in ['127.0.0.1','192.168.1.130']:
    packed_ip_addr =socket.inet_aton(ip_addr)
    unpacked_in_addr=socket.inet_ntoa(packed_ip_addr)
    print("IP Address: %s => Packed: %s, Unpacked: %s"%(ip_addr,hexlify(packed_ip_addr),unpacked_in_addr))


def find_sevice_name():
  protocolname='tcp'
  for port in[25,80]:
    print("port:%s => service name: %s"%(port,socket.getservbyport(port,protocolname)))
  print("port:%s => service name: %s"%(53,socket.getservbyport(53,'udp')))

def convert_integer():
  data=1234
  print("original: %s => long host byte oder:%s, network byte order:%s"%(data,socket.ntohl(data),socket.htonl(data)))
  print("original: %s => short host byte oder:%s, network byte order:%s"%(data,socket.ntohs(data),socket.htons(data)))


def main():

  parser=argparse.ArgumentParser(description='Socket Error Examples')
  parser.add_argument('--host',action="store",dest="host",required=False)
  parser.add_argument('--port',action="store",dest="port",type=int,required=False)
  parser.add_argument('--file',action="store",dest="file",required=False)
  give_args=parser.parse_args()
  host=give_args.host
  port=give_args.port
  filename=give_args.file
  try:
    s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
  except socket.error:
    print("Error creating socket:")
    sys.exit(1)
  try:
    s.connect((host,port))
  except socket.error:
    print("connection error")
    sys.exit(1)
  except socket.gaierror:
    print("Address-related error connecting to server:")
    sys.exit(1)
  try:
    s.sendall("GET %s HTTP/1.0 \r\n\r\n"%filename)
  except socket.error:
    print("Error sending data:")
    sys.exit(1)
  while(1):
    try:
      buf=s.recv(2048)
    except socket.error:
      print("Error receiving data:")
      sys.exit(1)
    if(not len(buf)):
      break
    sys.stdout.write(buf)


def test_socket_modes():
  s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
  s.setblocking(1)
  s.settimeout(0.5)
  s.bind(("127.0.0.1",0))
  socket_address=s.getsockname()
  print("Trival Server launched on sockect:%s"%str(socket_address))
  while(1):
    s.listen()

SEND_BUF_SIZE=4096
RECV_BUF_SIZE=4096

def modify_buff_size():
  sock=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
  bufsize=int(1)
  bufsize=sock.getsockopt(socket.SOL_TCP,socket.TCP_NODELAY,1)
  print("Buffer size [Before]:",bufsize)
  sock.setsockopt(socket.SOL_TCP,socket.TCP_NODELAY,1)
  sock.setsockopt(socket.SOL_SOCKET,socket.SO_SNDBUF,SEND_BUF_SIZE)
  bufsize=sock.getsockopt(socket.SOL_SOCKET,socket.SO_RCVBUF,RECV_BUF_SIZE)
  print("Buffer size [After]:",bufsize)

def reuse_socket_addr():
  sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
  old_state=sock.getsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR)
  print("old:",old_state)
  sock.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
  new_state=sock.getsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR)
  print("new:",old_state)
  local_port=8282
  srv=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
  srv.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
  srv.bind(('',local_port))
  srv.listen(1)
  print("Listen port :",local_port)
  while(1):
    connection,addr=srv.accept()
import ntplib
from time import ctime
def print_time():
  ntp_client=ntplib.NTPClient()
  response=ntp_client.request('time.asia.apple.com')
  print(ctime(response.tx_time))
print_time()

import time
import struct
NTP_SERVER="0.uk.time.asia.apple.com"
TIME1970=2208988800

def sntp_client():
  client=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
  data="\x1b"+47*'0'
  client.sendto(data,(NTP_SERVER,123))
  data,address=client.recvfrom(1024)
  if(data):
    print(address)
  t=struct.unpack('!12I',data)[10]
  t-=TIME1970
  print(time.ctime(t))