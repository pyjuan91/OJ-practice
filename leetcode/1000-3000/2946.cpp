#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		bool areSimilar(vector<vector<int>>& mat, int k) {
			int n = mat.size(), m = mat[0].size();
            k %= m;
			auto check_even_rows = [&]() {
				for (int i = 1; i < n; i += 2) {
					for (int j = 0; j < m; j++) {
						int neo_pos = (j - k + m) % m;
						if (mat[i][j] != mat[i][neo_pos])
							return false;
					}
				}
				return true;
			};
			auto check_odd_rows = [&]() {
				for (int i = 0; i < n; i += 2) {
					for (int j = 0; j < m; j++) {
						int neo_pos = (j + k) % m;
						if (mat[i][j] != mat[i][neo_pos])
							return false;
					}
				}
				return true;
			};
			return check_even_rows() && check_odd_rows();
		}
};
int main() {
	Solution s;
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> mat(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> mat[i][j];
	cout << (s.areSimilar(mat, k) ? "true" : "false") << endl;
	return 0;
}