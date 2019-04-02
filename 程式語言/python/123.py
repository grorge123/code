aa = 5
class Demo:
    a = 5
    def __init__(self,i):
        self.b = 10
        global aa
        print(aa)
        aa = i
ss = Demo(2)
sss = Demo(8)
print(ss.a)
