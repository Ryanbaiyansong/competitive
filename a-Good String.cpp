def f(s,c):n=len(s)//2;d=chr(c);return min(n-s.count(d,i,i+n)+f(s[n-i:n-i+n],c+1)for
i in(0,n))if n else s[0]!=d
for s in[*open(0)][2::2]:print(+f(s[:-1],97))