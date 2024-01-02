#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int minCut(string s) {
			int n = s.size();
			vector<vector<bool>> is_palindrome(n, vector<bool>(n, true));
			for (int len = 2; len <= n; len++) {
				for (int i = 0; i + len <= n; i++) {
					int j = i + len - 1;
					is_palindrome[i][j]
					  = (s[i] == s[j]) && is_palindrome[i + 1][j - 1];
				}
			}
			vector<int> dp(n, n);
			for (int i = 0; i < n; i++) {
				if (is_palindrome[0][i]) {
					dp[i] = 0;
					continue;
				}
				for (int j = 1; j <= i; j++) {
					if (is_palindrome[j][i])
						dp[i] = min(dp[i], dp[j - 1] + 1);
				}
			}
			return dp[n - 1];
		}
};
int main() {
	Solution s;
	string str;
	cin >> str;
	cout << s.minCut(str) << endl;
	return 0;
}