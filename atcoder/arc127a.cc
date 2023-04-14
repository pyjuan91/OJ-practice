#include <bits/stdc++.h>
using namespace std;
long long rec[18];
vector<int> digits(long long n) {
	if (n == 0) return {0};
	auto res = vector<int>();
	while (n) {
		res.emplace_back(n % 10LL);
		n /= 10LL;
	}
	return res;
}
int main() {
	cin.tie()->sync_with_stdio(false);
	long long n, res = 0;
	cin >> n;
	auto digit = digits(n);
	rec[0] = 1;
	for (int i = 1; i < 18; i++)
		rec[i] = pow(10, i) + rec[i - 1];
	for (size_t i = 0; i < digit.size() - 1; i++) res += rec[i];
	for (int i = int(digit.size()) - 1; i >= 0; i--) {
		if (digit[i] > 1) {
			res += rec[i];
			break;
		}
		if (digit[i] < 1) break;
		long long tmp = pow(10, i);
		res += n % tmp + 1;
	}
	cout << res;
	return 0;
}