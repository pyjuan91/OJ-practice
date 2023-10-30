#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string a, b;
	cin >> a >> b;
	a.append(b);
	int ans = stoi(a);
	int sq = sqrt(ans);
	cout << (sq * sq == ans ? "Yes" : "No");
	return 0;
}
