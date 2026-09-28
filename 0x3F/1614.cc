#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxDepth(string s) {
    int depth = 0, res = 0;

    for (const auto& c : s) {
      if (c == '(') {
        depth++;
      } else if (c == ')') {
        depth--;
      }
      res = max(res, depth);
    }

    return res;
  }
};

int main() { return 0; }