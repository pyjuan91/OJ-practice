#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string minRemoveToMakeValid(string s) {
    string res;
    int left_open = 0;
    for (const auto& c : s) {
      res.push_back(c);
      if (c == '(')
        left_open++;
      else if (c == ')') {
        if (left_open == 0) {
          res.pop_back();
        } else {
          left_open--;
        }
      }
    }
    int right_open = 0;
    swap(res, s);
    reverse(s.begin(), s.end());
    res.clear();
    for (const auto& c : s) {
      res.push_back(c);
      if (c == ')')
        right_open++;
      else if (c == '(') {
        if (right_open == 0) {
          res.pop_back();
        } else {
          right_open--;
        }
      }
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
int main() {
  Solution s;
  string str = "lee(t(c)o)de)";
  cout << s.minRemoveToMakeValid(str) << endl;
  return 0;
}