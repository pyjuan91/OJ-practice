#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	const string vowels = "aeiouAEIOU";
	cin >> s;
	int ans = 0;
	for (char c : s) {
		if (vowels.find(c) != string::npos)  ans++; 
	}
    cout << ans << '\n';
	return 0;
}
