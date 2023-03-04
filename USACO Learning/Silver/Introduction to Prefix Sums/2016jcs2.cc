#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n;
	cin >> n;
	vector<int> a(n + 1, 0);
	for (int i = 1; i < n + 1; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
		a[i] %= 7;
	}
	int sol = 7;
	vector<int> head(7, 0), tail(7, 0);
	for (int i = 1; i < n + 1; i++) {
		if (sol == 0) break;
		if (head[a[i]] == 0) {
			sol--;
			head[a[i]] = i;
		}
	}
	sol = 7;
	for (int i = n; i > 0; i--) {
		if (sol == 0) break;
		if (tail[a[i]] == 0) {
			sol--;
			tail[a[i]] = i;
		}
	}
	sol = 0;
	for (int i = 0; i < 7; i++) {
		sol = max(sol, tail[i] - head[i]);
	}
	cout << sol;
	return 0;
}