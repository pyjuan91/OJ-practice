#include <bits/stdc++.h>
using namespace std;
int go(int n, string s) {
  vector<int> pos;
  for (int i = 0; i < n; i++)
    if (s[i] == '1') pos.emplace_back(i);
  if (pos.size() == 0) return 0;
  if (pos.size() % 2) return -1;
  vector<int> head, tail;
  for (int i = 0; i < pos.size() / 2; i++) {
    head.emplace_back(pos[i]);
    tail.emplace_back(pos[i + pos.size() / 2]);
  }
  int res = 0;
  if (head[0] + 1 == tail[0]) {
    if (n < 4) return -1;
    if (n == 4) {
      if (head[0] == 1 && tail[0] == 2) return 3;
      return 2;
    }
    return head.size() + 1;
  }
  return head.size();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  int t, n;
  string s;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    cout << go(n, s) << "\n";
  }
  return 0;
}