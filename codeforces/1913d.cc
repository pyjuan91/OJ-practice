#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
struct mi {
		int v;
		explicit operator int() const { return v; }
		mi() { v = 0; }
		mi(long long _v)
		  : v(_v % MOD) {
			v += (v < 0) * MOD;
		}
};
mi &operator+=(mi &a, mi b) {
	if ((a.v += b.v) >= MOD) a.v -= MOD;
	return a;
}
mi &operator-=(mi &a, mi b) {
	if ((a.v -= b.v) < 0) a.v += MOD;
	return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long) a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
	assert(p >= 0);
	return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
	assert(a.v != 0);
	return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }

int chaewon(int n, vector<int> &a) {
	vector<mi> dp(n), pre_dp_sum(n);
	stack<int> mono;
	mi mono_sum = 0;

	for (int i = 0; i < n; i++) {
		while (!mono.empty() && a[mono.top()] > a[i]) {
			mono_sum -= dp[mono.top()];
			mono.pop();
		}

		if (mono.empty())
			dp[i] += 1 + (i ? pre_dp_sum[i - 1] : 0);
		else
			dp[i] += mono_sum + pre_dp_sum[i - 1]
				   - pre_dp_sum[mono.top()];

		pre_dp_sum[i] = dp[i] + (i ? pre_dp_sum[i - 1] : 0);
		mono.push(i);
		mono_sum += dp[i];
	}

	mi res = 0;
	int suff_min = INT32_MAX;
	for (int i = n - 1; i >= 0; i--) {
		suff_min = min(suff_min, a[i]);
		if (suff_min == a[i]) res += dp[i];
	}

	return (int) res;
}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n);
		for (auto &x : a) cin >> x;
		cout << chaewon(n, a) << '\n';
	}
	return 0;
}