#include <bits/stdc++.h>
using namespace std;
int find_diff(int* org, int* trans) {
	for (int i = 1; i < 10; i++)
		if (trans[i] > org[i]) return i;
	return 0;
}
int32_t main() {
	int t, n, *a, *org, *trans;
	cin >> t;
	while (t--) {
		cin >> n;
		a = new int[n];
		org = new int[10]();

		for (int i = 0; i < n; i++) cin >> a[i], org[a[i]]++;

		auto check = 0;
		while (check == 0) {
			cout << "- 0\n";
			cout.flush();
			delete[] trans;
			trans = new int[10]();
			for (int i = 0; i < n; i++)
				cin >> a[i], trans[a[i]]++;
			check = find_diff(org, trans);
		}

		cout << "- " << n - trans[check];
		for (int i = 0; i < n; i++)
			if (a[i] != check) cout << " " << i + 1;
		cout << "\n";
		cout.flush();

		n = trans[check];
		trans[check] = 0;
		for (int i = 0; i < n; i++) cin >> a[i], trans[a[i]]++;
		if (trans[check] == n) {
			cout << "- 0\n";
			cout.flush();
			for (int i = 0; i < n; i++) cin >> a[i];
		}
		for (int i = 0; i < n; i++)
			if (a[i] != check) cout << "! " << i + 1 << "\n";
		cout.flush();

		delete[] org;
		delete[] a;
	}
	return 0;
}