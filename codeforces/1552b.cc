#include <bits/stdc++.h>
using namespace std;
bool left_smaller_than_right(vector<int>& a, vector<int>& b) {
	int res = 0;
	for (int i = 0; i < 5; i++)
		if (a[i] > b[i]) res += 1;
	return res >= 3;
}
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<vector<int>> rank(n + 1, vector<int>(5));
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 5; j++) cin >> rank[i][j];
		auto ma = rank[1];
		auto ma_id = 1;
		for (int i = 2; i <= n; i++) {
			if (left_smaller_than_right(ma, rank[i])) {
				ma = rank[i];
				ma_id = i;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (i != ma_id && left_smaller_than_right(ma, rank[i])) {
				cout << "-1\n";
				goto chaewon;
			}
		}
		cout << ma_id << "\n";
	chaewon:;
	}
	return 0;
}