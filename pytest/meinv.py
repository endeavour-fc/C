import requests
import re
import time
import os


count=0

headers={
  'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/86.0.4240.75 Safari/537.36'
}

def saveData(url):
  html=requests.get(url,headers=headers).text
  #print(html.text)
  dirname='meinv'
  if not os.path.exists(dirname):
    os.mkdir(dirname)
  urls=[]
  urls = re.findall(r'<a href="(.*?)" alt=".*?" title=".*?">', html)
  #print(urls)
  for url in urls:
    #print("保存第",count,"张照片")
    #count+=1
    time.sleep(1) 
    filename=url.split('/')[-1]
    response=requests.get("https:"+url,headers=headers)

    with open(dirname+'/'+filename,'wb' ) as f:
      f.write(response.content)


'''
<a class=media-content href=14791.html title="一个吊床能玩一天" style='background-image:url("data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7")' data-bg=" url('//static.vmgirls.com/image/2020/10/2020101818160766.jpeg')" data-nclazyload=true>
<span class=overlay></span>
</a>
'''
'''
'''
def GetUrl(base):
  html=requests.get(base,headers=headers).text
  #print(html)
  urls = re.findall(r'<a class=media-content href=(.*?) title=".*?" style=.*? data-bg=".*?" data-nclazyload=true>', html)
  #urls.append(re.findall('<a class=media-content href=(.*?) title=".*?" style=.*? data-bg=".*?" data-nclazyload=true>', html))
  urls=set(urls)
  print(urls)
  num=0
  for url in urls:
    print("第",num,"张网页")
    num+=1
    #saveData(base+url)

if __name__ == '__main__':
  GetUrl("https://www.vmgirls.com/")
  print("end")

