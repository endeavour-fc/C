
#test1
#print("hello,world\n");

#test2
#num1=input('输入一个浮点数')
#num2=input('输入一个浮点数')
#sum=float(num1)+float(num2)
#print('num1 + num2 = ',sum)

#test3
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

#test4
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

#test5
'''
a=float(input('输入三角形第一边长：'))
b=float(input('输入三角形第二边长：'))
c=float(input('输入三角形第三边长：'))
s=(a+b+c)/2
area = (s*(s-a)*(s-b)*(s-c))** 0.5
print('三角形面积为 %0.2f'%area)
'''
#test6
'''
def findArea(r):
  PI = 3.142
  return PI*(r*r)
print('圆的面积%.6f\n' % findArea(5))
'''
#test7
'''
import random

print(random.randint(0,9))
'''
#test8
'''
celsius = float(input('输入摄氏温度: '))
 
# 计算华氏温度
fahrenheit = (celsius * 1.8) + 32
print('%0.1f 摄氏温度转为华氏温度为 %0.1f ' %(celsius,fahrenheit))
'''
#test9
'''
x=input('输入x值：')
y=input('输入y值：')
temp=x;
x=y;
y=temp;
print('交换后 x 的值为: {}'.format(x))
print('交换后 y 的值为: {}'.format(y))
'''
#test10
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
#test11
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