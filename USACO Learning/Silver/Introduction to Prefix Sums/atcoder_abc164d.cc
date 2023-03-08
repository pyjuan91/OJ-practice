#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	string s;
	cin >> s;
	int powerOfTen = 1, suffix = 0, res = 0;
	vector<int> remain(2019, 0);
    remain[0] = 1;
	for (int i = s.length() - 1; i >= 0; i--) {
		suffix = (suffix + (s[i] - '0') * powerOfTen) % 2019;
		res += remain[suffix];
		remain[suffix] += 1;
		powerOfTen = (powerOfTen * 10) % 2019;
	}
	cout << res << "\n";
	return 0;
}