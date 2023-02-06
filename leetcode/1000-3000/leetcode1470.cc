#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		vector<int> shuffle(vector<int>& nums, int n) {
			vector<int> res;
			for (int i = 0; i < n; i++) {
				res.emplace_back(nums[i]);
				res.emplace_back(nums[i + n]);
			}
            return res;
		}
};
int main() { return 0; }