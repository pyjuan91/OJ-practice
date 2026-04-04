#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findNumbers(vector<int>& nums) {
    int res = 0;
    for (const auto& num : nums) {
      string s = to_string(num);
      if (s.size() % 2 == 0) res++;
    }
    return res;
  }
};

int main() { return 0; }