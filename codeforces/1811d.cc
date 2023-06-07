#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> fibo;
void init() {
	fibo.emplace_back(1);
	fibo.emplace_back(1);
	int a = 1, b = 1, c;
	for (int i = 2; i <= 45; i++) {
		c = a + b;
		fibo.emplace_back(c);
		a = b;
		b = c;
	}
}
bool cut(vector<pair<int, int>>& corners, int x, int y, int level) {
	auto ul = corners[0], ur = corners[1], dl = corners[2],
		 dr = corners[3];
	corners.clear();
	if (level <= 1) return true;
	auto height = dr.first - ur.first + 1,
		 width = ur.second - ul.second + 1;
	if (height == fibo[level]) {
		// test right
		if (y <= ul.second + fibo[level] - 1) {
			if (y >= ur.second - fibo[level] + 1) return false;
			else {
				corners.emplace_back(ul);
				corners.emplace_back(
				  make_pair(ur.first, ur.second - fibo[level]));
				corners.emplace_back(dl);
				corners.emplace_back(
				  make_pair(dl.first, dl.second - fibo[level]));
				return cut(corners, x, y, level - 1);
			}
		}
		// test left
		else {
			corners.emplace_back(
			  make_pair(ul.first, ul.second + fibo[level]));
			corners.emplace_back(ur);
			corners.emplace_back(
			  make_pair(dl.first, dl.second + fibo[level]));
			corners.emplace_back(dr);
			return cut(corners, x, y, level - 1);
		}
	}
	else if (width == fibo[level]) {
		// test down
		if (x <= ul.first + fibo[level] - 1) {
			if (x >= dl.first - fibo[level] + 1) return false;
			else {
				corners.emplace_back(ul);
				corners.emplace_back(ur);
				corners.emplace_back(
				  make_pair(dl.first - fibo[level], dl.second));
				corners.emplace_back(
				  make_pair(dr.first - fibo[level], dr.second));
				return cut(corners, x, y, level - 1);
			}
		}
		else {
			corners.emplace_back(make_pair(ul.first + fibo[level], ul.second));
			corners.emplace_back(make_pair(ur.first + fibo[level], ur.second));
			corners.emplace_back(dl);
			corners.emplace_back(dr);
			return cut(corners, x, y, level - 1);
		}
	}
	return false;
}
void chaewon(int n, int x, int y) {
	vector<pair<int, int>> corners;
	corners.emplace_back(make_pair(1, 1));
	corners.emplace_back(make_pair(1, fibo[n + 1]));
	corners.emplace_back(make_pair(fibo[n], 1));
	corners.emplace_back(make_pair(fibo[n], fibo[n + 1]));
	if (cut(corners, x, y, n)) cout << "YES\n";
	else cout << "NO\n";
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, x, y;
	init();
	cin >> t;
	while (t--) {
		cin >> n >> x >> y;
		chaewon(n, x, y);
	}
	return 0;
}