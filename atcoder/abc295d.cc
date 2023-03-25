#include <bits/stdc++.h>
using namespace std;
int main() {
#define int long long
	cin.tie()->sync_with_stdio(false);
	string s;
	int res = 0, prefix = 0;
	map<int, int> m;
	m[0] = 1;
	cin >> s;
	for (auto& c : s) {
		prefix ^= 1LL << (c - '0');
		res += m[prefix];
		m[prefix] += 1;
	}
	cout << res;
	return 0;
}