# cook your dish here
#sahil
for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    res=[0 for i in range(n)]
    for i in range(n):
        bs,fs=0,0
        for j in range(i-1,-1,-1):
            #print(a[j],end=" ")
            if bs<=a[i]:
                res[j]+=1 
                bs+=a[j]
            else:
                break
        for j in range(i+1,n):
            #print(a[j],end=" ")
            if fs<=a[i]:
                res[j]+=1 
                fs+=a[j]
            else:
                break
        #print()
    print(*res)