#include <bits/stdc++.h>
using namespace std;
bool chaewon(int cond, vector<int>& odd, vector<vector<int>>& bulb, int M) {
	for (int i = 0; i < M; i++) {
		int cur = 0;
		for (auto j : bulb[i]) {
			if (cond & (1 << j)) cur ^= 1;
		}
		if (cur != odd[i]) return false;
	}
	return true;
}
int main() {
	cin.tie()->sync_with_stdio(false);
	int N, M, k;
	long long res = 0;
	cin >> N >> M;
	vector<vector<int>> bulb(M);
	for (int i = 0; i < M; i++) {
		cin >> k;
		vector<int> tmp(k);
		for (int j = 0; j < k; j++) {
			cin >> tmp[j];
			tmp[j] -= 1;
		}
		bulb[i] = tmp;
	}
	vector<int> odd(M);
	for (int i = 0; i < M; i++) cin >> odd[i];
	for (int cond = 0; cond < (1 << N); cond++) {
		if (chaewon(cond, odd, bulb, M)) res += 1LL;
	}
    cout << res;
	return 0;
}