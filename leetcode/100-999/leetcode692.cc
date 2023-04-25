#include <bits/stdc++.h>
using namespace std;
class NameFreq {
	public:
		string name;
		int freq;
		NameFreq(string _name, int _freq) {
			name = _name;
			freq = _freq;
		}
		bool operator<(const NameFreq& b) {
			if (freq == b.freq) return name < b.name;
			return freq > b.freq;
		}
};
class Solution {
	public:
		vector<string> topKFrequent(vector<string>& words, int k) {
			unordered_map<string, int> um;
			for (auto word : words) um[word] += 1;
			vector<NameFreq> a;
			for (auto p : um)
				a.emplace_back(NameFreq(p.first, p.second));
			sort(a.begin(), a.end());
			vector<string> res;
			for (int i = 0; i < k; i++)
				res.emplace_back(a[i].name);
			return res;
		}
};
int main() {
	cin.tie()->sync_with_stdio(false);
	return 0;
}