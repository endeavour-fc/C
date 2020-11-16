import re

# f=open('test.txt','r')
# txt=f.readlines()
# print(txt)
a="python"
#匹配开头
print(re.match('^p(.*?)n$',a).group())
#