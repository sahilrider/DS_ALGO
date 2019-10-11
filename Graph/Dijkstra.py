from collections import defaultdict
import math
'''Class Definition for weighted graph'''
class Graph:
    def __init__(self):
        self.adj=defaultdict(list)
        self.weight=defaultdict(int)
        self.V=[]

    def addedge(self,u,v,w):
       self.adj[u].append(v)
       self.weight[(u,v)]=w

'''Dijsktra'''
dist={}
parent={}
def init_single_source(g,start):
    for v in g.V:
        dist[v]=math.inf
        parent[v]=None
    dist[start]=0

def extract_min(q):
    res=q[0]
    for i in q:
        if dist[i]<dist[res]:
            res=i
    q.remove(res)
    return res

def relax(u,v,w):
    global dist,parent
    if dist[v] > dist[u]+w:
        dist[v]=dist[u]+w
        parent[v]=u

def dijkstra(g,start):
    init_single_source(g,start)
    #s for set of vertices whose path from source is calculated
    s=[]
    #q for remaining vertices
    q=g.V
    while q:
        u=extract_min(q)
        s.append(u)
        for v in g.adj[u]:
            relax(u,v,g.weight[(u,v)])
    
def printpath(src,dest):
    destt=dest
    path=[dest]
    while(dest!=src):
        path.append(parent[dest])
        dest=parent[dest]
    path.reverse()
    print('Shortest Path from %s to %s=>'%(src,destt),end=' ')
    for i in path:
        print(i,end=' ')
    print()
    
'''Driver Function'''
def main():
    g=Graph()
    
    g.V=['s','t','x','y','z']
    g.addedge('s','t',10)
    g.addedge('s','y',5)
    g.addedge('t','y',2)
    g.addedge('t','x',1)
    g.addedge('x','z',4)
    g.addedge('z','x',6)
    g.addedge('z','s',7)
    g.addedge('y','z',2)
    g.addedge('y','t',3)
    g.addedge('y','x',9)

    start='s'
    dijkstra(g,start)

    print("Printing all vertices,their distance from source and path")
    for v,d in dist.items():
        printpath(start,v)
        print('Distance=%d'%(d))
        
main()
