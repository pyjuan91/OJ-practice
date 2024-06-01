#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "../../debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
using namespace std;
class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    struct Event {
      int x, h;
      bool is_start;
      Event(int x, int h, bool is_start) : x(x), h(h), is_start(is_start) {}
      bool operator<(const Event& other) const {
        if (x != other.x) return x < other.x;
        if (is_start != other.is_start) return is_start;
        return is_start ? h > other.h : h < other.h;
      }
      bool operator==(const Event& other) const {
        return x == other.x && h == other.h && is_start == other.is_start;
      }
    };
    vector<Event> events;
    for (auto& building : buildings) {
      events.emplace_back(building[0], building[2], true);
      events.emplace_back(building[1], building[2], false);
    }
    sort(events.begin(), events.end());
    vector<vector<int>> ans;
    multiset<int> heights = {0};
    for (auto& event : events) {
      if (event.is_start) {
        if (event.h > *heights.rbegin()) {
          ans.push_back({event.x, event.h});
        }
        heights.insert(event.h);
      } else {
        heights.erase(heights.find(event.h));
        if (event.h > *heights.rbegin()) {
          ans.push_back({event.x, *heights.rbegin()});
        }
      }
    }
    return ans;
  }
};
int main() {
  Solution s;
  vector<vector<int>> buildings = {{5, 15, 20}, {10, 15, 20}, {20, 25, 5}};
  vector<vector<int>> ans = s.getSkyline(buildings);
  for (auto x : ans) {
    for (auto y : x) {
      cout << y << " ";
    }
    cout << endl;
  }
  return 0;
}