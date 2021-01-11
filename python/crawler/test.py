#!/usr/bin/python3



"""
import urllib.request
data_h = open("data.html", mode='w+')
data_t = open("data.txt", mode='w+')
#url = 'http://www.douban.com/'
url = 'http://www.baidu.com/'
webPage=urllib.request.urlopen(url)
data = webPage.read()
data = data.decode( 'UTF-8' )

#print(data)
print(type(webPage))
print(webPage.geturl())
#print(webPage.info())
print(webPage.getcode())
#data_h.write(data)
#data_t.write(webPage.getcode())
"""

"""
import urllib.request
data_h = open("data.html", mode='w+')
data_t = open("data.txt", mode='w+')
weburl = 'http://www.douban.com/'
webheader = { 'User-Agent' : 'Mozilla/5.0 (Windows NT 6.1; WOW64; rv:23.0) Gecko/20100101 Firefox/23.0' }
req = urllib.request.Request(url=weburl, headers=webheader) 
webPage=urllib.request.urlopen(req)
data = webPage.read()
data = data.decode( 'UTF-8' )
#print(data)
print(type(webPage))
print(webPage.geturl())
#print(webPage.info())
print(webPage.getcode())
data_h.write(data)
"""

"""
import urllib.request
data_h = open("data.html", mode='w+')
data_t = open("data.txt", mode='w+')
weburl = 'http://www.douban.com/'
webheader1 = { 'User-Agent' : 'Mozilla/5.0 (Windows NT 6.1; WOW64; rv:23.0) Gecko/20100101 Firefox/23.0' }
webheader2 = {
     'Connection' : 'Keep-Alive' ,
     'Accept' : 'text/html, application/xhtml+xml, */*' ,
     'Accept-Language' : 'en-US,en;q=0.8,zh-Hans-CN;q=0.5,zh-Hans;q=0.3' ,
     'User-Agent' : 'Mozilla/5.0 (Windows NT 6.3; WOW64; Trident/7.0; rv:11.0) like Gecko' ,
     # 'Accept-Encoding' : 'gzip, deflate' ,
     'Host' : 'www.douban.com' ,
     'DNT' : '1'
     }
req = urllib.request.Request(url=weburl, headers=webheader2) 
webPage=urllib.request.urlopen(req)
data = webPage.read()
data = data.decode( 'UTF-8' )
#print(data)
print(type(webPage))
print(webPage.geturl())
#print(webPage.info())
print(webPage.getcode())
data_h.write(data)
"""

import urllib.request 
import socket 
import re 
import sys 
import os 
targetDir = r'picture'  #文件保存路径
def destFile(path):
     if not os.path.isdir(targetDir): 
         os.mkdir(targetDir) 
     pos = path.rindex( '/' ) 
     t = os.path.join(targetDir, path[pos+ 1 :]) 
     return t 

if __name__ == '__main__':  #程序运行入口
     weburl = 'http://www.douban.com/'
     webheaders = { 'User-Agent' : 'Mozilla/5.0 (Windows NT 6.1; WOW64; rv:23.0) Gecko/20100101 Firefox/23.0' }
     webheaders2 = {
         'Connection' : 'Keep-Alive' ,
         'Accept' : 'text/html, application/xhtml+xml, */*' ,
         'Accept-Language' : 'en-US,en;q=0.8,zh-Hans-CN;q=0.5,zh-Hans;q=0.3' ,
         'User-Agent' : 'Mozilla/5.0 (Windows NT 6.3; WOW64; Trident/7.0; rv:11.0) like Gecko' ,
         # 'Accept-Encoding' : 'gzip, deflate' ,
         'Host' : 'www.douban.com' ,
         'DNT' : '1'
         }
     req = urllib.request.Request(url=weburl, headers=webheaders2)  #构造请求报头
     webpage = urllib.request.urlopen(req)  #发送请求报头
     contentBytes = webpage.read() 
 
     print("read url")
     print(set(re.findall(r'(https:[^s]*?(jpg|png|gif))' , str(contentBytes))))
     for link, t in set(re.findall(r'(https:[^s]*?(jpg|png|gif))' , str(contentBytes))):  #正则表达式查找所有的图片
         print(link)
         #print(t)
         try :
            urllib.request.urlretrieve(link, destFile(link)) #下载图片
         except:
             print( '失败' ) #异常抛出

             