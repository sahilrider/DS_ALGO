from collections import defaultdict
'''Class Definition'''
class Graph:

    def __init__(self):
        self.adj=defaultdict(list)

    def addedge(self,u,v):
       self.adj[u].append(v)


'''Fuction for Topological Sort'''
parent={}
T=[]
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
            
'''Driver Function'''
def main():
    g=Graph()
    V=[0,1,2,3,4,5]
    g.addedge(5,0)
    g.addedge(5,2)
    g.addedge(2,3)
    g.addedge(3,1)
    g.addedge(4,1)
    g.addedge(4,0)
    
    global T
    '''Calling Topological Sort'''
    tsort(V,g.adj)
    '''Sorted'''    
    print(*T)
main()

