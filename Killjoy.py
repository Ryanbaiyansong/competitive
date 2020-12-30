for _ in range(int(input())):
    n,x=map(int,input().split())
    l=list(map(int,input().split()))
    print((0,2-(x in l or sum(l)==x*n))[l!=[x]*n])