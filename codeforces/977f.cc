#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int n;
	cin >> n;
	map<int, int> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		if (m.count(a[i] - 1)) m[a[i]] = m[a[i] - 1] + 1;
		else m[a[i]] = 1;
	}
	int ma_len = 0, ma_id;
	for (auto p : m)
		if (p.second > ma_len) {
			ma_len = p.second;
			ma_id = p.first;
		}
	cout << ma_len << "\n";
	int beg = ma_id - ma_len + 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == beg) {
			cout << i << " ";
			beg += 1;
		}
	}
	return 0;
}