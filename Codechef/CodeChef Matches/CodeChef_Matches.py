def noMatch(digit):
    if digit=='0' or digit=='6' or digit=='9':
        return 6
    elif digit=='2' or digit=='3' or digit=='5':
        return 5
    else:
        if digit=='1':
            return 2
        elif digit=='4':
            return 4
        elif digit=='7':
            return 3
        else:
            return 7
t = int(input())
i = 0
while i < t:
    value = 0
    a, b = map(int, input().split())
    c = str(a+b)
    for j in range(0,len(c)):
        digit = c[j]
        value_1 = noMatch(digit)
        value = value + value_1
    print(value)
    i += 1

'''
PROBLEM URL:https://www.codechef.com/problems/MATCHES

TEST CASES:
3
123 234
10101 1010
4 4
'''
