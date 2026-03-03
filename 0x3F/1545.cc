#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  char findKthBit(int n, int k) {
    // S1 -> 2 ^ 0 -> 2 ^ 1 - 1
    // S2 -> 2 ^ 1 + 2 ^ 0 -> 2 ^ 2 - 1
    // S3 -> 2 ^ 2 + 2 ^ 1 + 2 ^ 0 -> 2 ^ 3 - 1
    auto patty = [&](this auto&& self, int n, int k) -> bool {
      if (n == 1) return false;
      int clen = (1 << n) - 1;
      if (k == clen / 2 + 1) return true;
      if (k < clen / 2 + 1) return self(n - 1, k);
      // k > clen / 2 + 1
      return !self(n - 1, clen - k + 1);
    };
    return patty(n, k) ? '1' : '0';
  }
};

int main() { return 0; }