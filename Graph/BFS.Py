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
            print(*frontier,end=' ')
            frontier=next
            i=i+1
        print()


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
    
    '''BFS is a instance of class which prints the BFS of a graph if starting vertex in given'''
    g.bfs('s')
    
main()
