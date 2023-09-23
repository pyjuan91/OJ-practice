#include <bits/stdc++.h>
#define int long long
using namespace std;
int r, g, b, dp[201][201][201], R[201], G[201], B[201];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> r >> g >> b;
	for (int i = 1; i <= r; i++) cin >> R[i];
	for (int i = 1; i <= g; i++) cin >> G[i];
	for (int i = 1; i <= b; i++) cin >> B[i];
	sort(R + 1, R + r + 1);
	sort(G + 1, G + g + 1);
	sort(B + 1, B + b + 1);
	for (int i = 0; i <= r; i++)
		for (int j = 0; j <= g; j++)
			for (int k = 0; k <= b; k++) dp[i][j][k] = -1e18;
	dp[0][0][0] = 0;
	function<int(int, int, int)> chaewon
	  = [&](int cur_r, int cur_g, int cur_b) {
		if (dp[cur_r][cur_g][cur_b] != -1e18)
			return dp[cur_r][cur_g][cur_b];
		int sel_rg = 0, sel_rb = 0, sel_gb = 0;
		if (cur_r && cur_g)
			sel_rg = R[cur_r] * G[cur_g]
				   + chaewon(cur_r - 1, cur_g - 1, cur_b);
		if (cur_r && cur_b)
			sel_rb = R[cur_r] * B[cur_b]
				   + chaewon(cur_r - 1, cur_g, cur_b - 1);
		if (cur_g && cur_b)
			sel_gb = G[cur_g] * B[cur_b]
				   + chaewon(cur_r, cur_g - 1, cur_b - 1);
		return dp[cur_r][cur_g][cur_b] = max({sel_rg, sel_rb, sel_gb});
	};
	cout << chaewon(r, g, b) << '\n';
	return 0;
}
