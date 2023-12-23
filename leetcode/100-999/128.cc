#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int longestConsecutive(vector<int>& nums) {
			unordered_set<int> s(nums.begin(), nums.end());
			int res = 0;
			for (auto x : nums) {
				if (!s.count(x)) continue;
				s.erase(x);
				int l = x - 1, r = x + 1;
				while (s.count(l)) s.erase(l--);
				while (s.count(r)) s.erase(r++);
				res = max(res, r - l - 1);
			}
            return res;
		}
};
int main() { return 0; }