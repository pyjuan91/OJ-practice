#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int binaryGap(int n) {
    vector<int> pos;
    for (int i = 0; i < 32; i++) {
      if (n & (1 << i)) pos.push_back(i);
    }
    int res = 0;
    for (int i = 1; i < pos.size(); i++) {
      res = max(res, pos[i] - pos[i - 1]);
    }
    return res;
  }
};

int main() { return 0; }