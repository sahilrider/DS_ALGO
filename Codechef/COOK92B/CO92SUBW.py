#sahil
for _ in range(int(input())):
    x=int(input())
    t=0
    step=1 
     
    while(x!=0):
        if x>=step:
            x-=step
            t+=1
            step+=1 
            
        else:
            t+=min(x,1+abs(x-step))
            x=0
    print(t)
        
