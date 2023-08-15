#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, res, left_zero, right_zero;
	bool contain_one, contain_two, first = true;
	res = left_zero = right_zero = 0;
	contain_one = contain_two = false;
	cin >> n;
	vector<int> a(n);
	for (auto& x : a) cin >> x;
	int index = 0;
	auto eat_zero = [&]() {
		int res = 0;
		while (index < n && a[index] == 0) {
			++res;
			++index;
		}
		return res;
	};
	auto eat_one_two = [&]() {
		while (index < n) {
			if (a[index] == 1) {
				contain_one = true;
				++index;
			}
			else if (a[index] == 2) {
				contain_two = true;
				++index;
			}
			else { break; }
		}
	};
	for (;;) {
		if (first) {
			first = false;
			left_zero = eat_zero();
			if (index == n) {
				res += left_zero;
				break;
			}
		}
		eat_one_two();
		res += 1;
		if (left_zero != 0) {
			res += left_zero - 1;
			if (!contain_two) contain_one = false;
			left_zero = 0;
		}
		if (index == n) break;
		right_zero = eat_zero();
		if (contain_one || contain_two) right_zero -= 1;
		contain_one = contain_two = false;
		if (index == n) {
			res += right_zero;
			break;
		}
		else left_zero = right_zero;
	}
	cout << res;
	return 0;
}
