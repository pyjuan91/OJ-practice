#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll chaewon(int n) {
	return 4LL * n + 1LL * n * (n - 1) / 2
		 + 1LL * (n - 1) * (n - 2) / 2 + 1LL;
}
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << chaewon(n) << "\n";
	}
	return 0;
}