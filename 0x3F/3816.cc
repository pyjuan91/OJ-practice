#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string lexSmallestAfterDeletion(string s) {
    array<int, 26> cnt = {};
    for (const auto& c : s) cnt[c - 'a']++;
    vector<char> stac;
    for (const auto& c : s) {
      while (!stac.empty() and cnt[stac.back() - 'a'] >= 2 and
             stac.back() > c) {
        cnt[stac.back() - 'a']--;
        stac.pop_back();
      }
      stac.push_back(c);
    }
    while (stac.size() >= 2 and cnt[stac.back() - 'a'] >= 2) {
      cnt[stac.back() - 'a']--;
      stac.pop_back();
    }
    return string(stac.begin(), stac.end());
  }
};

int main() { return 0; }