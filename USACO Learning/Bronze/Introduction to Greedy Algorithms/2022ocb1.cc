#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n, res = 0;
	bool flip = false;
	cin >> n;
	vector<char> a(n + 1);
	for (int i = 1; i < n + 1; i++) cin >> a[i];
	for (int i = n; i > 1; i -= 2) {
		if (a[i] == a[i - 1]) continue;
		if (!flip) {
			if (a[i] == 'H' && a[i - 1] == 'G') {
				flip = true;
				res += 1;
			}
		}
		else {
			if (a[i] == 'G' && a[i - 1] == 'H') {
				flip = false;
				res += 1;
			}
		}
	}
    cout << res;
	return 0;
}