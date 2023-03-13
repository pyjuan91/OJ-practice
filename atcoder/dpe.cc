#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
#define int long long
	int N, W, w, v;
	cin >> N >> W;
	vector<int> dp(maxn, 1e12);
    dp[0] = 0;
	while (N--) {
		cin >> w >> v;
		for (int value = maxn - 1; value >= v; value--)
			dp[value] = min(dp[value], dp[value - v] + w);
	}
	for (int i = maxn - 1; i >= 0; i--) {
		if (dp[i] <= W) {
			cout << i << "\n";
			break;
		}
	}
	return 0;
}