#include <bits/stdc++.h>
#define int long long
using namespace std;
string trans1(const string& s) {
	int nu1 = 0, id = 1, nu2 = 0;
	while (id < s.length() && isdigit(s[id])) {
		nu1 = nu1 * 10 + s[id] - '0';
		id++;
	}
	id++;
	while (id < s.length() && isdigit(s[id])) {
		nu2 = nu2 * 10 + s[id] - '0';
		id++;
	}
	string res;
	while (nu2) {
		char c = 'A' + ((nu2 + 25) % 26);
		if (nu2 % 26 == 0) nu2 -= 26;
		res += c;
		nu2 /= 26;
	}
	reverse(res.begin(), res.end());
	res += to_string(nu1);
	return res;
}
string trans2(const string& s) {
	string pre, res = "R";
	int nu = 0, id = 0;
	while (id < s.length() && isalpha(s[id])) {
		pre += s[id];
		id++;
	}
	while (id < s.length() && isdigit(s[id])) {
		nu = nu * 10 + s[id] - '0';
		id++;
	}
	res += to_string(nu) + "C";
	nu = 0;
	for (int i = 0; i < pre.length(); i++)
		nu = nu * 26 + pre[i] - 'A' + 1;
	return res + to_string(nu);
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		auto checker = [&](const string& s) {
			int id = 0;
			while (id < s.length() && isalpha(s[id])) { id++; }
			while (id < s.length() && isdigit(s[id])) { id++; }
			if (id < s.length()) return true;
			return false;
		};
		if (checker(s)) cout << trans1(s) << '\n';
		else cout << trans2(s) << '\n';
	}
	return 0;
}
