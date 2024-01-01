#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int findContentChildren(vector<int>& g, vector<int>& s) {
			sort(g.begin(), g.end());
			sort(s.begin(), s.end());
			int i = 0, j = 0, ans = 0;
			const int n = g.size(), m = s.size();

			while (i < n && j < m) {
				if (s[j] >= g[i]) ans++, i++, j++;
				else j++;
			}
            return ans;
		}
};
int main() {
	Solution sol;
	vector<int> g = {1, 2, 3}, s = {1, 1};
	cout << sol.findContentChildren(g, s) << endl;
	return 0;
}