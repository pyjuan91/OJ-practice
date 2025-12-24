#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int countBeautifulPairs(vector<int>& nums) {
    int res = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int first_digit = nums[i];
      while (first_digit > 9) first_digit /= 10;
      for (int j = i + 1; j < n; j++) {
        int last_digit = nums[j] % 10;
        if (gcd(first_digit, last_digit) == 1) res++;
      }
    }
    return res;
  }
};

int main() { return 0; }