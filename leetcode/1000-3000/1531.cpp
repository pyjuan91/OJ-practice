#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int getLengthOfOptimalCompression(string s, int k) {
			int n = s.size();
			vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
			function<int(int, int)> chaewon = [&](int i, int k) {
				if (i + k >= n) return 0;
				if (dp[i][k] != -1) return dp[i][k];
				int res = k ? chaewon(i + 1, k - 1) : 1e5;
				int quota = k, cnt = 1;
				for (int j = i + 1; j <= n; j++) {
					int suff = (cnt>99?3:cnt>9?2:cnt>1?1:0);
					res = min(res, 1 + suff + chaewon(j, quota));
					if (j < n && s[j] == s[i]) cnt++;
					else if (--quota < 0) break;
				}
				return dp[i][k] = res;
			};
			return chaewon(0, k);
		}
};


int main() {
	Solution s;
	string str;
	int k;
	cin >> str >> k;
	cout << s.getLengthOfOptimalCompression(str, k) << endl;
	return 0;
}