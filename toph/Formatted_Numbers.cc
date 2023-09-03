#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s, res = "";
	cin >> s;
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.length(); i += 3) {
		res.push_back(s[i]);
		if (i + 1 < s.length()) res.push_back(s[i + 1]);
		if (i + 2 < s.length()) res.push_back(s[i + 2]);
		res.push_back(',');
	}
    res.pop_back();
    reverse(res.begin(), res.end());
    cout << res << '\n';
	return 0;
}
