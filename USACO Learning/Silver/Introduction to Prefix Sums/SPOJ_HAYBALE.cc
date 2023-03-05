#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n, k, a, b;
	cin >> n >> k;
	vector<int> bay(n + 2, 0), sorted;
	while (k--) {
		cin >> a >> b;
		bay[a] += 1;
		bay[b + 1] -= 1;
	}
	for (int i = 1; i <= n; i++) {
		bay[i] += bay[i - 1];
		sorted.emplace_back(bay[i]);
	}
	sort(sorted.begin(), sorted.end());
	cout << sorted[n / 2];
	return 0;
}