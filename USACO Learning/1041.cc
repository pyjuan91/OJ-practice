#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int N, a[maxn], cnt[maxn] = {};
class BIT {
	private:
		vector<int> bit;

	public:
		BIT(int n) { bit.resize(n + 1, 0); }

		void update(int idx, int val) {
			for (; idx < (int) bit.size(); idx += (idx & -idx)) {
				bit[idx] += val;
			}
		}

		int query(int idx) {
			int sum = 0;
			for (; idx > 0; idx -= (idx & -idx)) {
				sum += bit[idx];
			}
			return sum;
		}

		int query(int left, int right) {
			return query(right) - query(left - 1);
		}
};

int32_t main() {
	ifstream cin("haircut.in");
	ofstream cout("haircut.out");

	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> N;
	auto bit = BIT(N + 2);
	int inv = 0, id = 0;
	vector<pair<int, int>> v;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		a[i]++;
		cnt[a[i]]++;
		bit.update(a[i], 1);
		v.emplace_back(make_pair(a[i], bit.query(a[i] + 1, N + 2)));
	}
	sort(v.begin(), v.end());
	cout << "0\n";
	for (int i = 1; i < N; i++) {
		while (id < (int) v.size() && v[id].first == i) {
			inv += v[id].second;
			id++;
		}
		cout << inv << '\n';
	}
	return 0;
}
