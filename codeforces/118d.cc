#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[101][101][2][11];
const int mod = 1e8;
int chaewon(int n1, int n2, int k1, int k2, int tail_mode, int tail_cnt) {
	if (n1 == 0 && n2 == 0) return 1;
	if (dp[n1][n2][tail_mode][tail_cnt] != -1)
		return dp[n1][n2][tail_mode][tail_cnt];
	int res = 0;
	if (tail_mode == 0) {
		if (n1 && tail_cnt < k1) {
			res += chaewon(n1 - 1, n2, k1, k2, 0, tail_cnt + 1);
			res %= mod;
		}
		if (n2) {
			res += chaewon(n1, n2 - 1, k1, k2, 1, 1);
			res %= mod;
		}
	}
	else {
		if (n2 && tail_cnt < k2) {
			res += chaewon(n1, n2 - 1, k1, k2, 1, tail_cnt + 1);
			res %= mod;
		}
		if (n1) {
			res += chaewon(n1 - 1, n2, k1, k2, 0, 1);
			res %= mod;
		}
	}
	return dp[n1][n2][tail_mode][tail_cnt] = res;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			for (int k = 0; k < 2; k++)
				for (int l = 0; l < 11; l++)
					dp[i][j][k][l] = -1;
	int n1, n2, k1, k2;
	cin >> n1 >> n2 >> k1 >> k2;
    cout << chaewon(n1, n2, k1, k2, 0, 0) << '\n';
	return 0;
}
