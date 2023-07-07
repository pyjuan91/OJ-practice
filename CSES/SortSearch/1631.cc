#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, ps = 0;
	cin >> n;
	vector<int> books(n);
	for (auto &x : books) cin >> x;
	sort(books.begin(), books.end());
	if (n == 1) {
		cout << 2 * books[0] << "\n";
		return 0;
	}
	for (int i = 0; i < n - 1; i++) ps += books[i];
	if (ps <= books[n - 1]) {
		cout << 2 * books[n - 1] << "\n";
		return 0;
	}
	cout << ps + books[n - 1] << "\n";
	return 0;
}