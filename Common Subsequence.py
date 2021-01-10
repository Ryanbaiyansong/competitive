from collections import defaultdict
from heapq import heapify, heappop, heappush
def solve():
    n, s, y = map(int, input().split());a = input().split();d = defaultdict(list)
    for i, x in enumerate(a):d[x].append(i)
    for i in range(1, n + 2):
        e = str(i)
        if e not in d:break
    q = [(-len(d[x]), x) for x in d.keys()];heapify(q);ans,p = [0] * n,[]
    for i in range(s):
        l, x = heappop(q);ans[d[x].pop()] = x;l += 1
        if l:heappush(q, (l, x))
    while q:l, x = heappop(q);p.extend(d[x])
    if p:
        h = (n - s) // 2;y = n - y;q = p[h:] + p[:h]
        for x, z in zip(p, q):
            if a[x] == a[z]:
                if y:ans[x] = e;y -= 1
                else:print("NO");return
            else:ans[x] = a[z]
        for i in range(n - s):
            if y and ans[p[i]] != e:ans[p[i]] = e;y -= 1
    print("YES");print(' '.join(ans))
for t in range(int(input())):solve()