#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    int cnt[26] = {};
    for (const string& word : words2) {
      int cnt2[26] = {};
      for (char c : word) {
        cnt2[c - 'a']++;
      }
      for (int i = 0; i < 26; i++) {
        cnt[i] = max(cnt[i], cnt2[i]);
      }
    }
    vector<string> res;
    for (const string& word : words1) {
      int cnt1[26] = {};
      for (char c : word) {
        cnt1[c - 'a']++;
      }
      bool ok = true;
      for (int i = 0; i < 26; i++) {
        if (cnt1[i] < cnt[i]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        res.push_back(word);
      }
    }
    return res;
  }
};

int main() {
  return 0;
}