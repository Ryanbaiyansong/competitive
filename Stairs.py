for s in[*open(0)][1:]:
 x=int(s);i=-1
 while x>=0:i+=1;k=2**i;x-=2*k*k-k
 print(i)