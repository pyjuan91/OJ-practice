#include <bits/stdc++.h>
using namespace std;
int main() { return 0; };
class Solution {
 public:
  double myPow(double x, int n) {
    double res = 1;
    if (n == 0) return 1;
    int m = abs(n);
    while (n) {
      if (n & 1) res *= x;
      x *= x;
      n >>= 1;
    }
    return n > 0 ? res : 1 / res;
  }
};