# coding=utf-8
import requests #引入函式庫
from bs4 import BeautifulSoup
import re
f = open('news.txt','r')
a=[]
a=f.read().split()
print(a)
f.close()
f = open('out.txt','w',encoding = 'utf8')
q=1
for i in range(len(a)):
    url = a[i]
    resp = requests.get(url)
    soup = BeautifulSoup(resp.text, 'html.parser')
    title = soup.find('title')
    f.write(a[i]+' ')
    if title is not None:
        name=title.text.strip()
        print(name+str(q)+'\n')
        f.write(name)
    f.write('\n\n')
    q+=1
f.close()
