#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	int leadingSpaces = n - 1;
	for (int i = 1; i <= n; i++) {
		for (int _ = 0; _ < leadingSpaces; _++) cout << " ";
		for (int _ = 0; _ < i; _++) {
			cout << "*" << (_ == i - 1 ? "\n" : " ");
		}
		leadingSpaces--;
	}
	return 0;
}
