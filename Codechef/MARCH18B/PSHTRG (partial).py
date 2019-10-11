#sahil
from itertools import combinations
def p(a,b,c):
    if a+b>c and b+c>a and a+c>b:
        return a+b+c 
    else:
        return 0

n,q=map(int,input().split())
a=list(map(int,input().split()))
for _ in range(q):
    t,l,r=map(int,input().split())
    if t==1:
        a[l-1]=r
    else:
        #print(a[l-1:r])
        s=sorted(a[l-1:r],reverse=True)
        #print(s)
        ans=0
        for i in range(len(s)-2):
            t=p(s[i],s[i+1],s[i+2])
            if t>ans:
                ans=t
        print(ans)
            
