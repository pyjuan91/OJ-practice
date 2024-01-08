#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maxScoreWords(vector<string>& words, vector<char>& letters,
                    vector<int>& score) {
    int n = words.size(), cnt[26] = {}, res = 0;
    for (auto c : letters) cnt[c - 'a']++;
    for (int mask = 1; mask < (1 << n); mask++) {
      int cur_cnt[26] = {}, cur_score = 0;
      bool ok = true;
      for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
          for (auto c : words[i]) {
            cur_cnt[c - 'a']++;
            cur_score += score[c - 'a'];
            if (cur_cnt[c - 'a'] > cnt[c - 'a']) ok = false;
          }
          if(!ok) break;
        }
      }
      if (ok) res = max(res, cur_score);
    }
    return res;
  }
};