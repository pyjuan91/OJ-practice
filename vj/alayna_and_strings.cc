#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	int upper = 0, lower = 0;
	cin >> s;
	for (auto c : s) {
		if (isupper(c)) upper++;
		else if (islower(c)) lower++;
	}
	cout << upper << " " << lower << "\n";
	return 0;
}
