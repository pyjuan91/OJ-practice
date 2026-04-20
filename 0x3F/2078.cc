#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxDistance(vector<int>& colors) {
    unordered_map<int, pair<int, int>> pos;
    for (int i = 0; i < colors.size(); i++) {
      if (!pos.count(colors[i])) {
        pos[colors[i]] = make_pair(INT32_MAX, 0);
      }
      pos[colors[i]].first = min(pos[colors[i]].first, i);
      pos[colors[i]].second = max(pos[colors[i]].second, i);
    }
    int res = 0;
    for (auto iter1 = pos.begin(); iter1 != pos.end(); iter1++) {
      for (auto iter2 = next(iter1); iter2 != pos.end(); iter2++) {
        auto [a1, a2] = iter1->second;
        auto [b1, b2] = iter2->second;
        res = max({res, a2 - b1, b2 - a1});
      }
    }
    return res;
  }
};

int main() { return 0; }