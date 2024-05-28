from datetime import date
import itertools
n = int(input())
def valid(c,y,m,d):
    isLeap = False
    y=c*100+y
    if m==0 or d==0:
        return False
    if y%400 == 0 or (y%4 == 0 and y%100 != 0):
        isLeap = True
    if isLeap and m == 2 and d <= 29:
        return True
    if not isLeap and m == 2 and d <= 28:
        return True
    if m in [1,3,5,7,8,10,12] and d <= 31:
        return True
    if m in [4,6,9,11] and d <= 30:
        return True
    return False

while n != 0:
    ina = [0]*3
    ls = []
    cent, ina[0],ina[1],ina[2] = map(int,input().split())
    for x in itertools.permutations(ina):
        y,m,d = x
        if valid(cent,y,m,d):
            ls.append(x)
    n-=1
    if ls == []:
        print(-1)
        continue
    y,m,d = min(ls)
    print(str.format('{:02d} {:02d} {:02d}', y,m,d))

