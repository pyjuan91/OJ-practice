#include <bits/stdc++.h>
using namespace std;

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

  // zero-based, inclusive
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
  bool hasAllCodes(string s, int k) {
    auto hs = HashedString(s);
    unordered_set<int64_t> us;
    for (int i = k - 1; i < s.size(); i++) {
      us.insert(hs.get_hash(i - k + 1, i));
    }
    return us.size() == (1 << k);
  }
};

int main() { return 0; }