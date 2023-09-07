#include <bits/stdc++.h>
using namespace std;
#define int long long
int cnt[300001], last[300001], a[300001];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, x, res = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		last[i] = -1, cnt[i] = a[i] = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (last[x] != -1) a[x] += (i - last[x] - 1) * cnt[x];
		last[x] = i;
		cnt[x] += 1;
		res += a[x];
	}
	cout << res << '\n';
	return 0;
}