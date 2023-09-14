#include <bits/stdc++.h>
#define int long long
using namespace std;
int cnt = 0, plus_num = 0, m_contri[500005], res = 0;
string s;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> s;
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == '+') plus_num += 1;
		else if (s[i] == '-') plus_num -= 1;
		else m_contri[++cnt] = plus_num;
	}
	sort(m_contri + 1, m_contri + cnt + 1);
	for (int i = 1; i <= cnt / 2; i++) res -= m_contri[i];
	for (int i = cnt / 2 + 1; i <= cnt; i++) res += m_contri[i];
    cout << res << endl;
	return 0;
}