#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

int kazuha(int a, int b) {
  if (a > b) swap(a, b);
  if (b >= 2 * a) return b / 2 + b % 2;
  return (a + b) / 3 + ((a + b) % 3 > 0);
}

int chaewon(int n, vector<int>& a) {
  multiset<int> ms(a.begin(), a.end());
  int res = INT64_MAX;
  // debug(ms);
  for (int i = 1; i <= n; i++) {
    array<int, 3> arr = {a[i - 1], a[i], a[i + 1]};
    array<int, 3> time_required = {a[i - 1], a[i] / 2 + a[i] % 2, a[i + 1]};
    ms.erase(ms.find(a[i - 1]));
    ms.erase(ms.find(a[i]));
    ms.erase(ms.find(a[i + 1]));
    int min_time = *min_element(time_required.begin(), time_required.end());

    array<int, 3> new_arr = {arr[0] - min_time, max(0LL, arr[1] - 2 * min_time),
                             arr[2] - min_time};
    ms.insert(new_arr[0]), ms.insert(new_arr[1]), ms.insert(new_arr[2]);
    int second = *next(ms.begin());
    res = min(res, second / 2 + second % 2 + min_time);
    ms.erase(ms.find(new_arr[0]));
    ms.erase(ms.find(new_arr[1]));
    ms.erase(ms.find(new_arr[2]));

    ms.insert(arr[0]), ms.insert(arr[1]), ms.insert(arr[2]);

    if (i == n) break;
    res = min(res, kazuha(a[i], a[i + 1]));
  }
  return res;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n + 2, INT32_MAX);
  for (int i = 1; i <= n; i++) cin >> a[i];
  cout << chaewon(n, a) << '\n';
  return 0;
}
