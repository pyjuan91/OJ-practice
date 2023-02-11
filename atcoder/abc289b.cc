#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n, m, x, j = 0;
	cin >> n >> m;
	vector<int> a(m), buffer;
	for (int i = 0; i < m; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		if (j < m && i == a[j]) {
			buffer.emplace_back(i);
			j++;
		}
		else {
			cout << i << " ";
			while (!buffer.empty()) {
				cout << buffer.back() << " ";
				buffer.pop_back();
			}
		}
	}
	return 0;
}