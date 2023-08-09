#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	ifstream cin("paint.in");
	ofstream cout("paint.out");
	cin.tie(nullptr)->sync_with_stdio(false);
	pair<int, int> a, b;
	cin >> a.first >> a.second >> b.first >> b.second;
	if (a > b) swap(a, b);
	if (a.second >= b.second)
		cout << a.second - a.first << "\n";
	else if (a.second >= b.first)
		cout << b.second - a.first << "\n";
	else
		cout << a.second - a.first + b.second - b.first << "\n";
	return 0;
}
