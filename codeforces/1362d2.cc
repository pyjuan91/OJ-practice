#include <bits/stdc++.h>
using namespace std;
vector<int> BuildNext(const string& target) {
	vector<int> next(target.size() + 1, 0);
	next[0] = -1;
	size_t cur = 0;
	int k = -1;
	while (cur < target.size()) {
		if (k == -1 || target[cur] == target[k]) {
			++cur;
			++k;
			next[cur] = k;
		}
		else { k = next[k]; }
	}
	return next;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		int pre = 0;
		while (pre < s.length() / 2 && s[pre] == s[s.length() - pre - 1])
			pre += 1;
		string pre_str = s.substr(0, pre);
		s = s.substr(pre, s.length() - 2 * pre);
		string rev_s = s;
		reverse(rev_s.begin(), rev_s.end());
		string chaewon = s + "#" + rev_s;
		// cout << "chaewon = " << chaewon << '\n';
		auto nxt1 = BuildNext(chaewon);
		// for (auto x : nxt1) cout << x << ' ';
		// cout << '\n';
		chaewon = rev_s + "#" + s;
		// cout << "chaewon = " << chaewon << '\n';
		auto nxt2 = BuildNext(chaewon);
		// for (auto x : nxt2) cout << x << ' ';
		// cout << '\n';
		// cout << "nxt1.back() = " << nxt1.back() << '\n';
		// cout << "nxt2.back() = " << nxt2.back() << '\n';
		cout << pre_str;
		if (nxt2.back() > nxt1.back())
			cout << s.substr(s.length() - nxt2.back(), nxt2.back());
		else cout << s.substr(0, nxt1.back());
		reverse(pre_str.begin(), pre_str.end());
		cout << pre_str << '\n';
	}
	return 0;
}