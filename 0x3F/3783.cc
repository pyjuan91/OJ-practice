#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int mirrorDistance(int n) {
    auto rev = [&](int x) -> int {
      string str_num = to_string(x);
      reverse(str_num.begin(), str_num.end());
      return stoi(str_num);
    };
    return abs(n - rev(n));
  }
};

int main() { return 0; }