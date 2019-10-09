#include <iostream>
#include <limits>
#include <utility>
#include <vector>
#include <string>

void solution(std::vector<std::vector>&brackets, std::string& s, char& name, int start, int end){
    if(start==end){
        s.push_back(name++);
        return;
    }
    s.push_back('(');
    solution(brackets, s, name, start, brackets[start][end]);
    solution(brackets, s, name, brackets[start][end]+1, end);
    s.push_back(')');
}

std::pair<int, std::string> matrixChainOrder(std::vector<int>&dims){
    ssize_t n = dims.size();
    std::vector<std::vector<int>> m(n, std::vector<int>(n)), brackets(n, std::vector<int>(n));
    for(int i = 1;i < n;i++)
    m[i][i] = brackets[i][i] = 0;
    for(int l = 2;l < n;l++){
        for(int i = 1;i < n-l+1;i++){
            int j = i+l-1;
            m[i][j] = std::numeric_limits<int>::max();
            for(int k = i;k < j;k++){
                int x = m[i][k] + m[k+1][j] + dims[i-1]*dims[k]*dims[j];
                if(x < m[i][j]){
                    m[i][j] = x;
                    brackets[i][j] = k;
                }
            }
        }
    }
    std::string s;
    char name = 'A';
    solution(brackets, s, name, 1, n-1);
    std::pair<std::string, int> res(m[1][n-1], s);
    return res;
}

int main(){
    ssize_t n;
    std::cin >> n;
    std::vector<int> dims;
    for(auto &x : dims)
    std::cin >> x;
    std::pair<std::string, int> res(matrixChainOrder(dims));
    std::cout << "Minimum number of multiplications = " << res.first << std::endl;
    std::cout << "Solution Matrix : " << res.second << std::endl;
}