#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int reverseDegree(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        res += (i + 1) * (26 - s[i] + 'a');
    }
    return res;
  }
};

int main() { return 0; }