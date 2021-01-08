#!/usr/bin/python3

"""
list=[1,2,'三',4]
it = iter(list)    # 创建迭代器对象
for x in it:
    print (x, end=" ")
"""
import sys
 
def fibonacci(n): # 生成器函数 - 斐波那契
    a, b, counter = 0, 1, 0
    while True:
        if (counter > n): 
            return
        yield a
        a, b = b, a + b
        counter += 1
f = fibonacci(10) # f 是一个迭代器，由生成器返回生成
      
print("===");       
while True:
    try:
        print (next(f), end=" ")
    except StopIteration:
        sys.exit()
