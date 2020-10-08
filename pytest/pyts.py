
#test1
#print("hello,world\n");

#数字求和
#num1=input('输入一个浮点数')
#num2=input('输入一个浮点数')
#sum=float(num1)+float(num2)
#print('num1 + num2 = ',sum)

#平方根
'''
num=float(input('输入一个浮点数：'));
num_sqrt=num ** 0.5
print(' %0.3f的平方根为 %0.3f'%(num,num_sqrt))
'''
'''
import cmath

num = int(input('输入一个数字'))
num_sqrt = cmath.sqrt(num)
print('{0} 的平方根为 {1:0.3f}+{2:0.3f}j'.format(num ,num_sqrt.real,num_sqrt.imag))
'''

#二次方程
'''
import cmath

a=float(input('输入 a: '))
b=float(input('输入 b: '))
c=float(input('输入 c: '))
d=(b**2) - (4*a*c)
sol1=(-b-cmath.sqrt(d))/(2*a);
sol2=(-b+cmath.sqrt(d))/(2*a);
print('结果为{0}和{1}'.format(sol1,sol2))
'''

#计算三角形的面积
'''
a=float(input('输入三角形第一边长：'))
b=float(input('输入三角形第二边长：'))
c=float(input('输入三角形第三边长：'))
s=(a+b+c)/2
area = (s*(s-a)*(s-b)*(s-c))** 0.5
print('三角形面积为 %0.2f'%area)
'''
# 计算圆的面积
'''
def findArea(r):
  PI = 3.142
  return PI*(r*r)
print('圆的面积%.6f\n' % findArea(5))
'''
#随机数生成
'''
import random

print(random.randint(0,9))
'''
#摄氏温度转华氏温度
'''
celsius = float(input('输入摄氏温度: '))
 
# 计算华氏温度
fahrenheit = (celsius * 1.8) + 32
print('%0.1f 摄氏温度转为华氏温度为 %0.1f ' %(celsius,fahrenheit))
'''
#交换变量
'''
x=input('输入x值：')
y=input('输入y值：')
temp=x;
x=y;
y=temp;
print('交换后 x 的值为: {}'.format(x))
print('交换后 y 的值为: {}'.format(y))
'''
#if 语句
'''
num = float(input('输入一个数字：'))
if num>0:
  print('正数')
elif num == 0:
  print('0')
else:
  print('负数')
'''
'''
num = float(input('输入一个数字：'))
if num>=0:
  if num==0:
    print('0')
  else:
    print('正数')
else:
  print('负数')
'''
#判断字符串是否为数字
'''
def is_number(s):
    try:
        float(s)
        return True
    except ValueError:
        pass
 
    try:
        import unicodedata
        unicodedata.numeric(s)
        return True
    except (TypeError, ValueError):
        pass
 
    return False
 
# 测试字符串和数字
print(is_number('foo'))   # False
print(is_number('1'))     # True
print(is_number('1.3'))   # True
print(is_number('-1.37')) # True
print(is_number('1e3'))   # True
 
# 测试 Unicode
# 阿拉伯语 5
print(is_number('٥'))  # True
# 泰语 2
print(is_number('๒'))  # True
# 中文数字
print(is_number('四')) # True
# 版权号
print(is_number('©'))  # False
'''
#判断奇数偶数
'''
num=int(input('输入一个整型'))
if(num%2):
  print('奇数')
else:
  print('偶数')
'''
#判断闰年
'''
num=int(input('输入一个年份'))
if(num%4==0):
  if(num%100==0):
    if(num%400==0):
      print('闰年')
    else:
      print('不是闰年')
  else:
    print('闰年')
else:
  print('不是闰年')
'''
#获取最大值函数
'''
# 最简单的
print(max(1, 2))
print(max('a', 'b'))
 
# 也可以对列表和元组使用
print(max([1,2]))
print(max((1,2)))
 
# 更多实例
print("80, 100, 1000 最大值为: ", max(80, 100, 1000))
print("-20, 100, 400最大值为: ", max(-20, 100, 400))
print("-80, -20, -10最大值为: ", max(-80, -20, -10))
print("0, 100, -400最大值为:", max(0, 100, -400))
'''
#质数判断
'''
import cmath
num=int(input('输入一个整型'))

if(num>3):
  for i in range(2,int(num**0.5)+1):
    if(num%i==0):
      print('不是质数')
      break
  else:
    print('是质数')
else:
  print('是质数')
'''
#输出指定范围内的素数
'''
lower=int(input('输入区间的最小值'))
upper=int(input('输入区间的最大值'))

for i in range(lower,upper):
  if(i>1):
    for j in range(2,int(i**0.5)+1):
      if(i%j==0):
        break
    else:
      print(i)
'''

#阶乘实例
'''
num=int(input('输入阶乘数'))
sum=1
if(num<0):
  print('err')
elif(num==0):
  print(1)
else:
  for i in range(1,num+1):
    sum*=i
  print(sum)
'''

#九九乘法表
'''
for i in range(1,10):
  for j in range(1,i+1):
    print("{} * {} = {}\t".format(j,i,i*j),end='')
  print()
'''

#斐波那契数列
'''
def fb(count):
  if(count<0):
    return -1
  n1=0
  n2=1
  for i in range(0,count):
    print(n1,end=' ')
    n1,n2=n2,n1
    n2+=n1
  print()

num=int(input("请输入一个正整数"))
fb(num)
'''
#十进制转二进制、八进制、十六进制
'''
dec=int(input('输入数字'))

print("十进制数为：",dec)
print("转换为二进制数为：",bin(dec))
print("转换为八进制数为：",oct(dec))
print("转换为十六进制数为：",hex(dec))
'''

#ASCII码与字符相互转换
'''
c=input('输入一个字符：')
a=int(input('输入一个ASCII码'))

print(c+'的ASCII码为',ord(c))
print(a,'对应的字符为',chr(a))
'''
#最大公约数算法
'''
def hcf(x,y):
  if(x>y):
    smaller=y
  else:
    smaller=x
  for i in range(2,smaller+1):
    if((x%i==0) and (y%i==0)):
      hcf=i
  return hcf

num1=int(input('输入第一个数'))
num2=int(input('输入第二个数'))
print(num1,'和',num2,'的最大公约数为',hcf(num1,num2))
'''

#最小公倍数算法
'''
def lcm(x,y):
  if(x>y):
    greater=x
  else:
    greater=y
  while(1):
    if((greater%x==0)and(greater%y==0)):
      return greater
    greater+=1

num1 = int(input("输入第一个数字: "))
num2 = int(input("输入第二个数字: "))
 
print( num1,"和", num2,"的最小公倍数为", lcm(num1, num2))
'''
#简单计算器实现
'''
def add(x,y):
  return x+y

def subtract(x,y):
  return x-y

def multiply(x,y):
  return x*y

def divide(x,y):
  return x/y

print('选择运算')
print('1、相加')
print('2、相减')
print('3、相乘')
print('4、相除')

choice=input('输入你的选择')
num1 = int(input("输入第一个数字: "))
num2 = int(input("输入第二个数字: "))
 
if choice == '1':
   print(num1,"+",num2,"=", add(num1,num2))
 
elif choice == '2':
   print(num1,"-",num2,"=", subtract(num1,num2))
 
elif choice == '3':
   print(num1,"*",num2,"=", multiply(num1,num2))
 
elif choice == '4':
  if(num2):
   print(num1,"/",num2,"=", divide(num1,num2))
  else:
    print('除零错误')
else:
   print("非法输入")
'''

#生成日历
'''
import calendar

yy=int(input('输入年份：'))
mm=int(input('输入月份：'))

print(calendar.month(yy,mm))
'''
#快速排序
'''
def partition(arr,low,high): 
  i=low-1
  pos=arr[high]
  for j in range(low,high):
    if(arr[j]<=pos):
      i+=1
      arr[i],arr[j]=arr[j],arr[i]
  arr[high],arr[i+1]=arr[i+1],arr[high]
  return i+1

def QuickSort(arr,low,high):
  if(low<high):
    pos=partition(arr,low,high)
    QuickSort(arr,low,pos-1)
    QuickSort(arr,pos+1,high)

def quickSort(arr,low,high):
  i=low
  j=high

  if(i<j):
    temp=arr[low]
    while(i<j):
      while((i<j) and (arr[j]>=temp)):
        j-=1
      if(i<j):
        arr[i]=arr[j]
        i+=1
      while((i<j) and (arr[i]<=temp)):
        i+=1
      if(i<j):
        arr[j]=arr[i]
        j-=1  

    arr[i]=temp
    quickSort(arr,low,i-1)
    quickSort(arr,i+1,high)


arr = [10, 7, 8, 9, 1, 5] 
n = len(arr) 
quickSort(arr,0,n-1) 
print ("排序后的数组:") 
for i in range(n): 
  print ("%d " %arr[i],end='')
'''

#文件 IO
'''
with open("test.txt","wt") as out_file:
  out_file.write("Hello,World!\nPython")

with open("test.txt","rt") as in_file:
  text=in_file.read()

print(text)
'''
'''
#字符串判断
print("测试实例一")
str = "runoob.com"
print(str.isalnum()) # 判断所有字符都是数字或者字母
print(str.isalpha()) # 判断所有字符都是字母
print(str.isdigit()) # 判断所有字符都是数字
print(str.islower()) # 判断所有字符都是小写
print(str.isupper()) # 判断所有字符都是大写
print(str.istitle()) # 判断所有单词都是首字母大写，像标题
print(str.isspace()) # 判断所有字符都是空白字符、\t、\n、\r

print("------------------------")

# 测试实例二
print("测试实例二")
str = "runoob"
print(str.isalnum())
print(str.isalpha())
print(str.isdigit())
print(str.islower())
print(str.isupper())
print(str.istitle())
print(str.isspace())
'''
'''
#字符串大小写转换
str = "www.runoob.com"
print(str.upper())          # 把所有字符中的小写字母转换成大写字母
print(str.lower())          # 把所有字符中的大写字母转换成小写字母
print(str.capitalize())     # 把第一个字母转化为大写字母，其余小写
print(str.title())          # 把每个单词的第一个字母转化为大写，其余小写
'''
'''
#计算每个月天数
import calendar

monthRange=calendar.monthrange(2016,9)
print(monthRange)
'''
'''
#获取昨天日期
import datetime

def getYesterday():
  today=datetime.date.today()
  oneday=datetime.timedelta(days=1)
  yesterday=today-oneday
  return yesterday

print(getYesterday())
'''

#约瑟夫生者死者小游戏
'''
def ysfdg(sum,value,n):
  if(n==1):
    return (sum+value-1)%sum
  else:
    return (ysfdg(sum-1,value,n-1)+value)%sum

print(ysfdg(10,3,10))
'''
#五人分鱼
'''
def main():
  fish=1
  while True:
      total, enough=fish,True
      for _ in range(5):
          if( (total-1) % 5 == 0):
              total=((total-1)//5)*4
          else:
              enough=False
              break
      if(enough):
          print("共有",fish,"条鱼")
          break
      fish+=1

if __name__ == '__main__':
    main()
'''
'''
import time
print('按下回车开始计时，按下 Ctrl + C 停止计时。')
while(True):
  input("")
  starttime=time.time()
  print("start")
  try:
    while(1):
      print('计时: ', round(time.time() - starttime, 0), '秒', end="\r")
      time.sleep(1)
  except KeyboardInterrupt:
    print("end")
    endtime=time.time()
    print('总共的时间为:', round(endtime - starttime, 2),'secs')
    break
'''
'''
#计算 n 个自然数的立方和
def sumofseries(n):
  sum=0
  for i in range(1,n+1):
    sum+=(i*i*i)
  return sum

n=5
print(sumofseries(n)) 
'''
'''
#计算数组元素之和
def _sum(arr,n):
  return (sum(arr))

#arr=[]
arr=[12,3,4,15]
n=len(arr)
ans=_sum(arr,n)
print ('数组元素之和为',ans)
'''
'''
#数组翻转指定个数的元素
def ReverseArray(arr,start,end):
  while(start<end):
    arr[start],arr[end]=arr[end],arr[start]
    start+=1
    end-=1

def leftRotate(arr,d):
  n=len(arr)
  d%=n
  ReverseArray(arr,0,d-1)
  ReverseArray(arr,d,n-1)
  ReverseArray(arr,0,n-1)

def PrintArr(arr):
  for i in range(0,len(arr)):
    print(arr[i],end=' ')

arr=[1,2,3,4,5,6,7]
num=int(input('输入一个数：'))

leftRotate(arr,num)
PrintArr(arr)
'''
'''
#将列表中的头尾两个元素对调
def SwapList(newList):
  size=len(newList)
  newList[0],newList[size-1]=newList[size-1],newList[0]
  return newList

newList = [1,2,3]
print(SwapList(newList))
'''
'''
#将列表中的指定位置的两个元素对调
def swapPositions(list,pos1,pos2):
  list[pos1],list[pos2]=list[pos2],list[pos1]
  return list

def swapPositions2(list,pos1,pos2):
  first_ele=list.pop(pos1)
  second_ele=list.pop(pos2-1)
  list.insert(pos1,first_ele)
  list.insert(pos2,second_ele)
  return list

list=[23,65,19,90]
pos1,pos2=1,3

print(swapPositions2(list,pos1-1,pos2-1))
'''
'''
#翻转列表
def Reverse(list):
  return [ele for ele in reversed(list)]

def Reverse2(list):
  list.reverse()
  return list

def Reverse3(list):
  new_list=list[::-1]
  return new_list

list = [10,11,12,13,14,15]
print(Reverse3(list))
'''
'''
#判断元素是否在列表中存在
test_list=[1,6,3,5,3,4]
for i in test_list:
  if(i==4):
    print("存在")
  
if(4 in test_list):
  print("存在")

test_list_bitset=test_list[:]
test_list=set(test_list)
if(test_list_bitset.count(4)>0):
  print("存在")
'''

#类
'''
class MyClass:
  i=12345
  def f(self):
    return "hello,world"

x=MyClass()
print("MyClass 类的属性 i 为：", x.i)
print("MyClass 类的方法 f 输出为：", x.f())
'''
'''
class Complex:
  def __init__(self,realpart,imagpart):
    self.r=realpart
    self.i=imagpart
x=Complex(3.0,-4.5)
print(x.r,x.i)
'''
'''
class Test:
  def prt(self):
      print(self)
      print(self.__class__)

t=Test()
t.prt()
'''
'''
class people:
  name=''
  age=0
  __weight=0
  def __init__(self,n,a,w):
    self.name=n
    self.age=a
    self.__weight=w
  def speak(self):
    print("%s 说: 我 %d 岁。" %(self.name,self.age))

class student(people):
  grade=""
  def __init__(self,n,a,w,g):
    people.__init__(self,n,a,w)
    self.grade=g
  def speak(self):
    print("%s 说: 我 %d 岁了，我在读 %d 年级"%(self.name,self.age,self.grade))

#s=student('ken',10,60,3)
#s.speak()
class speaker():
  topic = ''
  name = ''
  def __init__(self,n,t):
    self.name=n
    self.topic=t
  def speak(self):
    print("我叫 %s，我是一个演说家，我演讲的主题是 %s"%(self.name,self.topic))

class sample(speaker,student):
  a=''
  def __init__(self,n,a,w,g,t):
    student.__init__(self,n,a,w,g)
    speaker.__init__(self,n,t)

test=sample("Tim",25,80,4,"Python")
test.speak()
'''
'''
class Parent:
  def myMethod(self):
    print('调用父类方法')

class Child(Parent):
  def myMethod(self):
    print("调用子类方法")

c=Child()
c.myMethod()
super(Child,c).myMethod()
'''
'''
class JustCounter:
  __secretCout=0
  publicCount=0
  def count(self):
    self.__secretCout+=1
    self.publicCount+=1
    print(self.__secretCout)

counter = JustCounter()
counter.count()
counter.count()
print(counter.publicCount)
print(counter.__secretCount)
'''
'''
class Site:
  def __init__(self,name,url):
    self.name=name
    self.__url=url

  def who(self):
    print("name : ", self.name)
    print("url",self.__url)

  def __foo(self):
    print("这是私有方法")
  def foo(self):
    print("这是公有方法")
    self.__foo()

x=Site('菜鸟教程', 'www.runoob.com')
x.who()
x.foo()
x.__foo()
'''
'''
class Vector:
  def __init__(self,a,b):
    self.a=a
    self.b=b
  def __str__(self):
    return 'Vector (%d, %d)' % (self.a, self.b)
  def __add__(self,other):
    return Vector(self.a+other.a,self.b+other.b)    

v1=Vector(2,10)
v2=Vector(5,-2)
print(v1+v2)
'''

