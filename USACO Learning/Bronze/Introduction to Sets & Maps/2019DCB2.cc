#include <bits/stdc++.h>
using namespace std;
bool check(int mid, string str, int n) {
  set<string> s;
  for (int i = 0; i <= n - mid; i++) {
    string neo = str.substr(i, mid);
    if (s.find(neo) != s.end()) return false;
    s.insert(neo);
  }
  return true;
}
int main() {
  freopen("whereami.in", "r", stdin);
  freopen("whereami.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie();
  int n;
  cin >> n;
  string str;
  cin >> str;
  int left = 1, right = n;
  while (left + 1 < right) {
    int mid = left + (right - left) / 2;
    if (check(mid, str, n))
      right = mid;
    else
      left = mid;
  }
  cout << right << endl;
  return 0;
}