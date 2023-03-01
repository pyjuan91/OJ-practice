#include <bits/stdc++.h>
using namespace std;
int getStart(vector<int>& a, vector<int>& b, int n) {
	for (int i = 0; i < n; i++)
		if (a[i] != b[i]) return i;
	return -1;
}
int getEnd(vector<int>& a, vector<int>& b, int n) {
	for (int i = n - 1; i >= 0; i--)
		if (a[i] != b[i]) return i;
	return -1;
}
int main() {
	freopen("outofplace.in", "r", stdin);
	freopen("outofplace.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n, res = 0, start, end;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b.begin(), b.end());
	start = getStart(a, b, n);
	if (start == -1) cout << 0;
	else {
		end = getEnd(a, b, n);
		set<int> s;
		for (int i = start; i <= end; i++) {
			s.insert(a[i]);
		}
		cout << s.size() - 1;
	}
	return 0;
}