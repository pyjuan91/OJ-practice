#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minimumOperationsToMakeKPeriodic(string word, int k) {
    unordered_map<string, int> mp;
    for (int i = 0; i < word.size(); i += k) {
      string s = word.substr(i, k);
      mp[s]++;
    }
    int max_freq = 0;
    for (auto [_, freq] : mp) {
      max_freq = max(max_freq, freq);
    }
    return word.size() / k - max_freq;
  }
};

int main() {
  string word;
  int k;
  cin >> word >> k;
  cout << Solution().minimumOperationsToMakeKPeriodic(word, k) << '\n';
}