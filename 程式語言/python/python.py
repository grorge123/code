import sys
import math
s=[0,2]
d=[2]
now = 3
while len(d)<=5001:
    fi = 0
    for i in range(2,int(math.sqrt(now)+1)):
        if now%i == 0:
            fi = 1
            break;
    if fi == 0:
        d.append(now)
    now+=1
for i in range(2,5002):
        s.append(s[i-1]*d[i-1])
for n in sys.stdin:
    n=int(n)
    print(s[n])
    
