#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
#define int long long
	int n, k, w, v;
	cin >> n >> k;
	vector<int> dp(k + 1, 0);
	while (n--) {
		cin >> w >> v;
		for (int i = k; i >= w; i--)
			dp[i] = max(dp[i], dp[i - w] + v);
	}
	cout << dp[k];
	return 0;
}