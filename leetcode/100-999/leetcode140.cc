#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		vector<string>
			wordBreak(string s, vector<string>& wordDict) {
			unordered_set<string> dic(
				wordDict.begin(), wordDict.end());

			vector<bool> dp(s.length() + 1, false);
			vector<vector<string>> res(s.length() + 1);
			dp[0] = true;

			for (int i = 1; i <= s.length(); i++) {
				for (int j = i - 1; j >= 0; j--) {
					string sub = s.substr(j, i - j);
					if (dp[j] && dic.find(sub) != dic.end()) {
						dp[i] = true;
						if (res[j].size() == 0)
							res[i].push_back(sub);
						for (auto k : res[j]) {
							res[i].push_back(k + " " + sub);
						}
					}
				}
			}
			return res[s.length()];
		}
};
int main() {
	auto s = Solution();
	vector<string> dic = {"cat", "cats", "and", "sand", "dog"};
	vector<string> res = s.wordBreak("catsanddog", dic);
	for (auto i : res) cout << i << endl;
	return 0;
}