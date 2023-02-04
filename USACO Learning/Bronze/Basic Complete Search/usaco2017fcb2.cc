#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie();
	char c;
	int res = 0;
	vector<vector<int>> a(26);
	for (int i = 0; i < 52; i++) {
		cin >> c;
		a[c - 'A'].emplace_back(i);
	}
	for (int i = 0; i < 26; i++) {
		for (int j = i + 1; j < 26; j++) {
			bool cond1 = a[i][0] < a[j][0]
								&& a[j][0] < a[i][1]
								&& a[i][1] < a[j][1];
			bool cond2 = a[j][0] < a[i][0]
								&& a[i][0] < a[j][1]
								&& a[j][1] < a[i][1];
			if (cond1 || cond2) res += 1;
		}
	}
	cout << res;
	return 0;
}