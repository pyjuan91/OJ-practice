#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<string>> findMismatchedSegments(string s1, string s2) {
    vector<vector<string>> res;
    string mismatch_str1, mismatch_str2;
    for (int i = 0; i < s1.size(); i++) {
      if (s1[i] == s2[i]) {
        if (not mismatch_str1.empty()) {
          res.push_back({mismatch_str1, mismatch_str2});
        }
        mismatch_str1.clear();
        mismatch_str2.clear();
      } else {
        mismatch_str1.push_back(s1[i]);
        mismatch_str2.push_back(s2[i]);
      }
    }
    if (not mismatch_str1.empty()) {
      res.push_back({mismatch_str1, mismatch_str2});
    }
    return res;
  }
};

int main() { return 0; }