#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

using namespace std;

class Solution {
public:
  vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    int n = nums.size();
    set<pair<int, int>> nodes;
    for (int i = 0; i < n; i++) {
      nodes.insert({ nums[i], i });
    }
    auto dsu = atcoder::dsu(n);
    for (auto it = ++(nodes.begin()), prv = nodes.begin(); it != nodes.end(); it++) {
      if (it->first - prv->first <= limit) {
        dsu.merge(prv->second, it->second);
      }
      prv = it;
    }
    auto groups = dsu.groups();
    for (auto& group : groups) {
      vector<int> arr;
      for (auto& x : group) {
        arr.push_back(nums[x]);
      }
      sort(arr.begin(), arr.end());
      for (int i = 0; i < group.size(); i++) {
        nums[group[i]] = arr[i];
      }
    }
    return nums;
  }
};

int main() {
  int n, limit;
  cin >> n >> limit;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) cin >> nums[i];
  Solution sol;
  auto ans = sol.lexicographicallySmallestArray(nums, limit);
  for (auto& x : ans) cout << x << " ";
  return 0;
}
