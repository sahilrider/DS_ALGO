# cook your dish here
for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    d={}
    for i in a:
        d[i]=d.get(i,0)+1 
    #print(d)
    s=0
    for i in d.values():
        s+=i-1 
    print(s)