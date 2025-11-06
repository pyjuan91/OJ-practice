#include <bits/stdc++.h>
#ifdef LOCAL
#	include "./debug.cc"
#else
#	define debug(...)
#	define debugArr(...)
#endif
using namespace std;

class HashedString {
private:
	// change M and B if you want
	static const int64_t M = (1LL << 61) - 1;
	static const int64_t B;

	// pow[i] contains B^i % M
	static vector<int64_t> pow;

	// p_hash[i] is the hash of the first i characters of the given string
	vector<int64_t> p_hash;

	__int128 mul(int64_t a, int64_t b) { return (__int128)a * b; }
	int64_t mod_mul(int64_t a, int64_t b) { return mul(a, b) % M; }

public:
	HashedString(const string& s) : p_hash(s.size() + 1) {
		while (pow.size() <= s.size()) {
			pow.push_back(mod_mul(pow.back(), B));
		}
		p_hash[0] = 0;
		for (int i = 0; i < s.size(); i++) {
			p_hash[i + 1] = (mul(p_hash[i], B) + s[i]) % M;
		}
	}

	int64_t get_hash(int start, int end) {
		int64_t raw_val = p_hash[end + 1] - mod_mul(p_hash[start], pow[end - start + 1]);
		return (raw_val + M) % M;
	}
};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
vector<int64_t> HashedString::pow = {1};
const int64_t HashedString::B = uniform_int_distribution<int64_t>(0, M - 1)(rng);

int patty(string& a, string& b) {
	int n = a.size();
	auto hashed_a = HashedString(a);
	auto hashed_b = HashedString(b);

	if (hashed_a.get_hash(0, n - 1) == hashed_b.get_hash(0, n - 1)) {
		return 0;
	}
	for (int shift = 1; shift < n; shift++) {
		int64_t former_a = hashed_a.get_hash(shift, n - 1);
		int64_t later_a = hashed_a.get_hash(0, shift - 1);

		int64_t former_b = hashed_b.get_hash(0, n - shift - 1);
		int64_t later_b = hashed_b.get_hash(n - shift, n - 1);

		if (former_a == former_b and later_a == later_b) {
			return shift;
		}
	}
	return -1;
}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	string a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << patty(a, b) << "\n";
	}
	return 0;
}
