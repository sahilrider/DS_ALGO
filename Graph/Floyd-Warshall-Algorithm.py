from collections import defaultdict

INF=float('inf')

'''Creating Class for Graph with adj matrix and vertex'''
class Graph:
    def __init__(self,m,v):
        self.adj=m
        self.V=v

def printsol(d,p,src,dest):

    #changing as matrix is zero indexed
    src-=1
    dest-=1
    print("Distance between %d and %d is: %d"%(src+1,dest+1,d[src][dest]))
    path=[dest]
    while(dest!=src):
        path.append(p[src][dest])
        dest=p[src][dest]
    path.reverse()
    print('path:',end='')
    for i in path:
        print(i+1,end=' ')
           
def floydwarshall(g):

    #initialising distance matrix
    d=g.adj
    #initialising parent matrix
    p=[['N' for i in range(g.V)]for j in range(g.V)]
    for i in range(g.V):
        for j in range(g.V):
            if(g.adj[i][j]!=INF and g.adj[i][j]!=0):
                p[i][j]=i
            
    #applying algorithm

    for k in range(g.V):

        for i in range(g.V):
            for j in range(g.V):

                if( d[i][j]<=(d[i][k]+d[k][j]) ):
                    pass
                else:
                    p[i][j]=p[k][j]                 #updating parent matrix

                d[i][j]=min(d[i][j], d[i][k]+d[k][j])       #updating distance matrix

    return d,p

def main():
    #adacency matrix 
    m=[[0,3,8,INF,-4],
       [INF,0,INF,1,7],
       [INF,4,0,INF,INF],
       [2,INF,-5,0,INF],
       [INF,INF,INF,6,0]]
    #no.of vertices
    v=5
    #Graph initialising
    g=Graph(m,v)
    #calling floyd warshall algorithm
    dist,parent=floydwarshall(g)
    
    #printing solution
    source=2
    dest=5
    printsol(dist,parent,source,dest)

if __name__=='__main__':
    main()
