# cook your dish here
#sahil

for _ in range(int(input())):
    loss=0
    for i in range(int(input())):
        p,q,d=map(int,input().split())
        loss+=((d**2)*q*p)/10000
    print(loss)