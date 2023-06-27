#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, x;
	cin >> n;
	vector<pair<int, int>> v;
	v.push_back(make_pair(0, 0));
	for (int i = 1; i <= n; i++) {
		cin >> x;
		while (v.back().first >= x) v.pop_back();
		cout << v.back().second << " ";
		v.push_back(make_pair(x, i));
	}
	return 0;
}
