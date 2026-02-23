#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int trailingZeroes(int n) {
    int fives = 0;
    for (int base = 5; base <= n; base *= 5) {
      fives += n / base;
    }
    return fives;
  }
};

int main() { return 0; }