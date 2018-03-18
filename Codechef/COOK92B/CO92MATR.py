#sahil
for _ in range(int(input())):
    n,m=map(int,input().split())
    mat=[]
    t=[1 for j in range(m+1)]
    mat.append(t)
    flag=1
    for i in range(n):
        t=list(map(int,input().split()))
        mat.append([1]+t)
    for i in range(1,n+1):
        for j in range(1,m+1):
            if mat[i][j]==-1:
                mat[i][j]=max(mat[i][j-1],mat[i-1][j])
            else:
                if (mat[i][j]<mat[i-1][j] or mat[i][j]<mat[i][j-1]):
                    #print(i,j,mat[i][j],mat[i-1][j],mat[i][j-1])
                    flag=0
                    break
    if flag==0:
        print(-1)
    else:
        for i in range(1,n+1):
            for j in range(1,m+1):
                print(mat[i][j],end=" ")
            print()
    #print(mat)
