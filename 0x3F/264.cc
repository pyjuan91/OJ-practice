#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  static inline vector<int> chaewon = []() {
    set<int64_t> s;
    for (int64_t base_2 = 1; base_2 < INT32_MAX; base_2 *= 2) {
      for (int64_t base_3 = 1; base_2 * base_3 < INT32_MAX; base_3 *= 3) {
        for (int64_t base_5 = 1; base_2 * base_3 * base_5 < INT32_MAX;
             base_5 *= 5) {
          s.insert(base_2 * base_3 * base_5);
        }
      }
    }
    vector<int> res;
    for (const auto& x : s) {
      res.push_back(static_cast<int>(x));
      if (res.size() == 1690) break;
    }
    return res;
  }();

 public:
  int nthUglyNumber(int n) { return chaewon[n - 1]; }
};

int main() { return 0; }