#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int calculate(string s) {
    size_t i = 0;
    return static_cast<int>(evaluate(s, i));
  }

 private:
  int64_t evaluate(const string& s, size_t& i) {
    int64_t num = 0;
    vector<int64_t> stac;
    char op = '+';

    auto flush = [&](char c) {
      switch (c) {
        case '+':
          stac.push_back(num);
          break;
        case '-':
          stac.push_back(-num);
          break;
        case '*':
          stac.back() *= num;
          break;
        case '/':
          stac.back() /= num;
          break;
        default:
          break;
      }
      num = 0;
    };

    while (i < s.size() and s[i] != ')') {
      if (isdigit(s[i])) {
        num = num * 10 + (s[i] - '0');
      } else if (s[i] == '(') {
        ++i;
        num = evaluate(s, i);
      } else if (s[i] != ' ') {
        flush(op);
        op = s[i];
      }
      ++i;
    }

    flush(op);
    return accumulate(stac.begin(), stac.end(), 0LL);
  }
};

int main() { return 0; }