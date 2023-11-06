#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, prev, x;
	bool ascending = true;
	cin >> n >> prev;
	for (int i = 1; i < n; i++) {
		cin >> x;
		if (x < prev) ascending = false;
		prev = x;
	}
    cout << (ascending ? "Yes" : "No");
	return 0;
}
