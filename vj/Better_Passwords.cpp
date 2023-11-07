#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s, res;
	cin >> s;
	bool first = true;
	for (auto c : s) {
		if (first) {
			res.push_back(toupper(c));
			first = false;
			continue;
		}
		if (c == 's') res.append("$");
		else if (c == 'i') res.append("!");
		else if (c == 'o') res.append("()");
		else res.push_back(c);
	}
	res.append(".");
	cout << res;
	return 0;
}
