#include <bits/stdc++.h>
#define int long long
using namespace std;
string chaewon(string& s) {
	if (s.length() == 1) return s;
	string l = "", r = "";
	sort(s.begin(), s.end());
	for (int i = 0; i < (int) s.length(); i++) {
		if (i + 1 < (int) s.length() && s[i] == s[i + 1]) {
			l.append(1u, s[i + 1]);
			r.append(1u, s[i++]);
		}
		else if (i + 1 < s.length() && s[i + 1] == s[s.length() - 1]) {
			l += string(ceil((double) (s.length() - i - 1) / 2.0), s[i + 1])
			   + s[i]
			   + string(floor((double) (s.length() - i - 1) / 2.0), s[i + 1]);
			break;
		}
		else {
			r.append(1u, s[i]);
			for (int j = i + 1; j < s.length(); j++)
				l.append(1u, s[j]);
			break;
		}
	}
	reverse(r.begin(), r.end());
	return l + r;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		cout << chaewon(s) << "\n";
	}
	return 0;
}