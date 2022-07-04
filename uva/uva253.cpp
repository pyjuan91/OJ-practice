#include <iostream>
#include <string>
#include <cstring>
#include <cstdbool>
using namespace std;

int main() {
	string s;
	while(cin >> s) {
		string cube1, cube2;
		cube1 = s.substr(0, 6);
		cube2 = s.substr(6, 12);
		bool check[3] = {false, false, false};
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 6; j++) {
				if(check[i] == false && cube1[i] == cube2[j] && cube1[5-i] == cube2[5-j]) {
					check[i] = true;
					cube2[j] = cube2[5-j] = 'x';
				}
			}
		}
		if(check[0] && check[1] && check[2])
			cout << "TRUE\n";
		else cout << "FALSE\n";
	}
	return 0;
}