#include <bits/stdc++.h>
using namespace std;
int main() {
	int x;
	unordered_map<int, int> last_vist_pos;
	for (int i = 0; i <= 1000; i++) {
		if (i) {
			cout << "+ 1\n";
			cout.flush();
		}
		cin >> x;
		if (!last_vist_pos.count(x)) last_vist_pos[x] = i;
		else {
			cout << "! " << i - last_vist_pos[x] << "\n";
			cout.flush();
			return 0;
		}
	}
	for (int i = 1; i <= 1000; i++) {
		cout << "+ 1000\n";
		cout.flush();
		cin >> x;
		if (!last_vist_pos.count(x))
			last_vist_pos[x] = 1000 * (i + 1);
		else {
			cout << "! " << 1000 * (i + 1) - last_vist_pos[x] << "\n";
			cout.flush();
			return 0;
		}
	}
	return 0;
}