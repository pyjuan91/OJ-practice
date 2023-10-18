#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		string shortestBeautifulSubstring(string s, int k) {
			int n = s.length(), len = n + 1;
			set<string> st;
			for (int i = 0; i < n; i++) {
				if (s[i] == '0') continue;
				int j = i, cnt = 0;
				for (; j < n; j++) {
					if (s[j] == '1') cnt++;
					if (cnt == k) break;
				}
				if (cnt == k && j - i + 1 == len) {
					st.insert(s.substr(i, len));
				}
				if (cnt == k && j - i + 1 < len) {
                    len = j - i + 1;
					st.clear();
					st.insert(s.substr(i, j - i + 1));
				}
			}
			if (st.empty()) return "";
			return *st.begin();
		}
};
int main() { return 0; }