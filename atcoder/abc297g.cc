#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, l, r, x, res = 0;
	cin >> n >> l >> r;
	while (n--) {
		cin >> x;
		res ^= (x % (l + r)) / l;
	}
	if (res) cout << "First";
	else cout << "Second";  
	return 0;
}