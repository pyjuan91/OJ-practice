#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int32_t N, M;
  string S, T;
  cin >> N >> M >> S >> T;
  vector<int32_t> cnt(10, 0);
  for (const char& c : T) cnt[c - '0']++;
  int32_t cur_considered = 9;
  for (auto& c : S) {
    int32_t d = c - '0';
    while (cnt[cur_considered] == 0) cur_considered--;
    if (cur_considered == 0) break;
    if (d < cur_considered) cnt[cur_considered]--, c = cur_considered + '0';
  }
  if (count(S.begin(), S.end(), T.back()) == 0) S.back() = T.back();
  cout << S << '\n';
  return 0;
}
