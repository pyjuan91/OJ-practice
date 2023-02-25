#include <bits/stdc++.h>
using namespace std;
int chaewon(int n, int k, string s) {
	int cnt = count(s.begin(), s.end(), 'X');
	if (cnt == n) return max(0, k - 1);
	if (k > cnt) {
		for (int i = 0; i < n; i++) {
			if (s[i] == 'X') s[i] = 'Y';
			else s[i] = 'X';
		}
		return chaewon(n, n - k, s);
	}

	vector<int> section;
	for (int i = 0; i < n; i++)
		if (s[i] == 'Y')
			for (int j = i + 1; j < n; j++)
				if (s[j] == 'Y') {
					section.emplace_back(j - i - 1);
					break;
				}

	sort(section.begin(), section.end());
	int res = k;
	for (auto sec : section) {
		if (k >= sec) {
			k -= sec;
			res += 1;
		}
	}

	return res;
}
int main() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	cout << chaewon(n, k, s);
	return 0;
}