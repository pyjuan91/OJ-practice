#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	int need[3] = {}, have[3] = {}, price[3] = {}, robo;
	for (auto c : s) {
		if (c == 'B') need[0]++;
		else if (c == 'S') need[1]++;
		else need[2]++;
	}
	for (int i = 0; i < 3; i++) cin >> have[i];
	for (int i = 0; i < 3; i++) cin >> price[i];
	cin >> robo;
	int left = 0, right = 1e13, mid;
	while (left + 1 < right) {
		mid = (left + right) / 2;
		auto check = [&](int target) {
			int cost = 0;
			for (int i = 0; i < 3; i++) {
				cost += max(0LL, (target * need[i] - have[i])) * price[i];
			}
			return cost <= robo;
		};
		if (check(mid)) left = mid;
		else right = mid;
	}
	cout << left << '\n';
	return 0;
}