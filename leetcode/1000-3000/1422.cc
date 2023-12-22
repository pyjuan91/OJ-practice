#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int maxScore(string s) {
			int n = s.size();
			vector<int> pref_zeros(n + 1, 0);
			vector<int> suff_ones(n + 1, 0);
			for (int i = 0; i < n; i++) {
				if (i) pref_zeros[i] = pref_zeros[i - 1];
				if (s[i] == '0') pref_zeros[i]++;
			}
			for (int i = n - 1; i >= 0; i--) {
				if (i < n - 1) suff_ones[i] = suff_ones[i + 1];
				if (s[i] == '1') suff_ones[i]++;
			}
			int res = 0;
			for (int i = 0; i < n - 1; i++) {
				res = max(res, pref_zeros[i] + suff_ones[i + 1]);
			}
			return res;
		}
};
int main() {
	Solution s;
	return 0;
}