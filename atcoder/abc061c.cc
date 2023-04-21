#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
#define int long long
	int n, k, a, b;
	map<int, int> m;
	cin >> n >> k;
	while (n--) {
		cin >> a >> b;
		m[a] += b;
	}
	auto iter = m.begin();
	for (iter = m.begin(); iter != m.end(); iter++) {
		k -= iter->second;
		if (k <= 0) break;
	}
	cout << iter->first;
	return 0;
}