#include <bits/stdc++.h>
#define int long long
using namespace std;
void chaewon(int& n) {
	vector<int> considered;
	int mul = 1;
	for (int i = 1; i < n; i++)
		if (gcd(i, n) == 1) {
			considered.emplace_back(i);
			mul = (mul * i) % n;
		}
	if (mul != 1) {
		cout << considered.size() - 1 << "\n";
		for (auto& x : considered)
			if (x != mul) cout << x << " ";
	}
	else {
		cout << considered.size() << "\n";
		for (auto& x : considered) cout << x << " ";
	}
}
signed main() {
	cin.tie()->sync_with_stdio(false);
	int n;
	cin >> n;
	chaewon(n);
	return 0;
}