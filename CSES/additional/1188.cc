#include <bits/stdc++.h>
using namespace std;
int chaewon(set<int>& diff_point, multiset<int>& same_bit_range, int x, const int& n) {
	if (x == 0 || x == n) return *same_bit_range.rbegin();
	auto iter = diff_point.find(x);
	if (iter != diff_point.end()) {
		auto pr = prev(iter), ne = next(iter);
		same_bit_range.erase(same_bit_range.find(*iter - *pr));
		same_bit_range.erase(same_bit_range.find(*ne - *iter));
		same_bit_range.insert(*ne - *pr);
		diff_point.erase(iter);
	}
	else {
		diff_point.insert(x);
		iter = diff_point.find(x);
		auto pr = prev(iter), ne = next(iter);
		same_bit_range.erase(same_bit_range.find(*ne - *pr));
		same_bit_range.insert(*ne - *iter);
		same_bit_range.insert(*iter - *pr);
	}
	return *same_bit_range.rbegin();
}
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, m, x;
	string s;
	cin >> s >> m;
	n = s.length();
	set<int> diff_point;
	multiset<int> same_bit_range;
	diff_point.insert(0);
	for (int i = 0; i < n - 1; i++) {
		if (s[i] != s[i + 1]) {
			same_bit_range.insert(i + 1 - (*(diff_point.rbegin())));
			diff_point.insert(i + 1);
		}
	}
	same_bit_range.insert(n - (*(diff_point.rbegin())));
	diff_point.insert(n);
	while (m--) {
		cin >> x;
		chaewon(diff_point, same_bit_range, x - 1, n);
		cout << chaewon(diff_point, same_bit_range, x, n) << " ";
	}
	return 0;
}