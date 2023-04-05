#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		bool chaewon(int guess, vector<int>& nums) {
			if (nums[0] > guess) return false;
			long long quota = guess - nums[0];
			for (int i = 1; i < nums.size(); i++) {
				if (nums[i] <= guess)
					quota += 1LL * (guess - nums[i]);
				else {
					if (quota < nums[i] - guess) return false;
					quota -= nums[i] - guess;
				}
			}
			return true;
		}
		int minimizeArrayValue(vector<int>& nums) {
			int left = nums[0] - 1;
			int right = 1e9;
			while (left + 1 < right) {
				int mid = left + (right - left) / 2;
				if (chaewon(mid, nums)) right = mid;
				else left = mid;
			}
			return right;
		}
};
int main() { return 0; }