#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> comb;
void gen(int cur, vector<int>& v) {
	if (v.size() == 5) {
		comb.push_back(v);
		return;
	}
	if (cur == 10) return;
	v.push_back(cur);
	gen(cur + 1, v);
	v.pop_back();
	gen(cur + 1, v);
}
void chaewon(int n) {
	vector<pair<int, int>> res;
	auto check = [](int numerator, int denominator) {
		int digits[10] = {}, dig = 0;
		while (numerator) {
			digits[numerator % 10]++;
			dig++;
			numerator /= 10;
		}
		if (dig != 4 && dig != 5) return false;
		if (dig == 4) digits[0]++;
		dig = 0;
		while (denominator) {
			digits[denominator % 10]++;
			dig++;
			denominator /= 10;
		}
		if (dig == 4) digits[0]++;
		for (int i = 0; i < 10; i++)
			if (digits[i] != 1) return false;
		return true;
	};
	auto dig_cnt = [](int n) {
		int cnt = 0;
		while (n) {
			cnt++;
			n /= 10;
		}
		return cnt;
	};
	for (auto x : comb) {
		do {
			int denominator = 0;
			for (auto y : x)
				denominator *= 10, denominator += y;
			int numerator = denominator * n;
			if (check(numerator, denominator)) {
				res.push_back(make_pair(numerator, denominator));
			}
		} while (next_permutation(x.begin(), x.end()));
	}
	if (res.size() == 0) {
		cout << "There are no solutions for " << n << ".\n";
		return;
	}
	sort(res.begin(), res.end());
	for (auto p : res) {
		if (dig_cnt(p.first) == 4) cout << "0";
		cout << p.first << " / ";
		if (dig_cnt(p.second) == 4) cout << "0";
		cout << p.second << " = " << n << '\n';
	}
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	bool first = true;
	auto v = vector<int>();
	gen(0, v);
	while (cin >> n && n) {
		if (first) first = false;
		else cout << '\n';
		chaewon(n);
	}
	return 0;
}
