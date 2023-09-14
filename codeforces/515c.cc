#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	map<char, vector<char>> m;
	m['0'] = {};
	m['1'] = {};
	m['2'] = {'2'};
	m['3'] = {'3'};
	m['4'] = {'2', '2', '3'};
	m['5'] = {'5'};
	m['6'] = {'3', '5'};
	m['7'] = {'7'};
	m['8'] = {'2', '2', '2', '7'};
	m['9'] = {'2', '3', '3', '7'};
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	vector<char> ans;
	for (char c : s) {
		for (char d : m[c]) { ans.push_back(d); }
	}
	sort(ans.rbegin(), ans.rend());
	for (char c : ans) cout << c; 
	return 0;
}
