#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	string S;
	int Q, cmd, pos;
	char c;
	deque<char> dq;
	bool dir = true;
	cin >> S;
	for (auto& cc : S) dq.push_back(cc);
	cin >> Q;
	while (Q--) {
		cin >> cmd;
		if (cmd == 1) dir = !dir;
		else {
			cin >> pos >> c;
			if ((pos == 1 && dir) || (pos == 2 && !dir))
				dq.push_front(c);
			else dq.push_back(c);
		}
	}
	if (!dir) reverse(dq.begin(), dq.end());
	for (auto i : dq) cout << i;
	return 0;
}