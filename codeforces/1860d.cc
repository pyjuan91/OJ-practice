#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	int len = s.length();
	auto value = [&](string& s) {
		int left_zero[len] = {}, right_zero[len] = {};
		for (int i = 0; i < len; i++) {
			if (i) left_zero[i] = left_zero[i - 1];
			if (s[i] == '0') left_zero[i]++;
		}
		for (int i = len - 1; i >= 0; i--) {
			if (i != len - 1) right_zero[i] = right_zero[i + 1];
			if (s[i] == '0') right_zero[i]++;
		}
		int oI = 0, Io = 0;
		for (int i = 0; i < len; i++) {
			if (s[i] == '1') {
				oI += left_zero[i];
				Io += right_zero[i];
			}
		}
		return abs(oI - Io);
	};
	int res = 0;
	while (value(s) != 0) {
		string nice = s;
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				swap(s[i], s[j]);
				if (value(s) < value(nice)) nice = s;
				swap(s[i], s[j]);
			}
		}
		s = nice;
		res++;
	}
    cout << res << '\n';
	return 0;
}
