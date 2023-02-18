#include <bits/stdc++.h>
using namespace std;
void init(vector<string> s, map<string, int>& m) {
  for (auto i : s) m[i] = 0;
}
int main() {
  freopen("notlast.in", "r", stdin);
  freopen("notlast.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie();
  vector<string> s = {"Bessie",    "Elsie",  "Daisy",    "Gertie",
                      "Annabelle", "Maggie", "Henrietta"};
  int n;
  cin >> n;
  if (n == 0) {
    cout << "Tie\n";
    return 0;
  }
  map<string, int> m;
  init(s, m);
  string name;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> name >> x;
    m[name] += x;
  }
  map<int, vector<string>> chaewon;
  for (auto i : m) chaewon[i.second].emplace_back(i.first);
  auto iter = chaewon.begin();
  if (iter->second.size() == 7)
    cout << "Tie\n";
  else {
    iter++;
    if (iter->second.size() > 1)
      cout << "Tie\n";
    else
      cout << iter->second[0] << "\n";
  }
  return 0;
}