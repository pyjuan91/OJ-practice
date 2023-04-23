#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll chaewon(string& s) {
	int ma = 0, len = s.length();
	for (int i = 0; i < len; i++) {
		int cur = 0;
		while (i < len && s[i] == '1') {
			cur += 1;
			i += 1;
		}
		ma = max(cur, ma);
	}
	if (ma == int(s.length())) return 1LL * ma * ma;

	int seq = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == '0') break;
		seq += 1;
	}
	for (int i = len - 1; i >= 0; i--) {
		if (s[i] == '0') break;
		seq += 1;
	}

	ma = max(seq, ma);

	if (ma % 2 == 0) return 1LL * (ma / 2) * (ma / 2 + 1);
	return 1LL * (ma / 2 + 1) * (ma / 2 + 1);
}
int main() {
	cin.tie()->sync_with_stdio(false);
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		cout << chaewon(s) << "\n";
	}
	return 0;
}