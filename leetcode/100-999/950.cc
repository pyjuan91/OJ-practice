#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> deckRevealedIncreasing(vector<int>& deck) {
    int n = deck.size();
    queue<int> q;
    for (int i = 0; i < n; i++) q.push(i);
    vector<int> res;
    while (q.size() > 1) {
      res.push_back(q.front());
      q.pop();
      q.push(q.front());
      q.pop();
    }
    if (!q.empty()) res.push_back(q.front());
    for (auto x : res) cout << x << " ";
    cout << endl;
    map<int, int> m;
    for (auto x : deck) m[x] = 0;
    int cnt = 0;
    for (auto& x : m) x.second = cnt++;
    map<int, int> m2;
    for (auto x : m) m2[x.second] = x.first;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      ans[res[i]] = m2[i];
    }
    return ans;
  }
};
int main() {
  vector<int> deck = {17, 13, 11, 2, 3, 5, 7};
  Solution s;
  auto v = s.deckRevealedIncreasing(deck);
  for (auto x : v) cout << x << " ";
  cout << endl;
  return 0;
}