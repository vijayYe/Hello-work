#!/usr/bin/python3

"""
# Fibonacci series: 斐波纳契数列
# 两个元素的总和确定了下一个数
a, b = 0, 1
while b < 1000:
    print(b, end=',')
    a, b = b, a+b
print("")
"""
"""
age = int(input("请输入你家狗狗的年龄: "))
print("")
if age <= 0:
    print("你是在逗我吧!")
elif age == 1:
    print("相当于 14 岁的人。")
elif age == 2:
    print("相当于 22 岁的人。")
elif age > 2:
    human = 22 + (age -2)*5
    print("对应人类年龄: ", human)
                         
### 退出提示
input("点击 enter 键退出")
"""
"""
a = 0
while a<10:
    a+=1
    if(a==3):continue
    print(a,end=' ')
else:
    print("end")
    a=0
"""

"""
def max(a,b):
    if a > b:
        return a
    elif a==b:
        return 0
    else:
        return b

A=10
B=10
print(max(A,B))

str='acc'
print(str)
print(id(str))
str='ede'
print(str)
print(id(str))
"""

#"""
import re
str1 = 'www.runoob.com'
str2 = "Cats are smarter than dogs"
print(re.match('www', str1).span())  # 在起始位置匹配
print(re.match('run', str1).span())  # 在起始位置匹配
print(re.match('com', str1))         # 不在起始位置匹配

#"""
#"""
#"""
#"""
#"""
#"""
#"""
#"""
#"""
#"""
#"""
#"""
#"""
#"""
#"""
#"""
#"""
#"""
#"""


