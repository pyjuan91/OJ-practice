#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> minCosts(vector<int>& cost) {
    vector<int> res;
    for (auto x : cost) {
      if (res.empty() or res.back() > x) {
        res.push_back(x);
      }
      else {
        res.push_back(res.back());
      }
    }
    return res;
  }
};