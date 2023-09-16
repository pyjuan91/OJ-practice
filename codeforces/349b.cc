#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int v, cost[10] = {}, mi;
	cin >> v;
	for (int i = 1; i <= 9; i++) cin >> cost[i];
	vector<int> res;
	mi = *min_element(cost + 1, cost + 10);
	int target = v / mi;
	if (target == 0) {
		cout << -1 << '\n';
		return 0;
	}
	for (int i = 0; i < target; i++) {
		for (int j = 9; j >= 1; j--) {
			if (v >= cost[j] && (v - cost[j]) / mi == target - i - 1) {
				res.push_back(j);
				v -= cost[j];
				break;
			}
		}
	}
    for (int i : res) cout << i;
	return 0;
}
