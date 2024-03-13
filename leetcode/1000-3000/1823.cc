#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int findTheWinner(int n, int k) {
    function<int(int, int)> chaewon = [&](int n, int k) {
      if (n == 1) return 0;
      return (chaewon(n - 1, k) + k) % n;
    };
    return chaewon(n, k) + 1;
  }
};
int main() { return 0; }