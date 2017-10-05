'''
    Huffman Codes
    Time Complexity : O(nlog(n))
    Space Complexity : O(n)
'''
from heapq import *
from itertools import groupby

class Node(object):
    def __init__(self,char,freq):
        self.char=char
        self.freq=freq
        self.left=None
        self.right=None

    def setchildren(self,l,r):
        self.left=l
        self.right=r

    def __str__(self):
        return "%s %s %s %s"%(self.char,self.freq,self.left,self.right)

    def __lt__(self, other):
        return self.freq < other.freq

def HuffmanCodes(data):
    q=[ Node(a,len(list(b))) for a,b in groupby(sorted(data))]
    heapify(q)
    while len(q)>1:
       x=heappop(q)
       y=heappop(q)
       z=Node(None,x.freq+y.freq)
       z.setchildren(x,y)
       heappush(q,z)

    codes={}
    def codeIt(s,node):
        if node.char:
            if not s:
                codes[node.char]="0"
            else:
                codes[node.char]=s
        else:
            codeIt(s+"0",node.left)
            codeIt(s+"1",node.right)

    codeIt("",q[0])
    #print(codes)
    print(codes,"".join([codes[a] for a in data]))
    

def main():
    inp=input("Input any text to be encoded: ")
    HuffmanCodes(inp)

main()
    
