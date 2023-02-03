#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	map<char, pair<int, int>> dir;
	dir['L'] = {-1, 0};
	dir['R'] = {1, 0};
	dir['U'] = {0, 1};
	dir['D'] = {0, -1};
	int t, n;
	char c;
	cin >> t;
	while (t--) {
		cin >> n;
		bool candy = false;
		pair<int, int> pos = {0, 0};
		for (int i = 0; i < n; i++) {
			cin >> c;
			pos.first += dir[c].first;
			pos.second += dir[c].second;
			if (pos == make_pair(1, 1)) candy = true;
		}
		if (candy) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}