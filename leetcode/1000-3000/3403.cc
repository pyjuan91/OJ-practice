#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string answerString(string word, int numFriends) {
    string res = "";

    if (numFriends == 1) return word;
    auto lexico_larger_one = [&](const string& a, const string& b) {
      for (int i = 0; i < min(a.size(), b.size()); i++) {
        if (a[i] > b[i]) return a;
        if (a[i] < b[i]) return b;
      };
      return a.size() > b.size() ? a : b;
      };

    int n = word.size(), max_len = n - numFriends + 1;
    for (int i = 0; i < n; i++) {
      string cur = word.substr(i, i + max_len > n ? n - i : max_len);
      res = lexico_larger_one(res, cur);
    }
    return res;
  }
};

int main() {
  return 0;
}