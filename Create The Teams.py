for _ in " "*int(input()):
    a,b=map(int,input().split());z=sorted(map(int,input().split()))[::-1];s=c=i=0
    while(i<a):
        c+=1
        if c*z[i]>=b:s+=1;c=0
        i+=1
    print(s)