#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, w, h;
	cin >> t;
	while (t--) {
		cin >> n;
		map<int, vector<pii>> m;
		for (int i = 0; i < n; i++) {
			cin >> w >> h;
			if (w > h) swap(w, h);
			m[w].emplace_back(make_pair(h, i));
		}
		vector<int> ans(n, -2);
		pii small_person = make_pair(1e9 + 5, 1e9 + 5);
		for (auto p : m) {
			pii for_swap = small_person;
			for (auto x : p.second) {
				if (x.first > small_person.first)
					ans[x.second] = small_person.second;
				if (x.first < for_swap.first) for_swap = x;
			}
			swap(for_swap, small_person);
		}
		for (auto a : ans) cout << a + 1 << " ";
		cout << "\n";
	}
	return 0;
}