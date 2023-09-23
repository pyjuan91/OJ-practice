#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int a, b, c, d, res = 0;
	cin >> a >> b >> c >> d;
	vector<int> sum_cnt {1}, prefix;
	for (int i = 1; i <= min(b - a, c - b); i++)
		sum_cnt.push_back(i + 1);
	for (int i = min(b - a, c - b) + 1; i <= max(b - a, c - b); i++)
		sum_cnt.push_back(sum_cnt.back());
	for (int i = min(b - a, c - b) - 1; i >= 0; i--)
		sum_cnt.push_back(i + 1);
	for (auto x : sum_cnt) {
		if (!prefix.empty())
			prefix.push_back(prefix.back() + x);
		else prefix.push_back(x);
	}
	for (int i = c; i <= d; i++) {
		int bound = i - (a + b);
		if (bound >= (int)prefix.size()) continue;
		if (bound < 0) res += prefix.back();
		else res += prefix.back() - prefix[bound];
	}
	cout << res << '\n';
	return 0;
}
