#include <bits/stdc++.h>
using namespace std;
int chaewon(int odd, int even, int alice, int alice_turn, auto& dp) {
	if (dp[odd][even][alice][alice_turn] != -1)
		return dp[odd][even][alice][alice_turn];
	if (odd + even == 0) {
		dp[odd][even][alice][alice_turn] = alice;
		return alice;
	}
	if (alice_turn == 0) {
		if (odd > 0 && chaewon(odd - 1, even, alice ^ 1, 1, dp) == 0) {
			dp[odd][even][alice][alice_turn] = 0;
			return 0;
		}
		if (even > 0 && chaewon(odd, even - 1, alice, 1, dp) == 0) {
			dp[odd][even][alice][alice_turn] = 0;
			return 0;
		}
		dp[odd][even][alice][alice_turn] = 1;
		return 1;
	}
	if (odd > 0 && chaewon(odd - 1, even, alice, 0, dp) == 1) {
		dp[odd][even][alice][alice_turn] = 1;
		return 1;
	}
	if (even > 0 && chaewon(odd, even - 1, alice, 0, dp) == 1) {
		dp[odd][even][alice][alice_turn] = 1;
		return 1;
	}
	dp[odd][even][alice][alice_turn] = 0;
	return 0;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int odd = 0, even = 0, x;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (x & 1) odd++;
			else even++;
		}
		auto dp = vector<vector<vector<vector<int>>>>(
		  odd + 1,
		  vector<vector<vector<int>>>(
			even + 1, vector<vector<int>>(2, vector<int>(2, -1))));
		if (chaewon(odd, even, 0, 0, dp) == 0)
			cout << "Alice\n";
		else cout << "Bob\n";
	}
	return 0;
}