#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestBalanced(string s) {
    const int n = s.size();
    vector<vector<int>> prefix(3, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
      prefix[s[i] - 'a'][i + 1]++;
      for (int j = 0; j < 3; j++) prefix[j][i + 1] += prefix[j][i];
    }
    int res = 1;
    // find only one kind of char
    int idx = 0, cnt = 1;
    while (idx < n) {
      while (idx + 1 < n and s[idx + 1] == s[idx]) {
        idx++;
        cnt++;
      }
      res = max(res, cnt);
      cnt = 1;
      idx++;
    }
    // cout << res << "\n";
    // find only two kind of char
    auto patty1 = [&](int same_1, int same_2, int zero_3) {
      map<pair<int, int>, int> pos;
      pos[{0, 0}] = 0;
      for (int i = 1; i <= n; i++) {
        pair<int, int> cur =
            make_pair(prefix[same_1][i] - prefix[same_2][i],
            prefix[zero_3][i]);
        // cout << cur.first << " " << cur.second << "\n";
        if (pos.count(cur)) {
          res = max(res, i - pos[cur]);
        } else {
          pos[cur] = i;
        }
      }
    };
    patty1(0, 1, 2);
    patty1(1, 2, 0);
    patty1(0, 2, 1);
    // find three char
    map<pair<int, int>, int> pos;
    pos[{0, 0}] = 0;
    for (int i = 1; i <= n; i++) {
      pair<int, int> cur =
          make_pair(prefix[0][i] - prefix[1][i], prefix[1][i] -
          prefix[2][i]);
      if (pos.count(cur)) {
        res = max(res, i - pos[cur]);
      } else {
        pos[cur] = i;
      }
    }
    return res;
  }
};

int main() {
  auto s = new Solution;
  cout << s->longestBalanced("abbac");
  return 0;
}