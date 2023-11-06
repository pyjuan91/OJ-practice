#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x : a) cin >> x;
	cout << *max_element(a.begin(), a.end());
	return 0;
}
