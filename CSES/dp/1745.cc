#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, x;
	cin >> n;
	set<int> s = {0};
	for (int i = 0; i < n; i++) {
		cin >> x;
		set<int> fs;
		for (auto num : s) fs.insert(num + x), fs.insert(num);
		swap(fs, s);
	}
	cout << s.size() - 1 << "\n";
	for (auto x : s)
		if (x) cout << x << " ";
	return 0;
}