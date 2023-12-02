#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		long long beautifulSubstrings(string s, int k) {
			int len = 1;
			for (int i = 2; i <= k; i++) {
				int cnt = 0;
				while (k % i == 0) {
					k /= i;
					cnt++;
				}
				if (cnt) {
					if (cnt & 1) len *= pow(i, (cnt + 1) / 2);
					else len *= pow(i, cnt / 2);
				}
			}
			long long res = 0;
			unordered_map<int, unordered_map<int, int>> mp;
			auto is_vowel = [&](char c) {
				return c == 'a' || c == 'e' || c == 'i'
					|| c == 'o' || c == 'u';
			};
			s = " " + s;
			mp[0][0] = 1;
			int diff = 0;
			len *= 2;
			for (int i = 1; i < s.size(); i++) {
				diff += is_vowel(s[i]) ? 1 : -1;
				if (mp.count(i % len) && mp[i % len].count(diff))
					res += 1ll * mp[i % len][diff];
				mp[i % len][diff]++;
			}
			return res;
		}
};
int main() {
	Solution sol;
	string s;
	int k;
	cin >> s >> k;
	cout << sol.beautifulSubstrings(s, k) << endl;
	return 0;
}