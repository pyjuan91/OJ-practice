#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n);
		for (auto &x : a) cin >> x;
		int ma = 0, right = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] > ma) {
				ma = a[i];
				right = i;
			}
		}

		if (right == 1) {
			for (int i = 1; i < n; i++) cout << a[i] << " ";
			cout << a[0] << "\n";
		}
		else if (right == n - 1) {
			int left = right;
			while (left - 1 > 0 && a[left - 1] > a[0])
				left -= 1;
			for (int i = right + 1; i < n; i++)
				cout << a[i] << " ";
			for (int i = right; i >= left; i--)
				cout << a[i] << " ";
			for (int i = 0; i < left; i++) cout << a[i] << " ";
			cout << "\n";
		}
		else {
			right--;
			int left = right;
			while (left - 1 > 0 && a[left - 1] > a[0])
				left -= 1;
			for (int i = right + 1; i < n; i++)
				cout << a[i] << " ";
			for (int i = right; i >= left; i--)
				cout << a[i] << " ";
			for (int i = 0; i < left; i++) cout << a[i] << " ";
			cout << "\n";
		}
	}
	return 0;
}