#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int n;
	string s;
	cin >> n >> s;

	int ones = count(s.begin(), s.end(), '1');
	if (ones == 0 || ones == 1) {
		cout << ones << "\n";
		return 0;
	}

	if (ones == n) {
		cout << "1\n";
		return 0;
	}

	if (s.size() == 2) {
		cout << 1 << "\n";
		return 0;
	}

	if (s.size() == 3) {
		if (ones == 2 && s[1] == '0') cout << "2\n";
		else cout << "1\n";
		return 0;
	}

	vector<int> blocks;
	int cnt = 0, idx = 0;
	while (idx < n) {
		cnt = 0;
		while (idx < n && s[idx] == '1') cnt++, idx++;
		if (cnt) blocks.push_back(cnt);
		idx++;
	}

	int head_block = 0, tail_block = 0;
	if (s[0] == '1') head_block = blocks[0];
	if (s.back() == '1') tail_block = blocks.back();

	if (head_block == 0 && tail_block == 0) {
		sort(blocks.begin(), blocks.end());

		if (blocks[0] < 3) {
			cout << ones << "\n";
			return 0;
		}

		int res = 0, one_seed;
		if (blocks[0] % 2 == 0) one_seed = blocks[0] - 1;
		else one_seed = blocks[0];
		for (int i = 0; i < blocks.size(); i++) {
			res += blocks[i] / one_seed + (blocks[i] % one_seed != 0);
		}
		cout << res << "\n";
		return 0;
	}

	if (head_block != 0 && tail_block != 0) {
		blocks.erase(blocks.begin());
		blocks.pop_back();

		sort(blocks.begin(), blocks.end());
		if (!blocks.empty() && blocks[0] < 3) {
			cout << ones << "\n";
			return 0;
		}

		int res = 0, one_seed = INT32_MAX;
		if (!blocks.empty()) {
			if (blocks[0] % 2 == 0) one_seed = blocks[0] - 1;
			else one_seed = blocks[0];
		}

		one_seed = min(one_seed, 2 * head_block - 1);
		one_seed = min(one_seed, 2 * tail_block - 1);

		for (int i = 0; i < blocks.size(); i++) {
			res += blocks[i] / one_seed + (blocks[i] % one_seed != 0);
		}
		res += head_block / one_seed + (head_block % one_seed != 0);
		res += tail_block / one_seed + (tail_block % one_seed != 0);

		cout << res << "\n";
		return 0;
	}

	if (head_block != 0) {
		blocks.erase(blocks.begin());
		sort(blocks.begin(), blocks.end());
		if (!blocks.empty() && blocks[0] < 3) {
			cout << ones << "\n";
			return 0;
		}

		int res = 0, one_seed = INT32_MAX;
		if (!blocks.empty()) {
			if (blocks[0] % 2 == 0) one_seed = blocks[0] - 1;
			else one_seed = blocks[0];
		}

		one_seed = min(one_seed, 2 * head_block - 1);

		for (int i = 0; i < blocks.size(); i++) {
			res += blocks[i] / one_seed + (blocks[i] % one_seed != 0);
		}
		res += head_block / one_seed + (head_block % one_seed != 0);

		cout << res << "\n";
		return 0;
	}

	blocks.pop_back();
	sort(blocks.begin(), blocks.end());
	if (!blocks.empty() && blocks[0] < 3) {
		cout << ones << "\n";
		return 0;
	}

	int res = 0, one_seed = INT32_MAX;
	if (!blocks.empty()) {
		if (blocks[0] % 2 == 0) one_seed = blocks[0] - 1;
		else one_seed = blocks[0];
	}

	one_seed = min(one_seed, 2 * tail_block - 1);

	for (int i = 0; i < blocks.size(); i++) {
		res += blocks[i] / one_seed + (blocks[i] % one_seed != 0);
	}
	res += tail_block / one_seed + (tail_block % one_seed != 0);

	cout << res << "\n";
	return 0;
}
