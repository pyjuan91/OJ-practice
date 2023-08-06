#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, x;
	cin >> n >> m;
	vector<int> cnt(m + 1, 0);
	while (n--) {
		cin >> x;
		if (x < m) cnt[x]++;
	}
	for (int i = 1; i < m; i++) {
		if (cnt[i] % (i + 1)) {
			cout << "No\n";
			return 0;
		}
		cnt[i + 1] += cnt[i] / (i + 1);
	}
    cout << "Yes\n";
	return 0;
}
