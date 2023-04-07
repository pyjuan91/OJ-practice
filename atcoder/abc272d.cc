#include <bits/stdc++.h>
using namespace std;
int g[405][405] = {0};
bool isPerfectSquare(int num) {
	if (num == 1 || num == 0) return true;

	int start = 2;
	int end = num;
	int mid;
	while (start <= end) {
		mid = start + (end - start) / 2;
		if (mid == num / mid && num % mid == 0) return true;

		if (mid > num / mid) end = mid - 1;
		else start = mid + 1;
	}

	return false;
}
int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) g[i][j] = -1;
	}
	queue<int> qi, qj, qs;
	qi.push(0);
	qj.push(0);
	qs.push(0);

	vector<int> route_i, route_j;
	for (int i = 0; i <= sqrt(m); i++) {
		int j = m - pow(i, 2);
		if (isPerfectSquare(j)) {
			j = sqrt(j);
			route_i.push_back(i);
			route_j.push_back(j);
		}
	}
	while (!qi.empty()) {
		int curi = qi.front();
		int curj = qj.front();
		int curs = qs.front();
		if (g[curi][curj] != -1) {
			qi.pop();
			qj.pop();
			qs.pop();
			continue;
		}
		for (int p = 0; p < route_i.size(); p++) {
			int i = route_i[p], j = route_j[p];
			// + +
			if (curi + i < n && curj + j < n) {
				qi.push(curi + i);
				qj.push(curj + j);
				qs.push(curs + 1);
			}

			// + -
			if (curi + i < n && curj - j >= 0) {
				qi.push(curi + i);
				qj.push(curj - j);
				qs.push(curs + 1);
			}

			// - +
			if (curi - i >= 0 && curj + j < n) {
				qi.push(curi - i);
				qj.push(curj + j);
				qs.push(curs + 1);
			}

			// - -
			if (curi - i >= 0 && curj - j >= 0) {
				qi.push(curi - i);
				qj.push(curj - j);
				qs.push(curs + 1);
			}
		}
		g[curi][curj] = curs;
		qi.pop();
		qj.pop();
		qs.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << g[i][0];
		for (int j = 1; j < n; j++) { cout << " " << g[i][j]; }
		cout << "\n";
	}
	return 0;
}