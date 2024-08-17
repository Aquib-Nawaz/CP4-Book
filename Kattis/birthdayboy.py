from datetime import date, timedelta
def getYear(m,d):
    if m<10 or m==10 and d<=27:
        return 2002
    return 2001
n  = int(input())
ls = []
for i in range(n):
    name, dt = input().split()
    m,d = map(int,dt.split('-'))
    y = getYear(m,d)
    ls.append(date(y,m,d))
if(len(ls)==1):
    prevDate = ls[0]+timedelta(days=-1)
    print(str.format("{:02d}-{:02d}", prevDate.month, prevDate.day))
    exit()
ls = sorted(ls)
ans , v = None,0
if ls[0]!=date(2001,10,28):
    ans = ls[0]+timedelta(days=-1)
    v = 365-(ls[-1]-ls[0]).days-1
for i in range(n-1):
    diff = (ls[i+1]-ls[i]).days-1
    if diff > v:
        ans = ls[i+1]+timedelta(days=-1)
        v = diff
if ls[0]==date(2001,10,28):
    diff = 365-(ls[-1]-ls[0]).days-1
    if  diff > v:
        ans = ls[0]+timedelta(days=-1)
        v = diff
print(str.format("{:02d}-{:02d}", ans.month, ans.day))

