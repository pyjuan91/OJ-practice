#include <bits/stdc++.h>
using namespace std;
vector<int> pi(const string &s) {
	int n = (int) s.size();
	vector<int> pi_s(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && s[j] != s[i]) { j = pi_s[j - 1]; }
		if (s[i] == s[j]) { j++; }
		pi_s[i] = j;
	}
	return pi_s;
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	auto pi_s = pi(s);
	int ma = INT32_MIN;
	if (s.length() < 3) {
		cout << "Just a legend\n";
		return 0;
	}
	for (int i = 1; i < s.length() - 1; i++)
		ma = max(ma, pi_s[i]);
	int res = pi_s[s.length() - 1];
	if (res > ma) res = pi_s[res - 1];
	if (res == 0) cout << "Just a legend\n";
	else cout << s.substr(0, res) << '\n';
	return 0;
}