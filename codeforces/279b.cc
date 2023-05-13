#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, t, res = 0, left, right, cur_time;
	cin >> n >> t;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	left = -1, right = 0, cur_time = 0;
	while (right < n) {
		cur_time += a[right];
		while (cur_time > t && left < right)
			cur_time -= a[++left];
		res = max(res, right - left);
		right += 1;
	}
    cout << res;
	return 0;
}