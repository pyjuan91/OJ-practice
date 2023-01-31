#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int bestTeamScore(vector<int>& scores, vector<int>& ages) {
			int n = scores.size(), res = 0;
			vector<pair<int, int>> v;
			for (int i = 0; i < n; i++)
				v.emplace_back(ages[i], scores[i]);
			sort(v.begin(), v.end());
			vector<int> dp(n);
			for (int i = 0; i < n; i++) {
				dp[i] = v[i].second;
				res = max(res, dp[i]);
			}

			for (int i = 0; i < n; i++) {
				for (int j = i - 1; j >= 0; j--) {
					if (v[j].second <= v[i].second)
						dp[i] = max(dp[i], dp[j] + v[i].second);
				}
				res = max(res, dp[i]);
			}
			return res;
		}
};
int main() { return 0; }