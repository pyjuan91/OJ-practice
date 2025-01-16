#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    int res = 0;
    if (m % 2) {
      for (int i = 0; i < n; i++) {
        res ^= nums1[i];
      }
    }
    if (n % 2) {
      for (int i = 0; i < m; i++) {
        res ^= nums2[i];
      }
    }
    return res;
  }
};

int main() {
  return 0;
}