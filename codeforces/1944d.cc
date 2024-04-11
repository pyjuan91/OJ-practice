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
  vector<int64_t> p_hash_rev;

  __int128 mul(int64_t a, int64_t b) { return (__int128)a * b; }
  int64_t mod_mul(int64_t a, int64_t b) { return mul(a, b) % M; }

 public:
  HashedString(const string &s)
      : p_hash(s.size() + 3), p_hash_rev(s.size() + 3) {
    while (pow.size() < s.size()) {
      pow.push_back(mod_mul(pow.back(), B));
    }
    p_hash[0] = 0;
    for (int i = 0; i < s.size(); i++) {
      p_hash[i + 1] = (mul(p_hash[i], B) + s[i]) % M;
    }
    p_hash_rev[s.size()] = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      p_hash_rev[i] = (mul(p_hash_rev[i + 1], B) + s[i]) % M;
    }
  }

  int64_t get_hash(int start, int end) {
    int64_t raw_val =
        p_hash[end + 1] - mod_mul(p_hash[start], pow[end - start + 1]);
    return (raw_val + M) % M;
  }

  int64_t get_hash_rev(int start, int end) {
    int64_t raw_val =
        p_hash_rev[start] - mod_mul(p_hash_rev[end + 1], pow[end - start + 1]);
    return (raw_val + M) % M;
  }
};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
vector<int64_t> HashedString::pow = {1};
const int64_t HashedString::B =
    uniform_int_distribution<int64_t>(0, M - 1)(rng);

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t, n, m, u, v;
  string s;
  cin >> t;
  while (t--) {
    cin >> n >> m >> s;
    s = " " + s + " ";
    HashedString hs(s);

    while (m--) {
      cin >> u >> v;
      if (u == v) {
        cout << "0\n";
        continue;
      }
      if (v == u + 1) {
        if (s[u] == s[v])
          cout << "0\n";
        else
          cout << "2\n";
        continue;
      }

      int64_t len = v - u + 1;
      int64_t res = (len + 1) * len / 2 - 1;

      if (hs.get_hash(u, v - 1) == hs.get_hash(u + 1, v))
        res = 0;
      else if (hs.get_hash(u, v - 2) == hs.get_hash(u + 2, v) && len > 3) {
        res = ((len / 2) * 2 + 2) * (len / 2) / 2;
      } else if (hs.get_hash(u, u + len / 2 - 1) ==
                 hs.get_hash_rev(v - len / 2 + 1, v))
        res = (len + 1) * len / 2 - 1 - len;

      cout << res << '\n';
    }
  }
  return 0;
}
