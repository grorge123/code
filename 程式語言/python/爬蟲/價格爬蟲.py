# -*- coding: utf8 -*-
from lxml import etree  
import requests  
def main():  
    avd = requests.get("http://axe-level-1.herokuapp.com/")
    avd.encoding='utf8'
    avs = etree.fromstring(avd.content, etree.HTMLParser())
    jsonData = "["
    for row in avs.xpath("//table[@class='table']/tr[position()>1]"):
        column = row.xpath("./td/text()")
        tmp= '{"name": "%s", "grades": {"國語": %s, "數學": %s, "自然": %s, "社會": %s, "健康教育": %s}},\n' % (column[0], column[1], column[2], column[3], column[4], column[5])
        jsonData += tmp
    # 刪除最後一個逗號 
    print(jsonData[0:-1] + ']')

if __name__ == "__main__":  
	main()