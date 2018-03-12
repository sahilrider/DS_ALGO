# cook your dish here
#sahil

for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    g=list(map(int,input().split()))
    f,b=1,1 
    for i in range(n):
        if l[i]>g[i]:
            f=0
        if l[i]>g[n-i-1]:
            b=0
    if f==1 and b==1:
        print('both')
    if f==1 and b==0:
        print('front')
    if f==0 and b==1:
        print('back')
    if f==0 and b==0:
        print('none')
        