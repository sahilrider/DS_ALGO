'''BFS of a Undirected graph ,can also be modified to work for Directed Graph'''

from collections import defaultdict

class Graph:

    '''Initialises graph with a dict which stores adj list of every vertex'''
    def __init__(self):
        self.adj=defaultdict(list)

    def __str__(self):
        for v,e in self.adj.items():
            print(v,e)
            
    '''Adding edges'''
    def addedge(self,u,v):
        self.adj[u].append(v)
        self.adj[v].append(u)   #Remove this line to implement directed graph

    def bfs(self,start):
        level={start:0}
        parent={start:None}
        i=1
        frontier=[start]
        while frontier:
            next=[]
            for u in frontier:
                for v in self.adj[u]:
                    if v not in level:
                        level[v]=i
                        parent[v]=u
                        next.append(v)
            
            frontier=next
            i=i+1
        
        return (level,parent)

def minpath(g,src,dest):
    (level,parent)=g.bfs(src)
    path=[dest]
    dist=level[dest]
    while(dest!=src):
        path.append(parent[dest])
        dest=parent[dest]
    path.reverse()
    print('Minumum Path:',end='')
    print(*path)
    print('Distance:',end='')
    print(dist)

'''Value of dest changes in this function ,if want to edit it for further applications ,use another temp variable to store dest'''

def main():
    g=Graph()
    g.addedge('a','z')
    g.addedge('a','s')
    g.addedge('s','x')
    g.addedge('x','d')
    g.addedge('x','c')
    g.addedge('d','f')
    g.addedge('d','c')
    g.addedge('c','f')
    g.addedge('c','v')
    g.addedge('v','f')

    '''Prints minimum Path from a vertex to starting vertex'''
    minpath(g,'s','v')

    
main()
