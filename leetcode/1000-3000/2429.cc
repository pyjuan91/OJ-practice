#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimizeXor(int num1, int num2) {
    int cnt = __popcount(num2);
    int res = 0;
    for (int i = 31; i >= 0; i--) {
      if (num1 & (1 << i)) {
        if (cnt > 0) {
          res |= (1 << i);
          cnt--;
        }
      }
    }
    int idx = 0;
    while (cnt > 0) {
      if (!(num1 & (1 << idx))) {
        res |= (1 << idx);
        cnt--;
      }
      idx++;
    }
    return res;
  }
};

int main() {
  return 0;
}