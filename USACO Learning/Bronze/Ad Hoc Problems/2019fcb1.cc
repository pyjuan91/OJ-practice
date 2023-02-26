#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	int d1 = a[1] - a[0] - 1;
	int d2 = a[2] - a[1] - 1;
	if (d1 == d2 && d1 == 0) cout << "0\n0";
	else {
		if(d1 == 1 || d2 == 1) cout << 1;
        else cout << 2;
		cout << "\n";
		cout << max(d1, d2);
	}
	return 0;
}