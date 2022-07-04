#include <iostream>
#include <vector>
#include <map>
#include <cstdbool>
#include <cstring>
using namespace std;
const int maxn = 1005;
map<char, int> arr_rec;
map<int, int> arr_val[maxn];
map<int, bool> arr_ini[maxn];
int limit[maxn];
int gv(int lb, int rb, const char *cstr, bool &valid) {
	if(isdigit(cstr[lb])) {
		int num = 0;
		for(int i = lb; i < rb; i++) {
			num *= 10;
			num += cstr[i] - '0';
		}
		return num;
	} else {
		char c = cstr[lb];
		// cout << arr_rec[c] << endl;
		// cout << limit[arr_rec[c]] << endl;
		int tag = gv(lb + 2, rb - 1, cstr, valid);
		if(tag >= limit[arr_rec[c]]) valid = false;
		if(arr_ini[arr_rec[c]][tag] == false) valid = false;
		return arr_val[arr_rec[c]][tag];
	}
}
int main() {
	string str;
	while(cin >> str && str != ".") {
		vector<string> cmd;
		cmd.push_back(str);
		arr_rec.clear();
		for(int i = 0; i < maxn; i++) {
			arr_val[i].clear();
			arr_ini[i].clear();
			limit[i] = 0;
		}
		int tag = 0;
		int cnt = 0;
		bool ans = true;
		while(cin >> str && str != ".")
			cmd.push_back(str);
		for(auto i: cmd) {
			cnt++;
			const char* cstr = i.c_str();
			if(strchr(cstr, '=') == NULL) {
				// init
				arr_rec[i[0]] = ++tag;
				// identify the number
				int num = 0;
				for(int p = 2; p < i.length(); p++) {
					if(isdigit(i[p])){
						num *= 10;
						num += i[p] - '0';
					}
				}
				limit[tag] = num;
			}
			else {
				char c = i[0];
				int rb = strchr(cstr, '=') - cstr;
				bool valid = true;
				int tag = gv(2, rb - 1, cstr, valid);
				if(tag >= limit[arr_rec[c]]) valid = false;
				int v = gv(rb + 1, i.length(), cstr, valid);
				if(valid) {
					arr_ini[arr_rec[c]][tag] = true;
					arr_val[arr_rec[c]][tag] = v;
				}
				else {
					cout << cnt << endl;
					ans = false;
					break;
				}
			}
		}
		if(ans) cout << 0 << endl;
		// for(auto i:cmd) {
		// 	cout << i << endl;
		// }
		// cout << endl;
	}
	return 0;
}