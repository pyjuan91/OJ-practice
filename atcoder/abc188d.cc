#include <bits/stdc++.h>
using namespace std;
int main() {
#define int long long
	cin.tie()->sync_with_stdio(false);
	int N, C, res = 0, a, b, c, prefix = 0, pre = 0;
	map<int, int> m;
	cin >> N >> C;
	while (N--) {
		cin >> a >> b >> c;
		m[a] += c;
		m[b + 1] -= c;
	}
	for (auto e : m) {
		res += min(prefix, C) * (e.first - pre);
		pre = e.first;
		prefix += e.second;
	}
	cout << res;
	return 0;
}