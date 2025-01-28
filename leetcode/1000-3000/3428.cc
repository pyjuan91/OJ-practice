#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  static constexpr int64_t kMod = 1e9 + 7;
  static constexpr int64_t kMax = 1e5 + 5;
  vector<int64_t> fact, inv_fact;

  int64_t fast_pow(int64_t base, int64_t exp) {
    int64_t res = 1;
    while (exp) {
      if (exp & 1) res = res * base % kMod;
      base = base * base % kMod;
      exp >>= 1;
    }
    return res;
  }

  void init_fact() {
    fact.resize(kMax);
    inv_fact.resize(kMax);
    fact[0] = 1;
    for (int i = 1; i < kMax; i++) fact[i] = fact[i - 1] * i % kMod;
    inv_fact[kMax - 1] = fast_pow(fact[kMax - 1], kMod - 2);
    for (int i = kMax - 2; i >= 0; i--) inv_fact[i] = inv_fact[i + 1] * (i + 1) % kMod;
  }

  int64_t comb(int64_t n, int64_t k) {
    if (k == 0) return 1;
    if (n < k) return 0;
    return fact[n] * inv_fact[k] % kMod * inv_fact[n - k] % kMod;
  }

public:
  int minMaxSums(vector<int>& nums, int k) {
    init_fact();
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int64_t res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < k; j++) {
        res = (res +
          (static_cast<int64_t>(nums[i]) * ((comb(i, j) + comb(n - i - 1, j)) % kMod) % kMod)
          ) % kMod;
      }
    }
    return static_cast<int32_t>(res);
  }
};

int main() {
  Solution s;
  return 0;
}