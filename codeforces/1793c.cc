#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, x;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) cin >> a[i];
		int left = 1, right = n, mi = 1, ma = n;
		while (left + 3 < right) {
			if (a[left] > mi && a[left] < ma && a[right] > mi && a[right] < ma)
				break;
			if (a[left] <= mi) {
				left += 1;
				mi += 1;
			}
			else if (a[left] >= ma) {
				left += 1;
				ma -= 1;
			}
			else if (a[right] <= mi) {
				right -= 1;
				mi += 1;
			}
			else if (a[right] >= ma) {
				right -= 1;
				ma -= 1;
			}
		}
		if (a[left] > mi && a[left] < ma && a[right] > mi && a[right] < ma)
			cout << left << " " << right << "\n";
		else cout << "-1\n";
	}
	return 0;
}