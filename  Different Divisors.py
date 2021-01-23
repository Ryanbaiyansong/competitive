a=[1]*8**5
i=2
while b:=[0]*-(-8**5//i+i):a[i*i::i]=b;i+=1
for s in[*open(0)][1:]:d=int(s);i=a.index(1,d+1);print(i*a.index(1,i+d))