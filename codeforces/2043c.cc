#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, x, mid;
  cin >> t;
  while (t--) {
    cin >> n;
    mid = INT64_MIN;
    vector<int> left, right = {0};
    for (int i = 0; i < n; i++) {
      cin >> x;
      if (x == -1 or x == 1) {
        if (mid == INT64_MIN)
          left.push_back(x);
        else
          right.push_back(x);
      } else {
        mid = x;
      }
    }
    left.push_back(0);
    reverse(left.begin(), left.end());

    if (mid == INT64_MIN) {
      int left_min_any_time = 0, left_max_any_time = 0;
      int left_min_cur = 0, left_max_cur = 0;
      for (int i = 1; i < left.size(); i++) {
        left_min_cur = min(left_min_cur + left[i], 0LL);
        left_max_cur = max(left_max_cur + left[i], 0LL);
        left_min_any_time = min(left_min_any_time, left_min_cur);
        left_max_any_time = max(left_max_any_time, left_max_cur);
      }
      cout << left_max_any_time - left_min_any_time + 1 << "\n";
      for (int i = left_min_any_time; i <= left_max_any_time; i++) {
        cout << i << " ";
      }
      cout << "\n";
      continue;
    }

    int left_min_whole_time = 0, right_min_whole_time = 0;
    int left_max_whole_time = 0, right_max_whole_time = 0;
    int left_min_any_time = 0, left_max_any_time = 0;
    int right_min_any_time = 0, right_max_any_time = 0;
    int left_min_cur = 0, left_max_cur = 0;
    int right_min_cur = 0, right_max_cur = 0;
    for (int i = 1; i < left.size(); i++) {
      debug(left[i]);
      left_min_cur = min(left_min_cur + left[i], 0LL);
      left_max_cur = max(left_max_cur + left[i], 0LL);
      left_min_any_time = min(left_min_any_time, left_min_cur);
      left_max_any_time = max(left_max_any_time, left_max_cur);
      left[i] += left[i - 1];
      left_min_whole_time = min(left_min_whole_time, left[i]);
      left_max_whole_time = max(left_max_whole_time, left[i]);
    }
    for (int i = 1; i < right.size(); i++) {
      right_min_cur = min(right_min_cur + right[i], 0LL);
      right_max_cur = max(right_max_cur + right[i], 0LL);
      right_min_any_time = min(right_min_any_time, right_min_cur);
      right_max_any_time = max(right_max_any_time, right_max_cur);
      right[i] += right[i - 1];
      right_min_whole_time = min(right_min_whole_time, right[i]);
      right_max_whole_time = max(right_max_whole_time, right[i]);
    }
    // debug(left, right);
    debug(left_min_any_time, left_max_any_time);
    debug(right_min_any_time, right_max_any_time);
    set<int> res;
    for (int i = left_min_any_time; i <= left_max_any_time; i++) {
      res.insert(i);
    }
    for (int i = right_min_any_time; i <= right_max_any_time; i++) {
      res.insert(i);
    }
    debug(res);
    int x_min = left_min_whole_time + right_min_whole_time + mid;
    int x_max = left_max_whole_time + right_max_whole_time + mid;
    debug(x_min, x_max);
    for (int i = x_min; i <= x_max; i++) {
      res.insert(i);
    }
    cout << res.size() << "\n";
    for (auto it = res.begin(); it != res.end(); it++) {
      cout << *it << " ";
    }
    cout << "\n";
  }
  return 0;
}
