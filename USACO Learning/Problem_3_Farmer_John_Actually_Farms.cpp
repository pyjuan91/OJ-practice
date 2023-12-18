#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn], b[maxn];
pair<int, int> t[maxn];
int kase, n;

int32_t main() {
	// cin.tie(nullptr)->sync_with_stdio(false);
	cin >> kase;

	while (kase--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		for (int i = 0; i < n; i++)
			cin >> t[i].first, t[i].second = i;

		sort(t, t + n, [&](const pair<int, int>& a, const pair<int, int>& b) {
			return a.first < b.first;
		});

		int bound = 0;
		for (int i = 1; i < n; i++) {
			int big = t[i - 1].second, small = t[i].second;
			if (a[big] + bound * b[big] > a[small] + bound * b[small])
				continue;

			// bound * (b[big] - b[small]) > a[small] - a[big]

			if (b[big] <= b[small]) {
				cout << "-1\n";
				goto end;
			}

			if (b[big] > b[small]) {
				int tmp = (a[small] - a[big]) / (b[big] - b[small]) + 1;
				if (tmp <= bound) {
					cout << "-1\n";
					goto end;
				}
				bound = tmp;
			}
		}
		cout << bound << '\n';
	end:;
	}
	return 0;
}
