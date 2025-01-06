#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
using namespace std;

class Solution {
public:
  vector<int> minOperations(string boxes) {
    size_t n = boxes.size();
    vector<int> pre_one(n, 0), suf_one(n, 0);
    pre_one[0] = boxes[0] - '0', suf_one[n - 1] = boxes[n - 1] - '0';
    for (size_t i = 1; i < n; i++) {
      pre_one[i] = pre_one[i - 1] + boxes[i] - '0';
      suf_one[n - i - 1] = suf_one[n - i] + boxes[n - i - 1] - '0';
    }

    vector<int> pre_effort(n, 0), suf_effort(n, 0);
    for (size_t i = 1; i < n; i++) {
      pre_effort[i] = pre_effort[i - 1] + pre_one[i - 1];
      suf_effort[n - i - 1] = suf_effort[n - i] + suf_one[n - i];
    }

    vector<int> ans(n, 0);
    for (size_t i = 0; i < n; i++) {
      ans[i] = pre_effort[i] + suf_effort[i];
    }
    return ans;
  }
};

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  Solution* obj = new Solution();
  vector<int> ans = obj->minOperations(s);
  for (auto i : ans) {
    cout << i << " ";
  }
  return 0;
}