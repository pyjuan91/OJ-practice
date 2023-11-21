#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	stack<char> pending;
	while (!s.empty()) {
		if (s.back() == ')' || s.back() == '}' || s.back() == ']')
			pending.push(s.back());
		else if (s.back() == '(') {
			if (pending.empty() || pending.top() != ')') {
				cout << "No\n";
				return 0;
			}
			pending.pop();
		}
		else if (s.back() == '{') {
			if (pending.empty() || pending.top() != '}') {
				cout << "No\n";
				return 0;
			}
			pending.pop();
		}
		else if (s.back() == '[') {
			if (pending.empty() || pending.top() != ']') {
				cout << "No\n";
				return 0;
			}
			pending.pop();
		}
		else {
			cout << "No\n";
			return 0;
		}
        s.pop_back();
	}
	if (pending.empty()) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}
