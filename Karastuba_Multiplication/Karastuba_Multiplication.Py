'''Karatsuba Multiplication
   Time Complexity: O(n**1.58)'''

def karatsuba(x,y):
    lx=len(str(x))
    ly=len(str(y))

    if lx==1 or ly ==1:
        return x*y
    else:
        ''' 0<=x,y<10**n'''
        n=max(lx,ly)+1
        nby2=n//2

        ''' x=x1+ 10**(n//2) + x0 '''
        
        x1=x//(10**nby2)
        x0=x%(10**nby2)

        ''' y=y1+ 10**(n//2) + y0 '''
        
        y1=y//(10**nby2)
        y0=y%(10**nby2)
        
        z0=karatsuba(x0,y0)
        z2=karatsuba(x1,y1)
        z1=karatsuba(x0+x1,y0+y1)-z0-z2

        res = z2*(10**(2*nby2)) + z1*(10**nby2) + z0

        return res

def main():
    x=12345
    y=6789

    r=karatsuba(x,y)
    print(r)

main()
