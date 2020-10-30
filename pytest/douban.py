import bs4
import re#正则
import urllib.request,urllib.error
import xlwt
import sqlite3

def GetData(baseurl):
  datalist=[]
  for i in range(0,10):
    url=baseurl+str(i*25)
    html=askURL(url)
    
  return datalist
 
def SaveData(savedata,savepath):
  return

def main():
  baseurl="https://movie.douban.com/top250"
def askURL(url):
  header={
  "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/86.0.4240.75 Safari/537.36"
}
  request=urllib.request.Request(url,headers=header)
  html=""
  try:
    response=urllib.request.urlopen(request)
    html=response.read().decode("utf-8")
    print(html)
  except urllib.error.URLError as e:
    if(hasattr(e,"code")):
      print(e,"code")
    if(hasattr(e,"reason")):
      print(e.reason)
  return html
  
print(askURL("https://movie.douban.com/top250"))