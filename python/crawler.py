#!/usr/bin/python3

import urllib.request
url = http: //www.baidu.com/
webPage=urllib.request.urlopen(url)
data = webPage.read()
data = data.decode( 'UTF-8' )
print(data)
print(type(webPage))
print(webPage.geturl())
print(webPage.info())
print(webPage.getcode())