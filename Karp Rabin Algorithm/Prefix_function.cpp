#include<bits/stdc++.h>
using namespace std;
vector<int> prefix_function(const string &s) {
  vector<int> pi((int)s.size()); 
  for(int i = 1;i < (int)s.size();i++) {
    int j = pi[i - 1]; 
    while(j and s[i] != s[j]) {
      j = pi[j - 1]; 
    }
    pi[i] = j + (s[i] == s[j]); 
  }
  return pi;
}
void solve() {
  string s; 
  cin >> s; 
  vector<int> match = prefix_function(s); 
  for(auto &i: match) {
    cout << i << ' ';
  }
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  solve();
}
