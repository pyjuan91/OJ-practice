#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, t, c, r, fc;
	cin >> n >> t;
	vector<int> C(n), R(n);
	for (int i = 0; i < n; i++) cin >> C[i];
	for (int i = 0; i < n; i++) cin >> R[i];
	unordered_map<int, pair<int, int>> m;
	fc = C[0];
	r = R[0];
	m[fc] = make_pair(r, 1);
	for (int i = 1; i < n; i++) {
		c = C[i];
		r = R[i];
		if (!m.count(c)) m[c] = make_pair(r, i + 1);
		else if (m[c].first < r) m[c] = make_pair(r, i + 1);
	}
	if (!m.count(t)) cout << m[fc].second;
	else cout << m[t].second;
	return 0;
}