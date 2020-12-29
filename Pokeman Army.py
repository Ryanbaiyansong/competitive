for s in[*open(0)][2::2]:
 a=k=0
 for i in map(int,s.split()):a+=i-k if i>k else 0;a,k=max(a,i),i
 print(a)
