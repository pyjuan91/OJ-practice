#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numOfSubarrays(vector<int>& arr) {
    const int64_t kMod = 1e9 + 7;
    int64_t res = 0, prv_odds = 0, prv_evens = 1;
    for (const int& x : arr) {
      if (x & 1) {
        swap(prv_odds, prv_evens);
      }
      prv_evens += 1;
      res = (res + prv_odds) % kMod;
    }
    return res;
  }
};

int main() { return 0; }