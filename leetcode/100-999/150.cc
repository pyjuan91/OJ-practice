#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    vector<int> stac;
    for (auto& token : tokens) {
      if (isdigit(token[0]) || token[0] == '-') {
        stac.push_back(stoi(token));
      } else {
        int b = stac.back();
        stac.pop_back();
        int a = stac.back();
        stac.pop_back();
        if (token == "+")
          stac.push_back(a + b);
        else if (token == "-")
          stac.push_back(a - b);
        else if (token == "*")
          stac.push_back(a * b);
        else
          stac.push_back(a / b);
      }
    }
    return stac.back();
  }
};
int main() { return 0; }