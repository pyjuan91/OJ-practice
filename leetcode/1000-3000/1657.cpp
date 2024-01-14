#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool closeStrings(string word1, string word2) {
    int cnt1[26] = {0}, cnt2[26] = {0};
    for (auto c : word1) cnt1[c - 'a']++;
    for (auto c : word2) cnt2[c - 'a']++;
    multiset<int> sc1, sc2, mc1, mc2;
    for (int i = 0; i < 26; i++) {
      if (cnt1[i]) {
        sc1.insert(cnt1[i]);
        mc1.insert(i);
      }
      if (cnt2[i]) {
        sc2.insert(cnt2[i]);
        mc2.insert(i);
      }
    }
    return sc1 == sc2 && mc1 == mc2;
  }
};
int main() {
  Solution s;
  string word1, word2;
  cin >> word1 >> word2;
  cout << s.closeStrings(word1, word2) << endl;
  return 0;
}