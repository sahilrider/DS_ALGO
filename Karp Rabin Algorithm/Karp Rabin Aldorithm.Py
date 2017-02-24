def search(s,t,m):
    '''s=substring t=text string m=modulo'''
    ls=len(s)
    lt=len(t)
    a=256       #aplhabet size 256 bcz of ASCII
    rs=0        #hash of substring
    rt=0        #hash of text string
    
    '''Calculating hash of sub and first window of text'''
    for i in range(ls):
        rs=(rs*a + ord(s[i]))%m
        rt=(rt*a + ord(t[i]))%m

    if rs==rt:
        if s==t[:ls]:
            print('Substring found at 0')

    for i in range(ls,lt):
        
        '''Deleting first element'''
        rt=(rt - ord(t[i-ls])*(a**(ls-1)))% m
        '''Adding new element'''
        rt=(rt*a + ord(t[i]))%m
        
        if rs==rt :
            if s==t[i-ls+1:i+1]:
                print('Substring found at %d'%(i-ls+1))
        
            

def main():
    print('Enter the text string:')
    t=input()
    print('Enter the substring to be searched:')
    s=input()
    m=103 #prime no. for modulo
    search(s,t,m)

main()



'''Output:
Enter the text string:
aabaaccaadaabaaba
Enter the substring to be searched:
aaba
Substring found at 0
Substring found at 10
Substring found at 13'''
