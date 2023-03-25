#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, x, res = 0;
	unordered_map<int, int> m;
	cin >> n;
	while (n--) {
		cin >> x;
		m[x] += 1;
	}
	for (auto p : m) res += p.second / 2; 
    cout << res;
	return 0;
}