'''Implemented as shown in MIT 6.006'''

from collections import defaultdict
'''Class Definition'''
class Graph:

    def __init__(self):
        self.adj=defaultdict(list)

    def addedge(self,u,v):
       self.adj[u].append(v)

'''Fuction for DFS'''
parent={}
def dfs_visit(V,adj,s):
    global parent
    for v in adj[s]:
        if v not in parent:
            print(v,end=' ')
            parent[v]=s
            dfs_visit(V,adj,v)

def dfs(V,adj):
    global parent
    for s in V:
        if s not in parent:
            print(s,end=' ')
            parent[s]=None
            dfs_visit(V,adj,s)
    print()

'''Driver Function'''
def main():
    g=Graph()
    V=['a','b','c','d','e','f']
    g.addedge('a','b')
    g.addedge('b','e')
    g.addedge('e','d')
    g.addedge('a','d')
    g.addedge('d','b')
    g.addedge('c','e')
    g.addedge('c','f')
    g.addedge('f','f')

    '''Calling DFS'''
    dfs(V,g.adj)

    '''Just to check parent of each vertex'''
    global parent
    print(parent)


main()
