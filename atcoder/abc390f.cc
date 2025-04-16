#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> pos(n);
  vector<vector<int>> index(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> pos[i];
    index[pos[i] - 1].push_back(i);
  }

  auto zuha = [](const vector<int>& arr) -> int64_t {
    int64_t res = 0;
    int n = arr.size();
    for (int i = 1; i < n; i++) {
      int64_t diff = arr[i] - arr[i - 1];
      res += diff * (diff - 1) / 2;
    }
    return res;
  };

  int64_t res = 0;
  for (int c = 1; c <= n; c++) {
    vector<int> v1 = {-1};
    for (const auto& i : index[c]) {
      v1.push_back(i);
    }
    v1.push_back(n);

    vector<int> v2 = {-1};
    {
      const auto& i = index[c];
      const auto& j = index[c - 1];
      auto it1 = i.begin(), it2 = j.begin();
      while (it1 != i.end() and it2 != j.end()) {
        if (*it1 < *it2) {
          v2.push_back(*it1);
          it1++;
        } else {
          v2.push_back(*it2);
          it2++;
        }
      }
      while (it1 != i.end()) {
        v2.push_back(*it1);
        it1++;
      }
      while (it2 != j.end()) {
        v2.push_back(*it2);
        it2++;
      }
    }
    v2.push_back(n);

    res += zuha(v1) - zuha(v2);
  }
  cout << res << '\n';
  return 0;
}
