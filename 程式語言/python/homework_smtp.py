#!/usr/bin/python
# -*- coding: UTF-8 -*-
import smtplib
# import time
import datetime

sender = 'ubuntu'
receiver = ['testmail']

message = """

I will diss you.

"""

runtime = datetime.datetime(2017, 8, 19, 16, 23, 0)

print('等待程式執行...')

while datetime.datetime.now() < runtime:
    pass

try:
    smtpObj = smtplib.SMTP('192.168.0.16:25')
    smtpObj.sendmail(sender, receiver, message)
    print("成功送出")
except Exception:
    print("寄信失敗")

print('執行時間：', datetime.datetime.now())
print('程式結束')
