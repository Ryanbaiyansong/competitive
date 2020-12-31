I=input
for _ in[0]*int(I()):
 I();a=I().split();b=[i for i,x in enumerate(I()[::2])if'1'>x]
 for i,x in zip(b[::-1],sorted(int(a[i])for i in b)):a[i]=x
 print(*a)