#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	vector<vector<int>> v(3);
	for (int i = 0; i < 3; i++) {
		cin >> s;
		for (auto c : s) v[i].push_back(c - 'a');
		reverse(v[i].begin(), v[i].end());
	}
	int turn = 0, nxt;
	for (;;) {
		if (v[turn].empty()) {
			cout << (char) ('A' + turn) << '\n';
			break;
		}
		nxt = v[turn].back();
		v[turn].pop_back();
		turn = nxt;
	}
	return 0;
}
