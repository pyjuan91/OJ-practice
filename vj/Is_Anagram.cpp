#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string a, b;
	int cnta[26] = {}, cntb[26] = {};
	cin >> a >> b;
	for (auto c : a) cnta[c - 'a']++;
	for (auto c : b) cntb[c - 'a']++;
	auto is_anagram = [&]() {
		for (int i = 0; i < 26; i++) {
			if (cnta[i] != cntb[i]) return false;
		}
		return true;
	};
	cout << (is_anagram() ? "Yes" : "No");
	return 0;
}
