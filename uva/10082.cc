#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	const string kb1 = "`1234567890-=";
	const string kb2 = "QWERTYUIOP[]\\";
	const string kb3 = "ASDFGHJKL;'";
	const string kb4 = "ZXCVBNM,./";
	map<char, char> mp;
	for (int i = 1; i < (int) kb1.length(); ++i)
		mp[kb1[i]] = kb1[i - 1];
	for (int i = 1; i < (int) kb2.length(); ++i)
		mp[kb2[i]] = kb2[i - 1];
	for (int i = 1; i < (int) kb3.length(); ++i)
		mp[kb3[i]] = kb3[i - 1];
	for (int i = 1; i < (int) kb4.length(); ++i)
		mp[kb4[i]] = kb4[i - 1];
	while (getline(cin, s)) {
		for (char c : s) { cout << (mp.count(c) ? mp[c] : c); }
		cout << '\n';
	}
	return 0;
}
