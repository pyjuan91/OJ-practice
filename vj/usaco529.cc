#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  ifstream cin("censor.in");
  ofstream cout("censor.out");
  cin.tie(nullptr)->sync_with_stdio(false);

  const int kMax = 1e6 + 5, kMod = 1e9 + 7, kPoly = 31;
  vector<int> p(kMax);
  p[0] = 1;
  for (int i = 1; i < kMax; i++) p[i] = (p[i - 1] * kPoly) % kMod;

  auto fast_power = [&](int a, int b) {
    int res = 1;
    while (b) {
      if (b & 1) res = (res * a) % kMod;
      a = (a * a) % kMod;
      b >>= 1;
    }
    return res;
  };

  auto inverse = [&](int a) { return fast_power(a, kMod - 2); };

  string s, t;
  cin >> s >> t;

  vector<int> prefix_hash_sum(kMax, 0);
  int hash_t = 0;
  for (int i = 0; i < t.size(); i++) {
    hash_t = (hash_t + (t[i] - 'a' + 1) * p[i]) % kMod;
  }

  string res;
  for (int i = 0; i < s.size(); i++) {
    res.push_back(s[i]);
    prefix_hash_sum[res.size()] = (prefix_hash_sum[res.size() - 1] +
                                   (s[i] - 'a' + 1) * p[res.size() - 1]) %
                                  kMod;
    if (res.size() >= t.size()) {
      int cur_hash = (prefix_hash_sum[res.size()] -
                      prefix_hash_sum[res.size() - t.size()] + kMod) %
                     kMod;
      cur_hash = (cur_hash * inverse(p[res.size() - t.size()])) % kMod;
      if (cur_hash == hash_t) {
        for (int j = 0; j < t.size(); j++) res.pop_back();
      }
    }
  }

  cout << res << '\n';

  return 0;
}
