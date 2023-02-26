#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int largestRectangleArea(vector<int>& heights) {
			vector<pair<int, int>> mono;
			int res = 0;
			for (int i = 0; i < heights.size(); i++) {
				int co = i;
				while (!mono.empty()
							 && heights[i] < mono.back().first) {
					co = mono.back().second;
					res = max(
						res,
						(i - mono.back().second) * mono.back().first);
					mono.pop_back();
				}
				mono.push_back({heights[i], co});
			}
			while (!mono.empty()) {
				res = max(
					res,
					(int) (heights.size() - mono.back().second)
						* mono.back().first);
				mono.pop_back();
			}
			return res;
		}
};
int main() { return 0; }