#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, d;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> d >> s;
		char ins = '0' + d;
		vector<char> res;
		for (auto c : s) {
			if (c < ins) res.emplace_back(ins), ins = '$';
			res.emplace_back(c);
		}
		if (ins != '$') res.emplace_back(ins);
		for (auto c : res) cout << c;
		cout << '\n';
	}
	return 0;
}
