#include <bits/stdc++.h>
using namespace std;

class Allocator {
 public:
  Allocator(int n) { free_memory_.insert(make_pair(0, n)); }

  int allocate(int size, int mID) {
    for (auto it = free_memory_.begin(); it != free_memory_.end(); it++) {
      if (it->second - it->first >= size) {
        int res = it->first;
        if (it->second - it->first == size) {
          records_[mID].push_back(*it);
          free_memory_.erase(it);
        } else {
          pair<int, int> allocated_section =
              make_pair(it->first, it->first + size);
          pair<int, int> remaining_section =
              make_pair(it->first + size, it->second);
          records_[mID].push_back(allocated_section);
          free_memory_.erase(it);
          free_memory_.insert(remaining_section);
        }
        return res;
      }
    }
    return -1;
  }

  int freeMemory(int mID) {
    int free_units = 0;
    for (const auto& p : records_[mID]) {
      free_units += p.second - p.first;
      insert_intervals(p);
    }
    records_.erase(mID);
    return free_units;
  }

 private:
  set<pair<int, int>> free_memory_;
  unordered_map<int, vector<pair<int, int>>> records_;

  void insert_intervals(pair<int, int> interval) {
    auto it = free_memory_.lower_bound(interval);

    if (it != free_memory_.end() and it->first == interval.second) {
      interval.second = it->second;
      it = free_memory_.erase(it);
    }
    if (it != free_memory_.begin() and prev(it)->second == interval.first) {
      interval.first = prev(it)->first;
      free_memory_.erase(prev(it));
    }
    free_memory_.insert(interval);
  }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
