#include <bits/stdc++.h>
using namespace std;
int N;
const int mod = 1e9 + 7;
const int ma = 1 << 21;
int dp[21][ma];
int a[21][21];
int popcount(int x) {
	int res = 0;
	while (x) {
		res += x & 1;
		x >>= 1;
	}
	return res;
}
int main() {
	cin.tie()->sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) cin >> a[i][j];
	for (int j = 0; j < N; j++)
		if (a[0][j]) dp[0][1 << j] = 1;
	for (int j = 1; j < N; j++) {
		for (int cond = 0; cond < (1 << N); cond++) {
			int pairs = popcount(cond);
			dp[j][cond] = 0;
			if (pairs == j + 1) {
				for (int women = 0; women < N; women++) {
					if ((cond & (1 << women)) && a[j][women]) {
						dp[j][cond] += dp[j - 1][cond - (1 << women)];
						dp[j][cond] %= mod;
					}
				}
			}
		}
	}
	cout << dp[N - 1][(1 << N) - 1];
	return 0;
}