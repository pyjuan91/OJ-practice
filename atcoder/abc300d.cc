#include <bits/stdc++.h>
using namespace std;
const int MAXN = 316228;
std::vector<int> prime;
bool is_composite[MAXN];
void sieve(int n) {
	std::fill(is_composite, is_composite + n, false);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.push_back(i);
		for (int j = 0; j < (int) prime.size() && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	sieve(MAXN);
	unsigned long long n, a, b, c, res = 0, one = 1;
	cin >> n;
	size_t sz = prime.size();
	for (size_t i = 0; i < sz; i++) {
		a = one * prime[i] * prime[i];
		if (a > n) break;
		for (size_t j = i + 1; j < sz; j++) {
			b = one * prime[j];
			if (a * b > n) break;
			for (size_t k = j + 1; k < sz; k++) {
				c = one * prime[k] * prime[k];
				if (a * b * c > n) break;
				res++;
			}
		}
	}
	cout << res << '\n';
	return 0;
}
