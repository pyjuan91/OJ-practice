#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n, x, num, target, left, right;
	cin >> n >> x;
	vector<pii> a;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		a.emplace_back(make_pair(num, i));
	}
	sort(a.begin(), a.end());
	for (int i = 0; i <= n - 3; i++) {
		if (a[i].first >= x) break;
		target = x - a[i].first;
		left = i + 1, right = n - 1;
		while (left < right) {
			if (a[left].first + a[right].first == target) {
				cout << a[i].second << " " << a[left].second
					 << " " << a[right].second;
				return 0;
			}
			else if (a[left].first + a[right].first > target)
				right -= 1;
			else left += 1;
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}