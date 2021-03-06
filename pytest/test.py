# import requests
# res=requests.get('http://www.gutenberg.org/cache/epub/1112/pg1112.txt')
# res.raise_for_status()
# playFile= open('RomeAndJuliet.txt','wb')
# for chunk in res.iter_content(100000):
#     playFile.write(chunk)
# playFile.close()
# import xlwt
# import sqlite3
# workbook=xlwt.Workbook(encoding="utf-8")
# worksheet=workbook.add_sheet("sheet1")
# #worksheet.write(0,0,"hello")
# for i in range(1,10):
#   for j in range(1,i+1):
#     worksheet.write(i,j,"{} * {} = {}".format(j,i,i*j))
# workbook.save("student.xls")
# conn=sqlite3.connect("test.db")
# print("Opened databases successfully...")
# c=conn.cursor()
# sql='''
# create table tt13(
# 	id int unsigned not null primary key,
# 	name varchar(20) not null
# );
# '''
# c.execute(sql)
# conn.commit()
# conn.close()
from matplotlib import pyplot as plt
from wordcloud import WordCloud
from PIL import Image
import numpy as np
import sqlite3
import jieba


con=sqlite3.connect('movie250.db')
cur=con.cursor()
sql='select instroduction from movie250'
data=cur.execute(sql)
text=""
for item in data:
  text = text + item[0]
print(text)
cur.close()
con.close()

cut=jieba.cut(text)
string=' '.join(cut)
print(string)

img=Image.open(r'test.jpg')
img_array=np.array(img)
wc = WordCloud(
  background_color='white',
  mask=img_array,
  font_path="微软雅黑.TTF"
)
wc.generate_from_text(string)

