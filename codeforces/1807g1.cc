#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.end());
		if (n == 1) {
			if (a[0] == 1) cout << "YES\n";
			else cout << "NO\n";
		}
		else if (n == 2) {
			if (a[0] == 1 && a[1] == 1) cout << "YES\n";
			else cout << "NO\n";
		}
		else {
			if (a[0] != 1 || a[1] != 1) cout << "No\n";
			else {
				vector<bool> su(5005, false);
				su[1] = su[2] = true;
				bool yes = true;
				for (int i = 2; i < n; i++) {
					if (su[a[i]] == false) {
						yes = false;
						break;
					}
					for (int j = 5000; j >= 0; j--) {
						if (su[j])
							su[min(5000, j + a[i])] = true;
					}
				}
				if (yes) cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}
	return 0;
}