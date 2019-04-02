class student:
    def __init__(self,name,ty):
        self.name = name
        self.ty = ty
        self.score = []
        self.all = 0
        self.F = 0
    def add(self,now_score):
        self.score.append(now_score)
        self.all += now_score
        if now_score < 60:
            self.F += 1
    def show(self):
        print("Name: %s" %(self.name))
        print("Gender: %s" %(self.ty))
        print("Grades:",end = ' ')
        print(self.score)
        print("Avg: %.1f" %(self.all / len(self.score)))
        print("Fail Number: %d"  %(self.F))
        print()
def Top(*all_stu):
    Max = 0
    re = student("","")
    for i in all_stu:
        if Max < i.all / len(i.score):
            Max = i.all / len(i.score)
            re = i

    return re
s1 = student("Tom","M")
s2 = student("Jane","F")
s3 = student("John","M")
s4 = student("Ann","F")
s5 = student("Peter","M")
s1.add(80)
s1.add(90)
s1.add(55)
s1.add(77)
s1.add(40)
s2.add(58)
s2.add(87)
s3.add(100)
s3.add(80)
s4.add(40)
s4.add(55)
s5.add(60)
s5.add(60)
s1.show()
s2.show()
s3.show()
s4.show()
s5.show()
print("Top Student:")
Top(s1, s2, s3, s4, s5).show()
