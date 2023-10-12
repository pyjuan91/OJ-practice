#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int dp[105];
		int numDecodings(string s) {
			for (int i = 0; i < 105; i++) dp[i] = -1;
			return chaewon(s, 0);
		}
		int chaewon(const string& s, int id) {
			if (id == s.length()) return 1;
			if (s[id] == '0') return 0;
			if (dp[id] != -1) return dp[id];
			dp[id] = chaewon(s, id + 1);
			if (id + 1 < s.length() && (s[id] == '1' || (s[id] == '2' && s[id + 1] <= '6')))
				dp[id] += chaewon(s, id + 2);
			return dp[id];
		}
};
int main() { return 0; }