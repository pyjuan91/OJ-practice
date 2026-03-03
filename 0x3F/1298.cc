#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxCandies(vector<int>& status, vector<int>& candies,
                 vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
                 vector<int>& initialBoxes) {
    const int n = status.size();
    deque<int> dq;
    unordered_set<int> owned_keys;
    unordered_set<int> owned_boxes;

    auto distribute_box = [&](int box) -> void {
      if (status[box] or owned_keys.count(box)) {
        dq.push_back(box);
      } else {
        owned_boxes.insert(box);
      }
    };

    auto check_keys_useful = [&](int key) -> void {
      if (owned_boxes.count(key)) {
        dq.push_back(key);
        owned_boxes.erase(key);
      }
    };

    for (const auto& box : initialBoxes) {
      distribute_box(box);
    }

    int res = 0;
    while (!dq.empty()) {
      auto cur_box = dq.front();
      dq.pop_front();
      res += candies[cur_box];
      for (const auto& key : keys[cur_box]) {
        owned_keys.insert(key);
        check_keys_useful(key);
      }
      for (const auto& box : containedBoxes[cur_box]) {
        distribute_box(box);
      }
    }

    return res;
  }
};
int main() { return 0; }