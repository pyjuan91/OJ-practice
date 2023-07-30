#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		vector<int> productExceptSelf(vector<int>& nums) {
			int pro = 1, zc = 0;
			for (auto x : nums) {
				if (x == 0) zc++;
				else pro *= x;
			}
			if (zc > 1) return vector<int>(nums.size(), 0);
			vector<int> res;
			if (zc) {
				for (auto x : nums) {
					if (x == 0) res.push_back(pro);
					else res.push_back(0);
				}
			}
			else {
				for (auto x : nums) { res.push_back(pro / x); }
			}
			return res;
		}
};
int main() { return 0; }