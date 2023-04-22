#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, cnt = 0, i = 0, ask;
	cin >> n;
	int left = 1, right = n;
	vector<int> s(n + 1, -1);
	s[n] = 1, s[1] = 0;
	while (left + 1 < right) {
		auto mid = left + (right - left) / 2;
		cout << "? " << mid << endl;
		cin >> ask;
		if (ask == 0) left = mid;
		else right = mid;
	}
	cout << "! " << left << endl;
	return 0;
}