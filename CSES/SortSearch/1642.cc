#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, x;
	vector<pair<int, int>> a;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		a.emplace_back(make_pair(x, i));
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int left = j + 1, right = n - 1,
				tar = m - a[i].first - a[j].first;
			while (left < right) {
				int cs = a[left].first + a[right].first;
				if (cs == tar) {
					cout << a[i].second << " " << a[j].second
						 << " " << a[left].second << " "
						 << a[right].second << "\n";
					return 0;
				}
				else if (cs < tar) left++;
				else right--;
			}
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}