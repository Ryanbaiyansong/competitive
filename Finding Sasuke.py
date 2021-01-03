for s in [*open(0)][2::2]:
    a = list(map(int, s.split()))
    for x, y in zip(a[::2], a[1::2]): print(-y, x, end = ' ')
    print()