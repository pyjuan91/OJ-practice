#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestBalanced(vector<int>& nums) {
    int n = nums.size();
    // Segment tree: range add, track min/max, find leftmost zero
    vector<int> mn(4 * n, 0), mx(4 * n, 0), lazy(4 * n, 0);

    auto push = [&](int node) {
      if (lazy[node]) {
        for (int c : {2 * node, 2 * node + 1}) {
          mn[c] += lazy[node];
          mx[c] += lazy[node];
          lazy[c] += lazy[node];
        }
        lazy[node] = 0;
      }
    };

    auto update =
        [&](this auto& self, int node, int s, int e, int l, int r, int val) {
          if (s > r || e < l) return;
          if (s >= l && e <= r) {
            mn[node] += val;
            mx[node] += val;
            lazy[node] += val;
            return;
          }
          push(node);
          int mid = (s + e) / 2;
          self(2 * node, s, mid, l, r, val);
          self(2 * node + 1, mid + 1, e, l, r, val);
          mn[node] = min(mn[2 * node], mn[2 * node + 1]);
          mx[node] = max(mx[2 * node], mx[2 * node + 1]);
        };

    // Find leftmost index in [l, r] where balance == 0
    auto findLeftmostZero =
        [&](this auto& self, int node, int s, int e, int l, int r) -> int {
      // Prune: no zero possible if all values > 0 or all values < 0
      if (s > r || e < l || mn[node] > 0 || mx[node] < 0) return -1;
      if (s == e) return (mn[node] == 0) ? s : -1;
      push(node);
      int mid = (s + e) / 2;
      int left = self(2 * node, s, mid, l, r);
      if (left != -1) return left;
      return self(2 * node + 1, mid + 1, e, l, r);
    };

    unordered_map<int, int> prev;
    int ans = 0;

    for (int r = 0; r < n; r++) {
      int v = nums[r];
      int p = prev.count(v) ? prev[v] : -1;
      int delta = (v % 2 == 0) ? 1 : -1;

      update(1, 0, n - 1, p + 1, r, delta);
      prev[v] = r;

      int l = findLeftmostZero(1, 0, n - 1, 0, r);
      if (l != -1) ans = max(ans, r - l + 1);
    }

    return ans;
  }
};

int main() { return 0; }