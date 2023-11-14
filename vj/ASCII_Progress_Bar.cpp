#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	double x;
	cin >> x;
	cout << "[";
	for (int i = 0; i < (int) x / 10; i++) cout << "+";
	for (int i = (int) x / 10; i < 10; i++) cout << ".";
	cout << "] " << (int) x << "%\n";
	return 0;
}
