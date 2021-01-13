t=int(input())
 
 
for _ in range(t):
	n=int(input())
	a=[int(i) for i in input()]+[0]
	b=[int(i) for i in input()]+[0]
	
	op1=[]
	op2=[]
	for i in range(1,n+1):
		if a[i]!=a[i-1]:
			op1.append(i)
		if b[i]!=b[i-1]:
			op2.append(i)
	op=op1+op2[::-1]
	print(len(op),*op)