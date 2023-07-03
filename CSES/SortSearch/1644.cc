#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, a, b, x, res = INT64_MIN;
	cin >> n >> a >> b;
	vector<int> prefix = {0};
	multiset<int> ms;
	for (int i = 1; i <= n; i++)
		cin >> x, prefix.emplace_back(prefix[i - 1] + x);
	for (int i = a; i <= n; i++) {
		ms.insert(prefix[i - a]);
		res = max(res, prefix[i] - *ms.begin());
		if (i >= b) ms.erase(ms.find(prefix[i - b]));
	}
	cout << res;
	return 0;
}