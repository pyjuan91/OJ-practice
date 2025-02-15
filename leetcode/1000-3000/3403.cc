#include <bits/stdc++.h>
#include <debug.cc>
using namespace std;

class Solution {
public:
  string answerString(string word, int numFriends) {
    if (numFriends == 1) return word;
    string res = "";
    int n = word.size();
    int ideal_len = n - numFriends + 1;
    for (int i = 0; i < n; i++) {
      if (!res.empty() and word[i] < res[0]) continue;
      int len = min(ideal_len, n - i);
      res = max(res, word.substr(i, len));
    }
    return res;
  }
};

int main() {
  return 0;
}