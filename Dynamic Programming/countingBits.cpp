/*
Given a non negative integer number n. For every numbers i in the range 0 ≤ i ≤ n calculate the number of 1's in their binary representation and return them as an array.
example input: 5
expected result: {0, 1, 1, 2, 1, 2}
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> countingBits(int n) {
  
  vector<int> ans(n + 1);

  ans[0] = 0;

  if (n >= 1)
    ans[1] = 1;

  int curr = 2;
  int nearest = 2;
  while (curr <= n)
  {
    nearest = (n & (n - 1)) == 0 ? curr : nearest;
    ans[curr] = 1 + ans[curr - nearest];
    curr++;
  }

  return ans;
}