#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool canArrange(vector<int>& arr, int k) {
    vector<int> cnt(k, 0);
    for (const auto& x : arr) cnt[(x % k + k) % k]++;
    for (int i = 1; i < k; i++) {
      if (cnt[i] != cnt[k - i]) return false;
    }
    return cnt[0] % 2 == 0;
  }
};

int main() { return 0; }