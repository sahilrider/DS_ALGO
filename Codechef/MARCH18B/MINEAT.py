# cook your dish here
#sahil
def binary(a,n,h,mid):
    res=0
    for i in a:
        ctr=i//mid 
        if i%mid!=0:
            ctr+=1 
        res+=ctr
    if res<=h:
        return True
    else:
        return False
        
def main():
    for _ in range(int(input())):
        n,h=map(int,input().split())
        a=list(map(int,input().split()))
        m=max(a)
        res=m 
        low,high=1,m
        while(low<=high):
            mid=(low+high)//2
            if binary(a,n,h,mid):
                res=mid
                high=mid-1
            else:
                low=mid+1
        print(res)
            
main()
        
    