#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    size_t n = words.size(), m = queries.size();
    vector<int> prefix_sum(n);

    auto is_vowel = [&](char c) {
      return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
      };

    auto check = [&](const string& s) {
      return is_vowel(s[0]) and is_vowel(s.back());
      };

    for (size_t i = 0; i < n; i++) {
      prefix_sum[i] = check(words[i]);
      if (i) prefix_sum[i] += prefix_sum[i - 1];
    }

    vector<int> ans;
    for (auto& q : queries) {
      int l = q[0], r = q[1];
      int res = prefix_sum[r] - (l ? prefix_sum[l - 1] : 0);
      ans.push_back(res);
    }

    return ans;
  }
};

int main() {
  return 0;
}