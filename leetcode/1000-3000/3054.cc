#include <bits/stdc++.h>
#include "debug.cc"
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
    while (pow.size() < s.size()) {
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
vector<int64_t> HashedString::pow = { 1 };
const int64_t HashedString::B =
uniform_int_distribution<int64_t>(0, M - 1)(rng);

vector<int> longestPalindromeStartingAt(const string& s) {
  int n = s.size();
  vector<int> res(n, 0);

  // Check for odd-length palindromes
  for (int center = 0; center < n; center++) {
    int l = center, r = center;
    while (l >= 0 && r < n && s[l] == s[r]) {
      // For palindrome s[l...r] starting at index l, update maximum length
      res[l] = max(res[l], r - l + 1);
      l--;
      r++;
    }
  }

  // Check for even-length palindromes
  for (int center = 0; center < n - 1; center++) {
    int l = center, r = center + 1;
    while (l >= 0 && r < n && s[l] == s[r]) {
      res[l] = max(res[l], r - l + 1);
      l--;
      r++;
    }
  }

  return res;
}

vector<tuple<int, int, int, int>> findMaximalCommonSubstrings(const string& s, const string& t) {
  int n = s.size(), m = t.size();
  // Create a DP table where dp[i][j] is the length of the longest common
  // suffix ending at s[i-1] and t[j-1]
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  vector<tuple<int, int, int, int>> result;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        // Check if the substring cannot be extended further
        if (i == n || j == m || s[i] != t[j]) {
          int len = dp[i][j];
          // Record the start and end indices for s and t.
          // The substring is from index (i - len) to (i - 1) in s
          // and from index (j - len) to (j - 1) in t.
          result.push_back(make_tuple(i - len, i - 1, j - len, j - 1));
        }
      }
      // else dp[i][j] remains 0
    }
  }
  return result;
}

class Solution {
public:
  int longestPalindrome(string s, string t) {
    int n = s.size();
    int m = t.size();
    reverse(t.begin(), t.end());
    vector<int> s_lps = std::move(longestPalindromeStartingAt(s));
    vector<int> t_lps = std::move(longestPalindromeStartingAt(t));
    s_lps.push_back(0), t_lps.push_back(0);
    int res = max(*max_element(s_lps.begin(), s_lps.end()), *max_element(t_lps.begin(), t_lps.end()));
    // debug(s_lps, t_lps);
    // debug(res);
    auto common_substrings = std::move(findMaximalCommonSubstrings(s, t));
    // debug(common_substrings);
    for (auto [s_start, s_end, t_start, t_end] : common_substrings) {
      int len = s_end - s_start + 1;
      int lps = max(s_lps[s_end + 1], t_lps[t_end + 1]);
      res = max(res, len * 2 + lps);
    }
    return res;
  }
};

int main() {
  Solution sol;
  string s, t;
  cin >> s >> t;
  cout << sol.longestPalindrome(s, t) << endl;
  return 0;
}