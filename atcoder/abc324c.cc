#include <bits/stdc++.h>
using namespace std;
bool check(const string& s, const string& t) {
	int n = s.size(), m = t.size();
	if (abs(n - m) > 1) return false;
	if (n == m) {
		int diff_cnt = 0;
		for (int i = 0; i < n; i++)
			if (s[i] != t[i]) diff_cnt++;
		return diff_cnt <= 1;
	}
	if (n > m) return check(t, s);
	int addition = m - 1;
	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			addition = i;
			break;
		}
	}
	return s == (t.substr(0, addition) + t.substr(addition + 1));
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	string s, t;
	cin >> n >> s;
	vector<int> res;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		if (check(s, t)) res.push_back(i);
	}
	cout << res.size() << '\n';
	for (auto i : res) cout << i << ' ';
	return 0;
}
