#include <bits/stdc++.h>
#define int long long
using namespace std;
int chaewon(int n, string& s) {
	vector<int> prefix(n + 1, 0);
	map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		prefix[i + 1] = prefix[i] + (s[i] - '0');
		cnt[prefix[i + 1] - (i + 1)]++;
	}
	int res = 0;
	for (auto& [v, c] : cnt) res += c * (c - 1) / 2;
	return res + cnt[0];
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		cout << chaewon(n, s) << "\n";
	}
	return 0;
}
