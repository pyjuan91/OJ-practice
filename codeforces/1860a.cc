#include <bits/stdc++.h>
using namespace std;
void chaewon(size_t len, string& s, int left, bool& solved, string& cant) {
	if (solved) return;
	if (s.length() == len) {
		solved = true;
		return;
	}
	if (left > 0) {
		s.push_back(')');
		if (
		  s.length() < cant.length() || !strstr(s.c_str(), cant.c_str()))
			chaewon(len, s, left - 1, solved, cant);
		if (solved) return;
		s.pop_back();
	}
	if (s.length() + left > len) return;
	s.push_back('(');
	if (s.length() < cant.length() || !strstr(s.c_str(), cant.c_str()))
		chaewon(len, s, left + 1, solved, cant);
	if (solved) return;
	s.pop_back();
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		size_t len = s.length();
		bool solved = false;
		string res = "";
		chaewon(len * 2, res, 0, solved, s);
		if (solved) cout << "YES\n" << res << '\n';
		else cout << "NO\n";
	}
	return 0;
}
