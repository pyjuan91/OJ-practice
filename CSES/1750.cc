#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 5;
int n, q, dp[maxn][32], x, k;

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> dp[i][0];

	for (int bi_jump = 1; bi_jump < 32; bi_jump++) {
		for (int node = 1; node <= n; node++) {
			dp[node][bi_jump] = dp[dp[node][bi_jump - 1]][bi_jump - 1];
		}
	}

	while (q--) {
		cin >> x >> k;
		for (int bi_jump = 0; bi_jump < 32; bi_jump++) {
			if (k & (1 << bi_jump)) x = dp[x][bi_jump];
		}
		cout << x << '\n';
	}
	return 0;
}
