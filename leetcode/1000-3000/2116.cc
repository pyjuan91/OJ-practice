#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canBeValid(string s, string locked) {
    int n = s.size();
    if (n & 1) return false;
    int open = 0, close = 0;
    for (int i = 0; i < n; i++) {
      if (locked[i] == '1') {
        if (s[i] == '(') open++;
        else close++;
      }
      else {
        open++;
      }
      if (close > open) return false;
    }

    open = 0, close = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (locked[i] == '1') {
        if (s[i] == ')') close++;
        else open++;
      }
      else {
        close++;
      }
      if (open > close) return false;
    }

    return true;
  }
};

int main() {
  return 0;
}