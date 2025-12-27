#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int similarPairs(vector<string>& words) {
    unordered_map<int, int> cnt;
    int res = 0;

    auto get_id = [&](const string& s) -> int {
      int res = 0;
      for (const auto& c : s) {
        res |= (1 << static_cast<int>(c - 'a'));
      }
      return res;
    };

    for (const auto& word : words) {
      int idx = get_id(word);
      res += cnt[idx];
      cnt[idx]++;
    }

    return res;
  }
};

int main() { return 0; }