for s in[*open(0)][2::2]:
 a=s.split();n=len(a);i=j=a.index(max(a,key=int))
 while j<n and a[j]==a[i]:j+=1
 print((i or(-2,j-1)[j<n])+1)