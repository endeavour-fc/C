import bs4
import re#正则
import urllib.request,urllib.error
import xlwt
import sqlite3
#影片链接
findLink=re.compile(r'<a href="(.*?)">')
#影片图片链接
findImg=re.compile(r'<img.*src="(.*?)"',re.S)
#片名
findTitle=re.compile(r'<span class="title">(.*)</span>')
#影片评分
findRating=re.compile(r'<span class="rating_num" property="v:average">(.*)</span>')
#评价人数
findJudge=re.compile(r'<span>(\d*)人评价</span>')
#概况
findInq=re.compile(r'<span class="inq">(.*)</span>')
#相关内容
findBd=re.compile(r'<p class="">(.*?)</p>',re.S)

def GetData(baseurl):
  datalist=[]
  for i in range(0,10):
    url=baseurl+str(i*25)
    html=askURL(url)
    soup=bs4.BeautifulSoup(html,"html.parser")
    for item in soup.find_all('div',class_="item"):
      #print(item)
      data=[]#保存一部电影的全部信息
      item=str(item)
      link=re.findall(findLink,item)[0]
      data.append(link)
      imgSrc=re.findall(findImg,item)[0]
      data.append(imgSrc)
      titles=re.findall(findTitle,item)
      if(len(titles)==2):
        ctitle=titles[0]
        data.append(ctitle)#添加中文名
        otitle=titles[1].replace("/","")
        data.append(otitle)#添加外国名
      else:
        data.append(titles[0])
        data.append(" ")#外文名留空
      rating=re.findall(findRating,item)[0]
      data.append(rating)
      judgeNum=re.findall(findJudge,item)[0]
      data.append(judgeNum)
      inq=re.findall(findInq,item)
      if(len(inq)!=0):
        inq=inq[0].replace("。","")
        data.append(inq)
      else:
        data.append(" ")

      bd=re.findall(findBd,item)[0]
      bd=re.sub('<br(\s+)?/>(\s?)'," ",bd)
      bd=re.sub('/',' ',bd)
      data.append(bd.strip())

      datalist.append(data)

  #print(datalist)
  return datalist
 
def SaveData(datalist,savepath):
  print("saving...  ")
  book=xlwt.Workbook(encoding="utf-8",style_compression=8)
  sheet=book.add_sheet("豆瓣电影TOP250",cell_overwrite_ok=True)
  col=("电影详情链接","图片链接","影片中文名","影片外国名","评分","评分人数","概况","相关信息")
  for i in range(0,8):
    sheet.write(0,i,col[i])
  for i in range(0,250):
    print("第%d条"%(i+1))
    data=datalist[i]
    for j in range(0,8):
      sheet.write(i+1,j,data[j])

  book.save(savepath)
  return

def init_db(dbpath):
  sql='''
  create table movie250(
    id integer primary key autoincrement,
    info_link text,
    pic_link text,
    cname varchar,
    ename varchar,
    score numeric,
    rated numeric,
    instroduction text,
    info text
  )
  '''
  conn=sqlite3.connect(dbpath)
  cursor=conn.cursor()
  cursor.execute(sql)
  conn.commit()
  conn.close()

def saveDataDB(datalist,dbpath):
  init_db(dbpath)
  conn=sqlite3.connect(dbpath)
  cur=conn.cursor()

  for data in datalist:
    for index in range(len(data)):
      if(index==5 or index==4):
        continue
      data[index]='"'+data[index]+'"'
    sql='''
    insert into movie250(
      info_link,pic_link,cname,ename,score,rated,instroduction,info
    )
    values(%s)
    '''%",".join(data)
    cur.execute(sql)
    conn.commit()
  cur.close()
  conn.close()

  return

def main():
  baseurl="https://movie.douban.com/top250?start="
  savepath="豆瓣电影Top250.xls"
  datalist=GetData(baseurl)
  print("爬取完毕")
  SaveData(datalist,savepath)
  print("存储完毕")
  dbpath="movie250.db"
  saveDataDB(datalist,dbpath)
  

def askURL(url):
  header={
  "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/86.0.4240.75 Safari/537.36"
}
  request=urllib.request.Request(url,headers=header)
  html=""
  try:
    response=urllib.request.urlopen(request)
    html=response.read().decode("utf-8")
    #print(html)
  except urllib.error.URLError as e:
    if(hasattr(e,"code")):
      print(e,"code")
    if(hasattr(e,"reason")):
      print(e.reason)
  return html


# #print(askURL("https://movie.douban.com/top250"))
# pat=re.compile("AA")
# # print(pat.search("AACBAADDAAA"))
# # m = re.search("asd","Aasd")
# m=re.findall("a","Abdsakjcaa")
# print(m)
if __name__ == "__main__":
  #init_db("movietest.db")
  main()