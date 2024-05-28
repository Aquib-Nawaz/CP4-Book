from datetime import date, timedelta
n=int(input())
i=1
while i<=n:
    dat = int(input())
    y = dat % 10000
    d = (dat // 10000) % 100
    m = (dat // 1000000)
    g = date(y, m, d)+timedelta(days=280)
    z=""
    y=g.year
    if g>=date(y,1,21) and g<=date(y,2,19):
        z="Aquarius"
    elif g>=date(y,2,20) and g<=date(y,3,20):
        z="Pisces"
    elif g>=date(y,3,21) and g<=date(y,4,20):
        z="Aries"
    elif g>=date(y,4,21) and g<=date(y,5,21):
        z="Taurus"
    elif g>=date(y,5,22) and g<=date(y,6,21):
        z="Gemini"
    elif g>=date(y,6,22) and g<=date(y,7,22):
        z="Cancer"
    elif g>=date(y,7,23) and g<=date(y,8,21):
        z="Leo"
    elif g>=date(y,8,22) and g<=date(y,9,23):
        z="Virgo"
    elif g>=date(y,9,24) and g<=date(y,10,23):
        z="Libra"
    elif g>=date(y,10,24) and g<=date(y,11,22):
        z="Scorpio"
    elif g>=date(y,11,23) and g<=date(y,12,22):
        z="Sagittarius"
    else:
        z="Capricorn"
    print(str.format("{} {:02d}/{:02d}/{:04d} {:s}",i,g.month,g.day,g.year,z.lower()))
    i+=1


