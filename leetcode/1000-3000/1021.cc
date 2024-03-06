#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string removeOuterParentheses(string s) {
    stack<char> st;
    string res = "";
    for (auto& c : s) {
      if (c == '(') {
        if (!st.empty()) res += c;
        st.push(c);
      } else {
        st.pop();
        if (!st.empty()) res += c;
      }
    }
    return res;
  }
};
int main() {
  Solution s;
  string str = "(()())(())";
  cout << s.removeOuterParentheses(str) << endl;
  return 0;
}