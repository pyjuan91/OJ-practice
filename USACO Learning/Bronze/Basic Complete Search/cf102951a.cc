#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n, res = 0;
	cin >> n;
	vector<pair<int, int>> p(n);
	for (int i = 0; i < n; i++) cin >> p[i].first;
	for (int i = 0; i < n; i++) cin >> p[i].second;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int dis = pow(abs(p[i].first - p[j].first), 2)
							+ pow(abs(p[i].second - p[j].second), 2);
			res = max(res, dis);
		}
	}
	cout << res;
	return 0;
}