#include <bits/stdc++.h>
#ifdef LOCAL
#	include "./debug.cc"
#else
#	define debug(...)
#	define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	set<int> lines = {0, INT64_MAX};
	map<int, int> dist_record;
	dist_record[0] = INT32_MAX;
	dist_record[INT64_MAX] = 0;
	int dist_sum = INT32_MAX;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		auto iter = lines.lower_bound(x);
		auto left = prev(iter);
		auto right = iter;
		// debug(x, *left, *right);
		dist_record[x] = min(x - *left, *right - x);
		// debug(x - *left, *right - x);
		dist_sum += dist_record[x];
		if (x - *left < dist_record[*left]) {
			dist_sum -= dist_record[*left];
			dist_record[*left] = x - *left;
			dist_sum += dist_record[*left];
		}
		if (*right - x < dist_record[*right]) {
			dist_sum -= dist_record[*right];
			dist_record[*right] = *right - x;
			dist_sum += dist_record[*right];
		}
		cout << dist_sum << "\n";
		lines.insert(x);
	}
	return 0;
}
