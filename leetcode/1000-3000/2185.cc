#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int prefixCount(vector<string>& words, string pref) {
    int res = 0;
    for (const auto& word : words) {
      res += word.starts_with(pref);
    }
    return res;
  }
};

int main() {
  return 0;
}