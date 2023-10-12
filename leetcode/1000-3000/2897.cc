#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int maxSum(vector<int>& nums, int k) {
			const long long mod = 1e9 + 7;
			vector<int> bc(32, 0);
			for (auto x : nums) {
				for (int i = 0; i < 32; i++) {
					if (x & (1 << i)) bc[i]++;
				}
			}
			long long res = 0;
			for (int i = 0; i < k; i++) {
				long long cur = 0;
				for (int j = 0; j < 32; j++) {
					if (bc[j]) {
						cur += (1LL << j);
						bc[j]--;
					}
				}
				res += cur * cur % mod;
                res %= mod;
			}
			return (int)res;
		}
};
int main() { return 0; }