#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		bool wordBreak(string s, vector<string>& wordDict) {
			unordered_set<string> dic(
				wordDict.begin(), wordDict.end());

			vector<bool> dp(s.length() + 1, false);
			dp[0] = true;

			for (int i = 1; i <= s.length(); i++) {
				for (int j = i - 1; j >= 0; j--) {
					string str = s.substr(j, i - j);
					if (dp[j] && dic.find(str) != dic.end()) {
						dp[i] = true;
						break;
					}
				}
			}
			return dp[s.length()];
		}
};
int main() {
	auto sol = Solution();
	vector<string> wordDict
		= {"cats", "dog", "sand", "and", "cat"};
	cout << sol.wordBreak("catsandogz", wordDict);

	return 0;
}