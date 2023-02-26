#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("breedflip.in", "r", stdin);
	freopen("breedflip.out", "w", stdout);
	int n, res = 0;
	string s1, s2;
	cin >> n >> s1 >> s2;
	for (int i = 0; i < n; i++) {
		if (s1[i] != s2[i]) {
			res += 1;
			while (i < n && s1[i] != s2[i]) i++;
		}
	}
	cout << res;
	return 0;
}