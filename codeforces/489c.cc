#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int d, s;
	cin >> d >> s;
	vector<int> smallest(d, 0), greatest(d, 9);
	smallest[0] = 1;
	int smallestSum = 1, greatestSum = 9 * d;
	if (smallestSum > s || greatestSum < s) {
		cout << "-1 -1\n";
		return 0;
	}
	for (int i = d - 1; i >= 0; i--) {
		if (smallestSum != s) {
			int diff = s - smallestSum;
			if (diff >= 9) smallest[i] = 9, smallestSum += 9;
			else smallest[i] += diff, smallestSum += diff;
		}
	}
	for (int i = d - 1; i >= 0; i--) {
		if (greatestSum != s) {
			int diff = greatestSum - s;
			if (diff >= 9) greatest[i] = 0, greatestSum -= 9;
			else greatest[i] -= diff, greatestSum -= diff;
		}
	}
	for (int i = 0; i < d; i++) cout << smallest[i];
	cout << " ";
	for (int i = 0; i < d; i++) cout << greatest[i];
	return 0;
}
