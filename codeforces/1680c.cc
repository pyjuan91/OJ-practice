#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	string s;
	cin >> t;
	auto chaewon = [&](string& s) {
		int len = s.length();
		s = " " + s;
		vector<int> ones(len + 1, 0);
		for (int i = 1; i <= len; i++) {
			if (s[i] == '1') ones[i] = 1;
			ones[i] += ones[i - 1];
		}
		int res = ones[len], windows = ones[len];
		for (int i = windows; i <= len; i++) {
			res = min(res, windows - (ones[i] - ones[i - windows]));
		}
        return res;
	};
	while (t--) {
		cin >> s;
		cout << chaewon(s) << "\n";
	}
	return 0;
}
