#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  freopen("lineup.in", "r", stdin);
  freopen("lineup.out", "w", stdout);
  int n;
  string na;
  cin >> n;
  vector<vector<string>> rules(n, vector<string>(2));
  vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice",
                         "Bella",  "Blue",      "Betsy",   "Sue"};
  sort(cows.begin(), cows.end());
  for (int i = 0; i < n; i++) {
    cin >> rules[i][0];
    for (int j = 0; j < 4; j++) cin >> na;
    cin >> rules[i][1];
  }
  do {
    map<string, int> position;
    for (int i = 0; i < 8; i++) position[cows[i]] = i;
    bool ans = true;
    for (int i = 0; i < n; i++) {
      if (abs(position[rules[i][0]] - position[rules[i][1]]) > 1) ans = false;
    }
    if (ans) {
      for (auto cow : cows) cout << cow << "\n";
      return 0;
    }
  } while (next_permutation(cows.begin(), cows.end()));
  return 0;
}