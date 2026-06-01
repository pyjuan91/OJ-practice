#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minimumCost(vector<int>& cost) {
    sort(cost.begin(), cost.end());
    int sent_mod = 0, res = 0;
    while (!cost.empty()) {
      sent_mod = (sent_mod + 1) % 3;
      if (sent_mod > 0) {
        res += cost.back();
      }
      cost.pop_back();
    }
    return res;
  }
};

int main() { return 0; }