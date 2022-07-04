#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
void binary(int *a, string *b) {
	for(int i = 0; i < 4; i++) {
		char s[8];
		for(int si = 0; si < 8; si++) {
			s[si] = '0';
		}
		int tag = 7;
		while(a[i] > 0) {
			s[tag] = a[i] % 2 + '0';
			a[i] /= 2;
			tag--;
		}
		b[i].assign(s);
	}
}
void decimal(int *a, char *b) {
	for(int i = 0; i < 4; i++) {
		int num = 0;
		for(int p = 0; p < 8; p++) {
			if(b[8*i + p] == '1') {
				num += pow(2, 7-p);
			}
		}
		a[i] = num;
	}
}
int main() {
	int n;
	char c;
	while(cin >> n) {
	int ip[1005][4];
	for(int i = 0; i < n; i++) 
	cin >> ip[i][0] >> c >> ip[i][1] >> c >> ip[i][2] >> c >> ip[i][3];
	int min[4] = {255, 255, 255, 255};
	int max[4] = {0, 0, 0, 0};
	for(int i = 0; i < n; i++) {
		if(ip[i][0] < min[0] || (ip[i][0] == min[0] && ip[i][1] < min[1])
		|| (ip[i][0] == min[0] && ip[i][1] == min[1] && ip[i][2] < min[2])
		|| (ip[i][0] == min[0] && ip[i][1] == min[1] && ip[i][2] == min[2] && ip[i][3] < min[3])) {
			min[0] = ip[i][0];
			min[1] = ip[i][1];
			min[2] = ip[i][2];
			min[3] = ip[i][3];
		}
		if(ip[i][0] > max[0] || (ip[i][0] == max[0] && ip[i][1] > max[1])
		|| (ip[i][0] == max[0] && ip[i][1] == max[1] && ip[i][2] > max[2])
		|| (ip[i][0] == max[0] && ip[i][1] == max[1] && ip[i][2] == max[2] && ip[i][3] > max[3])) {
			max[0] = ip[i][0];
			max[1] = ip[i][1];
			max[2] = ip[i][2];
			max[3] = ip[i][3];
		}
	}
	// to binary
	string bmin[4], bmax[4];
	binary(min, bmin);
	binary(max, bmax);
	int same_bit_cnt = 0;
	bool same = true;
	for(int i=0;i<4;i++) {
		for(int j=0;j<8;j++) {
			if(bmin[i][j] != bmax[i][j]) {
				same = false;
				break;
			}
			same_bit_cnt += 1;
		}
		if(same == false) break;
	}
	char ipaddr[32], ipmask[32];
	for(int i=0;i<32;i++) ipaddr[i] = i<same_bit_cnt?bmin[i/8][i%8]:'0';
	for(int i=0;i<32;i++) ipmask[i] = i<same_bit_cnt?'1':'0';
	decimal(min, ipaddr);
	decimal(max, ipmask);
	cout << min[0] << "." << min[1] << "." << min[2] << "." << min[3] << endl;
	cout << max[0] << "." << max[1] << "." << max[2] << "." << max[3] << endl;
	}
	return 0;
}






