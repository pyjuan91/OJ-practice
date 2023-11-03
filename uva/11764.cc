#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, pre, cur;
	cin >> t;
	for (int kase = 1; kase <= t; kase++) {
		cin >> n >> pre;
		int high = 0, low = 0;
		for (int i = 1; i < n; i++) {
			cin >> cur;
			if (cur > pre) high++;
			if (cur < pre) low++;
			pre = cur;
		}
		cout << "Case " << kase << ": " << high << " " << low << "\n";
	}
	return 0;
}
