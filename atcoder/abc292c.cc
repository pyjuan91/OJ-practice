// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// int chaechae[200005] = {0};
// int chaewon(int a) {
// 	if (chaechae[a]) return chaechae[a];

// }
// ll solve(int n) {
// 	ll res = 0;
// 	for (int i = 1; i <= n / 2; i++) { int left = }
// }
// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie();
// 	int n;
// 	cin >> n;
// 	cout << solve(n);
// 	return 0;
// }

// C++ program to count number of factors
// of an array of integers
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;
int factor[MAX] = {0};

void generatePrimeFactors() {
	factor[1] = 1;

	for (int i = 2; i < MAX; i++) factor[i] = i;

	for (int i = 4; i < MAX; i += 2) factor[i] = 2;

	for (int i = 3; i * i < MAX; i++) {
		if (factor[i] == i) {
			for (int j = i * i; j < MAX; j += i) {
				if (factor[j] == j) factor[j] = i;
			}
		}
	}
}

int calculateNoOfFactors(int n) {
	if (n == 1) return 1;

	int ans = 1;

	int dup = factor[n];

	int c = 1;

	int j = n / factor[n];

	while (j != 1) {
		if (factor[j] == dup) c += 1;

		else {
			dup = factor[j];
			ans = ans * (c + 1);
			c = 1;
		}

		j = j / factor[j];
	}

	ans = ans * (c + 1);

	return ans;
}

int main() {
	generatePrimeFactors();

	int n;

	cin >> n;

	long long res = 0;
	for (int i = 1; i <= n / 2; i++) {
		int left = calculateNoOfFactors(i);
		int right = calculateNoOfFactors(n - i);

		if (i != n - i) res += 2LL * left * right;
		else res += 1LL * left * right;
	}

	cout << res;

	return 0;
}
