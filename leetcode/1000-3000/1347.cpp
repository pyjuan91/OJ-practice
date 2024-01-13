#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minSteps(string s, string t) {
    int cnt1[26] = {0}, cnt2[26] = {0};
    for (auto c : s) cnt1[c - 'a']++;
    for (auto c : t) cnt2[c - 'a']++;
    int diff = 0;
    for (int i = 0; i < 26; i++) diff += abs(cnt1[i] - cnt2[i]);
    return diff / 2;
  }
};
int main() {
  Solution s;
  string s1, s2;
  cin >> s1 >> s2;
  cout << s.minSteps(s1, s2) << endl;
  return 0;
}