#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ifstream cin("measurement.in");
  ofstream cout("measurement.out");
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, g;
  cin >> n >> g;
  int res = 0;
  string op;
  struct Cow {
    int day, id, change;
    Cow() {}
  };
  vector<Cow> cows(n);
  set<pair<int, int>> ordered_cows;
  ordered_cows.insert({g, 0});
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> cows[i].day >> cows[i].id >> op;
    if (op[0] == '+')
      cows[i].change = stoi(op.substr(1));
    else
      cows[i].change = -stoi(op.substr(1));
    ordered_cows.insert({g, cows[i].id});
    mp[cows[i].id] = g;
  }
  sort(cows.begin(), cows.end(), [](Cow a, Cow b) { return a.day < b.day; });

  for (const auto& cow : cows) {
    if (cow.change == 0) continue;
    // if is only cow with max value
    bool only_max =
        (ordered_cows.rbegin()->second == cow.id &&
         (++ordered_cows.rbegin())->first != ordered_cows.rbegin()->first);
    bool multi_max = (ordered_cows.rbegin()->first == mp[cow.id]);
    if (only_max) {
      ordered_cows.erase({mp[cow.id], cow.id});
      mp[cow.id] += cow.change;
      if (mp[cow.id] <= ordered_cows.rbegin()->first) {
        res++;
      }
      ordered_cows.insert({mp[cow.id], cow.id});
    } else if (multi_max) {
      ordered_cows.erase({mp[cow.id], cow.id});
      mp[cow.id] += cow.change;
      res++;
      ordered_cows.insert({mp[cow.id], cow.id});
    } else {
      ordered_cows.erase({mp[cow.id], cow.id});
      mp[cow.id] += cow.change;
      if (mp[cow.id] >= ordered_cows.rbegin()->first) {
        res++;
      }
      ordered_cows.insert({mp[cow.id], cow.id});
    }
  }
  cout << res << '\n';
  return 0;
}
