#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	string s1, s2;
	auto merge = [&](string& s1, string& s2) {
		// KMP build nxt
		int pos = max((int) s1.size() - (int) s2.size(), 0);
		string s = s2 + "#"
				 + s1.substr(pos);
		int n = s.size();
		vector<int> nxt(n);
		for (int i = 1, j = 0; i < n; ++i) {
			while (j && s[i] != s[j]) j = nxt[j - 1];
			if (s[i] == s[j]) ++j;
			nxt[i] = j;
		}
		while (nxt[n - 1]) s1.pop_back(), nxt[n - 1]--;
		s1 += s2;
	};
	cin >> n >> s1;
	for (int i = 1; i < n; i++) {
		cin >> s2;
		merge(s1, s2);
	}
	cout << s1;
	return 0;
}
