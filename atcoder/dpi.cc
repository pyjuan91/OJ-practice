#include <bits/stdc++.h>
using namespace std;
double dp[3000][3000] = {0.0}, p;
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cin >> N;
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		cin >> p;
		dp[i][0] = (1 - p) * dp[i - 1][0];
		for (int j = 1; j <= i; j++)
			dp[i][j] += dp[i - 1][j] * (1 - p) + dp[i - 1][j - 1] * p;
	}
	p = 0;
	for (int i = N / 2 + 1; i <= N; i++) p += dp[N][i];
	cout << setprecision(20) << p;
	return 0;
}