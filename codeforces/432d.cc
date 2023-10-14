#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	// KMP build nxt
	vector<int> nxt(n);
	for (int i = 1, j = 0; i < n; ++i) {
		while (j && s[i] != s[j]) j = nxt[j - 1];
		if (s[i] == s[j]) ++j;
		nxt[i] = j;
	}
	// count the number of different substrings
	vector<int> cnt(n, 0);
	for (int i = 0; i < n; ++i) ++cnt[nxt[i]];
	for (int i = n - 1; i; --i)
		if (nxt[i - 1]) cnt[nxt[i - 1]] += cnt[i];
	// output
	vector<pair<int, int>> res;
	int index = n - 1;
	while (nxt[index]) {
		res.emplace_back(nxt[index], cnt[nxt[index]] + 1);
		index = nxt[index] - 1;
	}
	reverse(res.begin(), res.end());
	cout << res.size() + 1 << '\n';
	for (auto [len, cnt] : res)
		cout << len << ' ' << cnt << '\n';
	cout << n << ' ' << 1 << '\n';
	return 0;
}