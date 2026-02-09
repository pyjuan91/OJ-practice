#include <bits/stdc++.h>
using namespace std;

// BeginCodeSnip{HashedString}
class HashedString {
 private:
  // change M and B if you want
  static const int64_t M = (1LL << 61) - 1;
  static const int64_t B;

  // pow[i] contains B^i % M
  static vector<int64_t> pow;

  // p_hash[i] is the hash of the first i characters of the given string
  vector<int64_t> p_hash;

  __int128 mul(int64_t a, int64_t b) { return (__int128)a * b; }
  int64_t mod_mul(int64_t a, int64_t b) { return mul(a, b) % M; }

 public:
  HashedString(const string& s) : p_hash(s.size() + 1) {
    while (pow.size() <= s.size()) {
      pow.push_back(mod_mul(pow.back(), B));
    }
    p_hash[0] = 0;
    for (int i = 0; i < s.size(); i++) {
      p_hash[i + 1] = (mul(p_hash[i], B) + s[i]) % M;
    }
  }

  int64_t get_hash(int start, int end) {
    int64_t raw_val =
        p_hash[end + 1] - mod_mul(p_hash[start], pow[end - start + 1]);
    return (raw_val + M) % M;
  }
};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
vector<int64_t> HashedString::pow = {1};
const int64_t HashedString::B =
    uniform_int_distribution<int64_t>(0, M - 1)(rng);

class Solution {
 public:
  int shortestMatchingSubstring(string s, string p) {
    const int n = s.size(), m = p.size();
    vector<string> p_seg;
    string str;
    for (int i = 0; i < m; i++) {
      if (p[i] != '*')
        str.push_back(p[i]);
      else if (!str.empty())
        p_seg.push_back(str), str.clear();
    }
    if (!str.empty()) p_seg.push_back(str);
    vector<vector<int>> pos(p_seg.size());
    HashedString hashed_s(s);
    for (int i = 0; i < p_seg.size(); i++) {
      const auto& k = p_seg[i];
      HashedString hashed_k(k);
      int64_t hashed_k_value = hashed_k.get_hash(0, k.size() - 1);
      for (int start = 0; start + k.size() <= n; start++) {
        if (hashed_s.get_hash(start, start + k.size() - 1) == hashed_k_value) {
          pos[i].push_back(start);
        }
      }
    }
    if (p_seg.size() == 0) return 0;
    if (p_seg.size() == 1) {
      if (!pos[0].empty()) return p_seg[0].size();
      return -1;
    }
    int res = INT32_MAX;
    for (const auto& x : pos[0]) {
      auto iter_mid = lower_bound(pos[1].begin(), pos[1].end(), x + p_seg[0].size());
      if (iter_mid == pos[1].end()) break;
      if (p_seg.size() == 3) {
        auto iter_end = lower_bound(pos[2].begin(), pos[2].end(), *iter_mid + p_seg[1].size());
        if (iter_end == pos[2].end()) break;
        res = min(res, static_cast<int>(*iter_end + p_seg[2].size() - x));
      } else {
        res = min(res, static_cast<int>(*iter_mid + p_seg[1].size() - x));
      }
    }

    return res == INT32_MAX ? -1 : res;
  }
};

int main() { return 0; }