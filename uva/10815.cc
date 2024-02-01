#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  set<string> res;
  string s;
  while (cin >> s) {
    string pros;
    int id = 0;
    while (id < s.size()) {
      if (!isalpha(s[id])) {
        if (!pros.empty()) res.insert(pros);
        pros.clear();
      } else
        pros.push_back(tolower(s[id]));
      id++;
    }
    if (!pros.empty()) res.insert(pros);
  }
  for (const auto& s : res) cout << s << "\n";
  return 0;
}
