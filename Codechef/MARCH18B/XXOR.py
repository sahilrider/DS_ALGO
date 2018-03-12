#sahil
from operator import add,sub

def main():
    n,q=map(int,raw_input().split())
    a=list(map(int,raw_input().split()))
    cumsum=[0 for i in range(31)]
    a2=[]
    for i in a:
        binary=list(map(int,bin(i)[2:].zfill(31)))
        cumsum=list(map(add,cumsum,binary))
        a2.append(cumsum)
    #print(a2)
    
    for _ in range(q):
        l,r=map(int,raw_input().split())
        ans=''
        l=l-1
        r=r-1
        
        if l==0:
            res=a2[r]
        else:
            res=list(map(sub,a2[r],a2[l-1]))
        for ones in res:
            zeroes=r-l+1 - ones
            if ones>=zeroes:
                ans+='0'
            else:
                ans+='1'
        print(int(ans,2))
    
main()
    