#include <bits/stdc++.h>
using namespace std;
int n, a[4];
int main() {
	cin >> n >> a[0] >> a[1] >> a[2] >> a[3];
	bool cond1 = (abs(a[1] - a[2]) <= 1);
	bool cond2
		= !(a[0] && a[3] && a[1] == a[2] && a[1] == 0);
	if (cond1 && cond2) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}