'''Finding Shortest Path for a Directed Acyclic Graph with complexity theta(V+E)'''


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

'''Fuction for Topological Sort'''
parent={}
T=[]            #To store sorted graph in order
def tsort_rec(V,adj,s):
    global parent
    for v in adj[s]:
        if v not in parent:
            parent[v]=s
            tsort_rec(V,adj,v)
    T.insert(0,s)
    
def tsort(V,adj):
    global parent
    for s in V:
        if s not in parent:
            parent[s]=None
            tsort_rec(V,adj,s)
            
'''Fuction for shortest path'''
dist={}         #to store distance from source
prnt={}         #to store parent as in shortest path
def relax(u,v,w):
    global dist,prnt
    if dist[v] > dist[u]+w:
        dist[v]=dist[u]+w
        prnt[v]=u
    
def spath(T,adj,source,weight):
    global dist,prnt
    for i in T:
        dist[i]=math.inf
    dist[source]=0
    prnt[source]=None
    for u in T:
        for v in adj[u]:
            relax(u,v,weight[(u,v)])
            
def minpath(src,dest):
    path=[dest]
    while(dest!=src):
        path.append(prnt[dest])
        dest=prnt[dest]
    path.reverse()
    print('Shortest Path=>',end=' ')
    for i in path:
        print(i,end=' ')
    print()

'''Driver Function'''
def main():
    g=Graph()
    g.V=['r','s','t','x','y','z']
    g.addedge('r','t',3)
    g.addedge('r','s',5)
    g.addedge('t','y',4)
    g.addedge('t','z',2)
    g.addedge('t','x',7)
    g.addedge('x','y',-1)
    g.addedge('x','z',1)
    g.addedge('s','t',2)
    g.addedge('s','x',6)
    g.addedge('y','z',-2)
    
    global T
    global dist
    '''Calling Topological Sort'''
    tsort(g.V,g.adj)
    '''Printing Topologically Sorted Graph'''    
    print(*T)
    '''Calling Shortest Path Fuction'''
    spath(T,g.adj,'s',g.weight)
    '''Printing all vertices and their distance from source'''
    for a,b in dist.items():
        print(a,b)
        if b!=math.inf:
            minpath('s',a)
        else:
            print('No Path')
        
main()

