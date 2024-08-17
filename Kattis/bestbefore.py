from datetime import date
import itertools

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


ina = [0]*3
ls = []
cent=20
dt = input()
ina[0],ina[1],ina[2] = map(int,dt.split('/'))
f = True
for i in range(3):
    if ina[i]>=2000:
        f = False
        if(valid(0,ina[i], ina[i-1],ina[i-2])):
            ls.append((ina[i],ina[i-1],ina[i-2]))
        if(valid(0,ina[i], ina[i-2],ina[i-1])):
            ls.append((ina[i],ina[i-2],ina[i-1]))
        break

if f:
    for x in itertools.permutations(ina):
        y,m,d = x
        if valid(cent,y,m,d):
            ls.append(x)

if ls == []:
    print(dt +" is illegal")
    exit()

y,m,d = min(ls)
print(str.format('{:04d}-{:02d}-{:02d}', cent*100+y if f else y,m,d))

