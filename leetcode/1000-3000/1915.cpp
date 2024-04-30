#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long wonderfulSubstrings(string word) {
    int64_t res = 0;
    unordered_map<int64_t, int64_t> mp;
    mp[0] = 1LL;
    int state = 0LL;
    for (auto c : word) {
      state ^= 1LL << (c - 'a');
      res += mp[state];
      for (int i = 0; i < 10; i++) {
        if (mp.count(state ^ (1LL << i))) {
          res += mp[state ^ (1LL << i)];
        }
      }
      mp[state]++;
    }
    return res;
  }
};
int main() {
  string s;
  cin >> s;
  Solution sol;
  cout << sol.wonderfulSubstrings(s) << endl;
  return 0;
}