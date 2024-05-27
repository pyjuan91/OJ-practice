#include <bits/stdc++.h>
using namespace std;

struct SegmentTreeNode {
  int left_index, right_index;
  int64_t subsegment_sum[2][2];
  SegmentTreeNode() {
    left_index = right_index = 0;
    subsegment_sum[0][0] = subsegment_sum[0][1] = subsegment_sum[1][0] =
        subsegment_sum[1][1] = 0;
  }
  SegmentTreeNode(int left_index, int right_index,
                  int64_t subsegment_sum[2][2]) {
    this->left_index = left_index;
    this->right_index = right_index;
    this->subsegment_sum[0][0] = subsegment_sum[0][0];
    this->subsegment_sum[0][1] = subsegment_sum[0][1];
    this->subsegment_sum[1][0] = subsegment_sum[1][0];
    this->subsegment_sum[1][1] = subsegment_sum[1][1];
  }
  SegmentTreeNode operator+(const SegmentTreeNode& other) const {
    SegmentTreeNode result;
    result.left_index = left_index;
    result.right_index = other.right_index;
    result.subsegment_sum[0][0] =
        max({subsegment_sum[0][0] + other.subsegment_sum[0][0],
             subsegment_sum[0][1] + other.subsegment_sum[0][0],
             subsegment_sum[0][0] + other.subsegment_sum[1][0]});
    result.subsegment_sum[0][1] =
        max({result.subsegment_sum[0][0],
             subsegment_sum[0][1] + other.subsegment_sum[0][1],
             subsegment_sum[0][0] + other.subsegment_sum[1][1],
             subsegment_sum[0][0], other.subsegment_sum[0][1]});
    result.subsegment_sum[1][0] =
        max({result.subsegment_sum[0][0],
             subsegment_sum[1][0] + other.subsegment_sum[0][0],
             subsegment_sum[1][1] + other.subsegment_sum[0][0],
             subsegment_sum[1][0] + other.subsegment_sum[1][0]});
    result.subsegment_sum[1][1] =
        max({result.subsegment_sum[0][0], result.subsegment_sum[0][1],
             result.subsegment_sum[1][0],
             subsegment_sum[1][1] + other.subsegment_sum[0][1],
             subsegment_sum[1][0] + other.subsegment_sum[1][1],
             subsegment_sum[1][0] + other.subsegment_sum[0][1]});
    return result;
  }
};

template <typename T>
class SegmentTree {
 private:
  std::vector<T> tree;
  int n;

  void build(int node, int start, int end, const std::vector<T>& arr) {
    if (start == end) {
      tree[node] = arr[start];
    } else {
      int mid = (start + end) / 2;
      build(2 * node, start, mid, arr);
      build(2 * node + 1, mid + 1, end, arr);
      tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
  }

  void update(int node, int start, int end, int idx, T val) {
    if (start == end) {
      // Leaf node
      tree[node] = val;
    } else {
      int mid = (start + end) / 2;
      if (start <= idx && idx <= mid) {
        // If idx is in the left child, recurse on the left child
        update(2 * node, start, mid, idx, val);
      } else {
        // If idx is in the right child, recurse on the right child
        update(2 * node + 1, mid + 1, end, idx, val);
      }
      // Internal node will have the sum of both of its children
      tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
  }

  T query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
      // range represented by a node is completely outside the given range
      return T();
    }
    if (l <= start && end <= r) {
      // range represented by a node is completely inside the given range
      return tree[node];
    }
    // range represented by a node is partially inside and partially outside the
    // given range
    int mid = (start + end) / 2;
    T p1 = query(2 * node, start, mid, l, r);
    T p2 = query(2 * node + 1, mid + 1, end, l, r);
    return p1 + p2;
  }

 public:
  SegmentTree(const std::vector<T>& arr) {
    n = arr.size();
    tree.resize(4 * n);
    build(1, 0, n - 1, arr);
  }

  void update(int idx, T val) { update(1, 0, n - 1, idx, val); }

  T query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

class Solution {
 public:
  int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    vector<SegmentTreeNode> arr(n);
    for (int i = 0; i < n; i++) {
      int64_t subsegment_sum[2][2] = {{0, 0}, {0, nums[i]}};
      arr[i] = SegmentTreeNode(i, i, subsegment_sum);
    }
    SegmentTree<SegmentTreeNode> st(arr);
    int64_t result = 0;
    const int64_t kMod = 1e9 + 7;
    for (const auto& query : queries) {
      int pos = query[0], val = query[1];
      int64_t subsegment_sum[2][2] = {{0, 0}, {0, val}};
      st.update(pos, SegmentTreeNode(pos, pos, subsegment_sum));
      auto node = st.query(0, n - 1);
      int64_t max_sum =
          max({node.subsegment_sum[0][0], node.subsegment_sum[0][1],
               node.subsegment_sum[1][0], node.subsegment_sum[1][1]});
      result = (result + max_sum) % kMod;
    }
    return (int)result;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> nums(n);
  vector<vector<int>> queries(m, vector<int>(2));
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> queries[i][0] >> queries[i][1];
  }
  Solution sol;
  cout << sol.maximumSumSubsequence(nums, queries) << endl;
}