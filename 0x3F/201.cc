#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int rangeBitwiseAnd(int left, int right) {
    int res = left;
    for (int i = 0; i < 31; i++) {
      if (!(left & (1 << i))) continue;
      if (right > (left | ((1LL << (i + 1)) - 1))) res ^= (1 << i);
    }
    return res;
  }
};

int main() { return 0; }