# adapted from Corman algorithms book, 3rd ed. (section 15.2)
import sys


def matrix_chain_order(p):
    n = len(p)
    m = [[0 for x in range(n)] for y in range(n)]
    s = [[0 for x in range(n)] for y in range(n)]

    for l in range(2, n):
        for i in range(1, n-l+1):
            j = i + l - 1
            m[i][j] = sys.maxsize
            for k in range(i, j):
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j] = k
    return m, s


def print_optimal_parens(s, i, j):
    if i == j:
        print("A_{}".format(i), end='')
    else:
        print("(", end='')
        print_optimal_parens(s, i, s[i][j])
        print_optimal_parens(s, s[i][j]+1, j)
        print(")", end='')


# Driver program to test above function
arr = [1, 2, 3, 4, 3]
m, s = matrix_chain_order(arr)
print("Min multipications: {}".format(m[1][len(arr)-1]))
print_optimal_parens(s, 1, len(arr)-1)
