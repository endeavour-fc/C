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
#print(text)
cur.close()
con.close()

cut=jieba.cut(text)
string=' '.join(cut)
#print(string)

img=Image.open(r'test.jpg')
img_array=np.array(img)
wc = WordCloud(
  background_color='white',
  mask=img_array,
  font_path="msyh.ttc"
)
wc.generate_from_text(string)

flg=plt.figure(1)
plt.imshow(wc)
plt.axis('off')

#plt.show()
plt.savefig(r'static\img\word.jpg',dpi=500)