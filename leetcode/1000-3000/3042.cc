#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countPrefixSuffixPairs(vector<string>& words) {
    auto is_prefix = [](const string& a, const string& b) {
      return a.size() <= b.size() && b.substr(0, a.size()) == a;
      };
    auto is_suffix = [](const string& a, const string& b) {
      return a.size() <= b.size() && b.substr(b.size() - a.size()) == a;
      };
    auto is_prefix_suffix = [&](const string& a, const string& b) {
      return is_prefix(a, b) && is_suffix(a, b);
      };
    int res = 0;
    for (int i = 0; i < words.size(); i++) {
      for (int j = i + 1; j < words.size(); j++) {
        res += is_prefix_suffix(words[i], words[j]);
      }
    }
    return res;
  }
};

int main() {
  return 0;
}