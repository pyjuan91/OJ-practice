#include <bits/stdc++.h>
using namespace std;
long long dp[5005][5005];
int main() {
	cin.tie()->sync_with_stdio(false);
#define int long long
	int N, M, c, y;
	cin >> N >> M;
	vector<int> X(N + 1);
	map<int, int> bonus;
	for (int i = 1; i <= N; i++) cin >> X[i];
	for (int i = 0; i < M; i++) {
		cin >> c >> y;
		bonus[c] = y;
	}
	dp[0][0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j > 0; j--) {
			dp[i][j] = dp[i - 1][j - 1] + X[i] + bonus[j];
			dp[i][i + 1] = max(dp[i][i + 1], dp[i][j]);
		}
		dp[i][0] = dp[i - 1][i];
		dp[i][i + 1] = max(dp[i][i + 1], dp[i][0]);
	}
	cout << dp[N][N + 1];
	return 0;
}