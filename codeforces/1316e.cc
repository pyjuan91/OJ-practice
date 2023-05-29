#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n, p, k;
	cin >> n >> p >> k;
	vector<pair<int, int>> audio(n);
	for (int i = 0; i < n; i++) {
		cin >> audio[i].first;
		audio[i].second = i;
	}
	sort(audio.rbegin(), audio.rend());
	vector<int> new_pos(n);
	for (int i = 0; i < n; i++) new_pos[audio[i].second] = i;
	vector<vector<int>> position(n, vector<int>(p));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < p; j++)
			cin >> position[new_pos[i]][j];

	vector<vector<int>> dp(n + 1, vector<int>(1 << p, -1));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		for (int team_set = 0; team_set < (1 << p); team_set++) {
			auto bp = __builtin_popcount(team_set);
			if (bp > i) continue;
			int cur_audio = i - bp - 1;
			if (cur_audio < k && dp[i - 1][team_set] != -1) {
				dp[i][team_set] = max(
				  dp[i][team_set],
				  dp[i - 1][team_set] + audio[i - 1].first);
			}
			for (int t = 0; t < p; t++) {
				int prev_state = team_set & ~(1 << t);
				if ((team_set & (1 << t)) == 0 || dp[i - 1][prev_state] == -1)
					continue;
				dp[i][team_set] = max(
				  dp[i][team_set],
				  dp[i - 1][prev_state] + position[i - 1][t]);
			}
		}
	}
	cout << dp[n][(1 << p) - 1];
	return 0;
}