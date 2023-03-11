#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1), called(n + 1, 0), ans;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
		if (called[i] == false) called[a[i]] = true;
	for (int i = 1; i <= n; i++)
		if (called[i] == false) ans.emplace_back(i);
	cout << ans.size() << "\n";
	bool first = true;
	for (auto i : ans) {
		if (first) first = false;
		else cout << " ";
		cout << i;
	}
	return 0;
}