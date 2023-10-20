#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, lent, lens;
	long long res = 0;
	string t;
	cin >> n >> t;
	lent = t.length();
	vector<string> s(n);
	vector<int> pref, suff;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		lens = s[i].length();
		int si = 0, ti = 0;
		while (si < lens && ti < lent) {
			if (s[i][si] == t[ti]) ti++;
			si++;
		}
		pref.push_back(ti);
		si = lens - 1, ti = lent - 1;
		while (si >= 0 && ti >= 0) {
			if (s[i][si] == t[ti]) ti--;
			si--;
		}
		suff.push_back(lent - ti - 1);
	}
	sort(suff.begin(), suff.end());
	for (auto x : pref) {
		auto it = lower_bound(suff.begin(), suff.end(), lent - x);
		res += suff.end() - it;
	}
	cout << res;
	return 0;
}
