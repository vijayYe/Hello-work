#!/usr/bin/python3


# 1
import requests, json, time, sys
from contextlib import closing
from bs4 import BeautifulSoup
from fake_useragent import UserAgent

class get_photos(object):

    def __init__(self): 
        self.photos_url = []
        #keyword = urllib2.quote(keyword)
        #self.target = 'https://image.baidu.com/search/acjson?tn=resultjson_com&ipn=rj&ct=201326592&is=&fp=result&queryWord='+keyword+'&cl=2&lm=-1&ie=utf-8&oe=utf-8&adpicid=&st=-1&z=&ic=0&word='+keyword+'&s=&se=&tab=&width=&height=&face=0&istype=2&qc=&nc=1&fr=&cg=wallpaper&pn='+num+'&rn=5s&gsm=1e&1534226537567='
        self.headers={'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.131 Safari/537.36'}
        #self.headers = {'User-Agent':'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/61.0.3163.79 Safari/537.36',
                        #'Cookie': 'winWH=%5E6_1366x625; BDIMGISLOGIN=0; BIDUPSID=7AA6985FA4302E7A6C6625FE0611698C; PSTM=1593574735; MCITY=-%3A; BAIDUID=72B4DC06A62227A81F09137DFDBC26F5:FG=1; BDUSS=c3QlA3UjNtTUJwMFh4VW1oblk1UmxwR3ZMWkE0WEkySklzaFlQdTNmYmxUT1ZmRVFBQUFBJCQAAAAAAAAAAAEAAAB~jck6VklWSVdJMjIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAOW~vV~lv71fYz; BDUSS_BFESS=c3QlA3UjNtTUJwMFh4VW1oblk1UmxwR3ZMWkE0WEkySklzaFlQdTNmYmxUT1ZmRVFBQUFBJCQAAAAAAAAAAAEAAAB~jck6VklWSVdJMjIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAOW~vV~lv71fYz; __yjs_duid=1_8222c45ffaef2177bda11dc4fd1c742f1608798907774; BDSFRCVID=LhLOJeC62xJXBAnrUYwM-VP3hHgENBRTH6aoV1JxrCFosQaRGUzmEG0PHx8g0Kubpw3xogKK0mOTH6KF_2uxOjjg8UtVJeC6EG0Ptf8g0M5; H_BDCLCKID_SF=tJ-t_CIhfC83fP36q4rth4Pqqxby26nr2gJ9aJ5nJDoWOxntLtTK3qFWXecpQTJ3WIv42qo4QpP-HJ7KDf6WKxtzhpbI5ljxQ6QLKl0MLpnWbb0xynoDKbby2MnMBMPjamOnaIQc3fAKftnOM46JehL3346-35543bRTLnLy5KJYMDcnK4-Xj5oQjajP; BDSFRCVID_BFESS=LhLOJeC62xJXBAnrUYwM-VP3hHgENBRTH6aoV1JxrCFosQaRGUzmEG0PHx8g0Kubpw3xogKK0mOTH6KF_2uxOjjg8UtVJeC6EG0Ptf8g0M5; H_BDCLCKID_SF_BFESS=tJ-t_CIhfC83fP36q4rth4Pqqxby26nr2gJ9aJ5nJDoWOxntLtTK3qFWXecpQTJ3WIv42qo4QpP-HJ7KDf6WKxtzhpbI5ljxQ6QLKl0MLpnWbb0xynoDKbby2MnMBMPjamOnaIQc3fAKftnOM46JehL3346-35543bRTLnLy5KJYMDcnK4-Xj5oQjajP; delPer=0; BAIDUID_BFESS=8B826189955128FC50BE55B004800007:FG=1; BDRCVFR[LjY4kjSi7r_]=OjjlczwSj8nXy4Grjf8mvqV; BDRCVFR[feWj1Vr5u3D]=I67x6TjHwwYf0; PSINO=2; H_PS_PSSID=33423_33401_33258_33344_31660_33284_33286_33413_33370; BDORZ=B490B5EBF6F3CD402E515D22BCDA1598; BA_HECTOR=a4242ka00l2524054q1fvvd6k0r; BDRCVFR[dG2JNJb_ajR]=mk3SLVN4HKm; userFrom=www.baidu.com; indexPageSugList=%5B%22%E6%B5%B7%E8%B4%BC%E7%8E%8B%22%2C%22%E6%99%BA%E8%83%BD%E5%AE%B6%E5%B1%8586%E6%99%BA%E8%83%BD%E6%9A%97%E5%90%88%E5%BC%80%E5%85%B3%22%2C%22%E6%99%BA%E8%83%BD%E5%AE%B6%E5%B1%8586%E6%9A%97%E5%90%88%22%2C%22%E6%99%BA%E8%83%BD%E5%AE%B6%E5%B1%85%E6%9A%97%E5%90%88%22%2C%22%E6%99%BA%E8%83%BD%E7%BD%91%E5%85%B3%22%2C%22%E6%99%BA%E8%83%BD%E5%AE%B6%E5%B1%85%E6%9A%97%E5%90%88%E7%BD%91%E5%85%B3%22%2C%225G%E8%8A%AF%E7%89%87%E6%A8%A1%E7%BB%84%22%2C%22%E8%8A%AF%E7%89%87%E6%A8%A1%E7%BB%84%22%2C%22%E6%A8%A1%E7%BB%84%22%5D; cleanHistoryStatus=0; ab_sr=1.0.0_ZDg0ZjBiNWM3OTk5ODJiMGRmNDM5YTYwMWFiMGY0YjIyZTA4MDdkMmQ3ZWJhN2M0NzZlYTAyZTJlMmY2ZjMzMmRmNWM3OTk5M2FiODg3OTgyNWJhN2E0ZDhmM2M4ZTRmZTgxNWI3ZTJjYWZjMDc5MzUzM2RmOGUyYzNiNzBjN2I='}

    def get_ids(self, keyword, num):#keyword搜索关键字， num每次获取多少张
        self.target = 'https://image.baidu.com/search/acjson?tn=resultjson_com&ipn=rj&ct=201326592&is=&fp=result&queryWord='+keyword+'&cl=2&lm=-1&ie=utf-8&oe=utf-8&adpicid=&st=-1&z=&ic=0&word='+keyword+'&s=&se=&tab=&width=&height=&face=0&istype=2&qc=&nc=1&fr=&cg=wallpaper&pn='+num+'&rn=5s&gsm=1e&1534226537567='
        print(self.target);
        #req = requests.get(url=self.target, headers=self.headers, verify=False)
        req = requests.get(url=self.target, headers=self.headers)
        html = req.text
        try:
            s_json=json.loads(html)
            #print(s_json)
            dataList = s_json['data']
            x = 0
            for x in range(0,len(dataList)):
                try:
                    path = str(dataList[x]['thumbURL'])
                    self.photos_url.append(path)
                    print(path)
                except KeyError as e:
                    print('没有找到路径')
        except:
            print("json error")
        data_t = open("data.txt", mode='w+')
        data_t.write(str(s_json))
        data_h = open("data.html", mode='w+')
        data_h.write(html)
 
  
    def download(self, photo_id, filename):
        #target = self.download_server.replace('xxx', photo_id) #替换
        target = photo_id
        try :
            r = requests.get(url=target, headers=self.headers)
            with open(r'picture/%d.jpg' % filename, 'wb+') as f:
                for chunk in r.iter_content(chunk_size = 1024):
                    if chunk:
                        f.write(chunk)
                        f.flush()  
        except:
            print("下载失败")

if __name__ == '__main__':
    #for i in sys.argv:
        #print(i)
    img_num = int(sys.argv[1])
    print("img number:",img_num)
    gp = get_photos()
    num = 0
    index = 1
    print('图片下载中:')
    #while True:
    while index <= img_num:
        #print('获取图片连接中:')
        gp.get_ids('海贼王', str(num))      
        for i in range(len(gp.photos_url)):
            img_url = gp.photos_url.pop()
            print('  正在下载第%d张图片,url: ' % index + img_url)
            #gp.download(gp.photos_url[i], (i+1))
            gp.download(img_url, index)
            index += 1
        num += 5
        #print(len(gp.photos_url))
        #print(num)
        





     
   
