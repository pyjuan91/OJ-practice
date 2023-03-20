#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<int> b(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n; i > 0; i--) {
		int sum = 0;
		for (int j = i; j <= n; j += i) sum += b[j];
		if (sum % 2 != a[i]) b[i] = 1;
	}
	vector<int> res;
	for (int i = 1; i <= n; i++)
		if (b[i] == 1) res.emplace_back(i);

	cout << res.size() << "\n";
	bool first = true;
	for (auto i : res) {
		if (first) first = false;
		else cout << " ";
		cout << i;
	}
	return 0;
}