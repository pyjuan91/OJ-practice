#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool chaewon(ll, ll, ll, vector<ll>&);
int main() {
	cin.tie()->sync_with_stdio(false);
#define int long long
	int n, a, b, sum = 0, left, right;
	cin >> n >> a >> b;
	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		sum += num[i];
	}
	sort(num.begin(), num.end());
	left = num[0], right = sum / n + 1;
	while (left + 1 < right) {
		int mid = left + (right - left) / 2;
		if (chaewon(mid, a, b, num)) left = mid;
		else right = mid;
	}
	cout << left;
	return 0;
}
bool chaewon(int guess, int a, int b, vector<int>& num) {
	int a_required_times = 0;
	int b_required_times = 0;
	for (auto& i : num) {
		if (i > guess) b_required_times += (i - guess) / b;
		if (i < guess)
			a_required_times += (guess - i) / a + ((guess - i) % a > 0);
	}
	return a_required_times <= b_required_times;
}