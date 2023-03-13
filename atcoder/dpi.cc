#include <bits/stdc++.h>
using namespace std;
double dp[3000] = {0.0}, p;
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cin >> N;
	dp[0] = 1;
	for (int i = 1; i <= N; i++) {
		cin >> p;
		for (int j = i; j >= 1; j--)
			dp[j] = dp[j] * (1 - p) + dp[j - 1] * p;
		dp[0] = (1 - p) * dp[0];
	}
	p = 0;
	for (int i = N / 2 + 1; i <= N; i++) p += dp[i];
	cout << setprecision(20) << p;
	return 0;
}