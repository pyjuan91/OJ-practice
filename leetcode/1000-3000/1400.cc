#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canConstruct(string s, int k) {
    if (k > s.size()) return false;
    int cnt[26] = { 0 };
    for (char c : s) {
      cnt[c - 'a'] ^= 1;
    }
    int odd = 0;
    for (int i = 0; i < 26; i++) {
      odd += cnt[i];
    }
    return odd <= k;
  }
};

int main() {
  return 0;
}