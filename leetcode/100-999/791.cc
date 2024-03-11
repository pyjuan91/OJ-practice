#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string customSortString(string order, string s) {
    sort(s.begin(), s.end(),
         [&](char a, char b) { return order.find(a) < order.find(b); });
    return s;
  }
};
int main() { return 0; }