#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                        int need2) {
    long long sol1 = static_cast<long long>(cost1) * need1 +
                     static_cast<long long>(cost2) * need2;
    long long sol2 = static_cast<long long>(costBoth) * need1 +
                     static_cast<long long>(cost2) * max(0, need2 - need1);
    long long sol3 = static_cast<long long>(costBoth) * need2 +
                     static_cast<long long>(cost1) * max(0, need1 - need2);
    return min({sol1, sol2, sol3});
  }
};