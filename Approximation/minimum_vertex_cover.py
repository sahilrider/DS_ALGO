from collections import defaultdict
import math
'''Class Definition'''
class Graph:
    def __init__(self,v):
        self.adj=defaultdict(list)
        self.V=[i for i in range(v)]

    def addEdge(self,u,v):
       self.adj[u].append(v)
       self.adj[v].append(u)

    def printvertexcover(self):
        visited={}
        for u in self.V:
            if u not in visited:
                for v in self.adj[u]:
                    if v not in visited:
                        visited[v]=True
                        visited[u]=True
                        break

        print(sorted(visited.keys()))

def main():
    g=Graph(7)
    g.addEdge(0, 1)
    g.addEdge(0, 2)
    g.addEdge(1, 3)
    g.addEdge(3, 4)
    g.addEdge(4, 5)
    g.addEdge(5, 6)

    g.printvertexcover()
    
main()
