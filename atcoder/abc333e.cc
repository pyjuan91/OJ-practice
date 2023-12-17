#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
vector<int> potion_pos[maxn];
vector<pair<int, int>> monsters, events = {{0, 0}};
vector<int> potion(maxn, false);
int n, t, x, cur_potions = 0, ma_postions = INT32_MIN;

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t >> x;
		events.emplace_back(t, x);
		if (t == 1) potion_pos[x].emplace_back(i);
		else monsters.emplace_back(i, x);
	}

	// for (int i = 1; i <= 3; i++) {
	// 	for (auto x : potion_pos[i]) cout << x << ' ';
	// 	cout << '\n';
	// }

	// cout << '\n';
	// for (auto x : monsters)
	// 	cout << x.first << ' ' << x.second << '\n';

	reverse(monsters.begin(), monsters.end());
	for (auto monster : monsters) {
		int pos = monster.first, tp = monster.second;
		while (!potion_pos[tp].empty() && potion_pos[tp].back() > pos) {
			potion[potion_pos[tp].back()] = false;
			potion_pos[tp].pop_back();
		}
		if (!potion_pos[tp].empty()) {
			potion[potion_pos[tp].back()] = true;
			potion_pos[tp].pop_back();
		}
		else {
			cout << "-1\n";
			return 0;
		}
	}

	vector<int> potion_state;
	for (int i = 1; i <= n; i++) {
		int t = events[i].first, x = events[i].second;
		if (t == 1) {
			if (potion[i])
				cur_potions++, potion_state.emplace_back(1);
			else potion_state.emplace_back(0);
			ma_postions = max(ma_postions, cur_potions);
		}
		else cur_potions--;
	}

	cout << ma_postions << '\n';
	for (auto x : potion_state) cout << x << ' ';
	cout << '\n';

	return 0;
}
