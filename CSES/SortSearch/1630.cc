#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n, res = 0, ct = 0;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (auto &p : a) cin >> p.first >> p.second;
	sort(a.begin(), a.end());
	for (auto p : a) {
		ct += p.first;
		res += p.second - ct;
	}
    cout << res;
	return 0;
}