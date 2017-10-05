'''
Fractional Knapsack

Greedy Approach

Complexity:- O(nlog(n))

'''
def knapsack(n,p,w,m):
    val=[p[i]/w[i] for i in range(n)]
    p=[x for _,x in sorted(zip(val,p),reverse=True)]
    w=[x for _,x in sorted(zip(val,w),reverse=True)]
    profit=0
    for i in range(n):
        if(m>0 and w[i]<=m):
            m-=w[i]
            profit+=p[i]
        else:
            break
    if(m>0):
        profit+=(p[i]/w[i])*m
    return profit

def main():
    n=int(input('Enter the no. of obects: '))
    profits=list(map(int,input('Profit List: ').split()))
    weights=list(map(int,input('Weight List: ').split()))
    m=int(input('Max Capacity: '))
    p=knapsack(n,profits,weights,m)
    print(p)
    
if __name__=="__main__":
    main()

