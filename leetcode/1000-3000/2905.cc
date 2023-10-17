#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		vector<int>
		  findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
			int n = nums.size();
			if (indexDifference >= n) return {-1, -1};
			set<pair<int, int>> s;
			for (int i = indexDifference; i < n; i++) {
				s.insert({nums[i - indexDifference], i - indexDifference});
				auto iter = s.lower_bound(
				  make_pair(nums[i] + valueDifference, -1));
				if (iter != s.end()) return {iter->second, i};
				iter = s.upper_bound(make_pair(nums[i] - valueDifference, n));
				if (iter != s.begin()) {
					iter--;
					return {iter->second, i};
				}
			}
			return {-1, -1};
		}
};
int main() { return 0; }