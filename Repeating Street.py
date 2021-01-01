for _ in range(int(input())):
  n,k= map(int, input().split())
  c = list(map(int, input().split()))
  s = set(c)
  day = 10**5
  for i in s:
    m=0;x = 0
    while x < n:
      if c[x] == i:
        x += 1
      else:
        x +=k
        m +=1
    day = min(day, m)
  print(day)