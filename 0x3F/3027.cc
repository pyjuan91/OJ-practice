#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numberOfPairs(vector<vector<int>>& points) {
    map<int, vector<int>> mp;
    for (const auto& point : points) {
      int x = point[0], y = -point[1];
      mp[x].push_back(y);
    }
    for (auto& [k, v] : mp) {
      sort(v.begin(), v.end());
    }
    int res = 0;

    for (auto iter1 = mp.begin(); iter1 != mp.end(); iter1++) {
      int x = iter1->first;
      for (const int& y : iter1->second) {
        bool first = true;
        int cur_y = y;
        for (auto iter2 = iter1; iter2 != mp.end(); iter2++) {
          if (first) {
            auto iter2_y = (iter2 == iter1)
                               ? upper_bound(iter2->second.begin(),
                                             iter2->second.end(), cur_y)
                               : lower_bound(iter2->second.begin(),
                                             iter2->second.end(), cur_y);

            if (iter2_y != iter2->second.end()) {
              cur_y = *iter2_y;
              res++;
              first = false;
            }
          } else {
            auto iter2_y =
                lower_bound(iter2->second.begin(), iter2->second.end(), y);
            if (iter2_y != iter2->second.end() and *iter2_y < cur_y) {
              cur_y = *iter2_y;
              res++;
            }
          }
        }
      }
    }

    return res;
  }
};

int main() { return 0; }