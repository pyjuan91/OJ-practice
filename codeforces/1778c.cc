#include <bits/stdc++.h>
#define int long long
using namespace std;
int cal(string& a, string& b, int n) {
	int res = 0, buff = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) buff++;
		else buff = 0;
		res += buff;
	}
	return res;
}
int chaewon(int n, int k, string a, string b) {
	set<char> s;
	for (int i = 0; i < n; i++)
		if (a[i] != b[i]) s.insert(a[i]);
	vector<char> posi = vector<char>(s.begin(), s.end());
	int res = cal(a, b, n), diff = posi.size();

	if (k >= diff) return cal(b, b, n);

	for (int cond = 0; cond < (1 << diff); cond++) {
		if (__builtin_popcount(cond) != k) continue;
		set<char> can_modi;
		for (int i = 0; i < diff; i++) {
			if (cond & (1 << i)) { can_modi.insert(posi[i]); }
		}
		string c = a;
		for (int i = 0; i < n; i++) {
			if (can_modi.count(c[i])) { c[i] = b[i]; }
		}
		res = max(res, cal(c, b, n));
	}
	return res;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, k;
	string a, b;
	cin >> t;
	while (t--) {
		cin >> n >> k >> a >> b;
		cout << chaewon(n, k, a, b) << '\n';
	}
	return 0;
}
