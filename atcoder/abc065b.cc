#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, res = 0, cur = 1;
	cin >> n;
	vector<int> a(n + 1);
	vector<bool> used(n + 1, false);
	for (int i = 1; i <= n; i++) cin >> a[i];
	while (cur != 2) {
		if (used[cur]) {
			cout << -1;
			return 0;
		}
		used[cur] = true;
		res += 1;
		cur = a[cur];
	}
	cout << res;
	return 0;
}