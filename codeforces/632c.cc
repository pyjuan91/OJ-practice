#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<string> a(n);
	for (auto &s : a) cin >> s;
	sort(begin(a), end(a), [&](auto a, auto b) {
		return a + b < b + a;
	});
	for (auto &s : a) cout << s;
	return 0;
}