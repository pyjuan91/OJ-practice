#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> b(n - 1), a(n);
		for (int i = 0; i < n - 1; i++) cin >> b[i];
		for (int i = 0, j = 0; i < n - 2; i++) {
			if (b[i] >= b[i + 1]) {
				if (j > i && a[j - 1] == b[i]) { continue; }
				else {
					a[j] = b[i];
					j++;
				}
			}
			else {
				if (j > i && a[j - 1] <= b[i]) {
					a[j] = b[i];
					j += 1;
				}
				else {
					a[j] = b[i];
					a[j + 1] = 0;
					j += 2;
				}
			}
		}
		a[n - 1] = b[n - 2];
		for (int i = 0; i < n; i++) {
			if (i) cout << " ";
			cout << a[i];
		}
		cout << "\n";
	}
	return 0;
}