for f in[*open(0)][1:]:
 n,s=map(int,f.split());v=n;d=1
 while sum(map(int,str(n)))>s:n+=-(n//d%10)%10*d;d*=10
 print(n-v)