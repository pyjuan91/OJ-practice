#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
int chaewon(string& s, bool rev_first = false, bool rev_last = false) {
	if (s.length() < 3) return -1;
	if (s.length() == 3) {
		if (s[1] != 'O') return -1;
		return (s[0] != 'M') + (s[2] != 'O');
	}
	if (mp.find(s) != mp.end()) return mp[s];
	// remove first
	int res = INT32_MAX;
	char first = s[0];
	s.erase(s.begin());
	// cout << s << endl;
	int tmp = chaewon(s, false, rev_last);
	if (tmp != -1) res = min(res, tmp + 1);
	s.insert(s.begin(), first);
	// cout << s << " " << res << endl;
	// remove last
	char last = s[s.length() - 1];
	s.pop_back();
	tmp = chaewon(s, rev_first, false);
	if (tmp != -1) res = min(res, tmp + 1);
	s.push_back(last);
	// cout << s << " " << res << e1ndl;
	// reverse first
	if (!rev_first) {
		if (s[0] == 'M') s[0] = 'O';
		else s[0] = 'M';
		tmp = chaewon(s, true, rev_last);
		if (tmp != -1) res = min(res, tmp + 1);
		if (s[0] == 'M') s[0] = 'O';
		else s[0] = 'M';
	}
	// reverse last
	if (!rev_last) {
		if (s[s.length() - 1] == 'M') s[s.length() - 1] = 'O';
		else s[s.length() - 1] = 'M';
		tmp = chaewon(s, rev_first, true);
		if (tmp != -1) res = min(res, tmp + 1);
		if (s[s.length() - 1] == 'M') s[s.length() - 1] = 'O';
		else s[s.length() - 1] = 'M';
	}
	res = res == INT32_MAX ? -1 : res;
	return mp[s] = res;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		cout << chaewon(s) << '\n';
		mp.clear();
	}
	return 0;
}
