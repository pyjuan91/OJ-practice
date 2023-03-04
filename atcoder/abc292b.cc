#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n, q, cmd, x;
	cin >> n >> q;
	vector<int> a(n + 1, 0);
	while (q--) {
		cin >> cmd >> x;
		if (cmd == 1) { a[x] += 1; }
		else if (cmd == 2) { a[x] += 2; }
		else {
			if (a[x] > 1) cout << "Yes\n";
			else cout << "No\n";
		}
	}
	return 0;
}