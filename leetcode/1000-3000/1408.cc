#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> stringMatching(vector<string>& words) {
    vector<string> ans;
    for (size_t i = 0; i < words.size();i++) {
      for (size_t j = 0; j < words.size(); j++) {
        if (i == j) continue;
        if (words[j].find(words[i]) != string::npos) {
          ans.push_back(words[i]);
          break;
        }
      }
    }
    return ans;
  }
};

int main() {
  return 0;
}