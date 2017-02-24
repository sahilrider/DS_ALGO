'''Searching time= O(|s|+|t|)

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
    #print(rs,rt)
    for i in range(lt-ls+1):
        #print(i)
        if rs==rt:
            for j in range(ls):
                if s[j]!=t[i+j]:
                    break
            if j+1==ls:
                print('Substring found at %d'%(i))
        else:
            '''Deleting first element'''
            rt=(rt - ord(t[i])*(a**(ls-1)))% m
            '''Adding new element'''
            rt=(rt*a + ord(t[i+ls]))%m





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
