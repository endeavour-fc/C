from flask import Flask,render_template,request
import jinja2
import datetime
import sqlite3

app = Flask(__name__)

@app.route('/')

def index():
  return render_template("index.html")

@app.route('/index')

def home():
  return render_template("index.html")


@app.route('/movie')

def movie():
  datalist=[]
  con=sqlite3.connect("movie250.db")
  cur=con.cursor()
  sql="select * from movie250"
  data=cur.execute(sql)
  for item in data:
    datalist.append(item)

  cur.close()
  con.close()

  return render_template("movie.html",movies=datalist)

@app.route('/sorce')

def sorce():
  score=[]
  num=[]
  con=sqlite3.connect("movie250.db")
  cur=con.cursor()
  sql="select score,count(score) from movie250 group by score"
  data=cur.execute(sql)
  for item in data:
    score.append(item[0])
    num.append(item[1])

  cur.close()
  con.close()

  return render_template("video-page.html",score=score,num=num)


@app.route('/contact')

def contact():
  return render_template("contact.html")

@app.route('/test')

def test():
  return render_template("echart.html")

if __name__ == '__main__':
  app.run(debug=True)