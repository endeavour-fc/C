# import requests
# res=requests.get('http://www.gutenberg.org/cache/epub/1112/pg1112.txt')
# res.raise_for_status()
# playFile= open('RomeAndJuliet.txt','wb')
# for chunk in res.iter_content(100000):
#     playFile.write(chunk)
# playFile.close()
import xlwt
import sqlite3
# workbook=xlwt.Workbook(encoding="utf-8")
# worksheet=workbook.add_sheet("sheet1")
# #worksheet.write(0,0,"hello")
# for i in range(1,10):
#   for j in range(1,i+1):
#     worksheet.write(i,j,"{} * {} = {}".format(j,i,i*j))
# workbook.save("student.xls")
conn=sqlite3.connect("test.db")
print("Opened databases successfully...")
c=conn.cursor()
sql='''
create table tt13(
	id int unsigned not null primary key,
	name varchar(20) not null
);
'''
c.execute(sql)
conn.commit()
conn.close()
