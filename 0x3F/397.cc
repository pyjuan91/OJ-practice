#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int integerReplacement(int N) {
    int res = 0;
    int64_t n = N;
    while (n > 1) {
      if ((n & 1) == 0) {
        n >>= 1;
      } else if (n == 3 or (n & 2) == 0) {
        n--;
      } else {
        n++;
      }
      res++;
    }
    return res;
  }
};

int main() { return 0; }