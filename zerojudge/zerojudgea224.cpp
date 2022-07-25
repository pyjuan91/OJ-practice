#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
    string s;
    int map[26];
    while (cin >> s) {
        for (int i = 0; i < 26; i++) {
            map[i] = 0;
        }
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                map[s[i] - 'a']++;
            }
            if (s[i] >= 'A' && s[i] <= 'Z') {
                map[s[i] - 'A']++;
            }
        }
        int oddNum = 0;
        for (int i = 0; i < 26; i++) {
            if (map[i] % 2) {
                oddNum++;
            }
        }
        if (oddNum < 2) {
            cout << "yes !" << endl;
        } else {
            cout << "no..." << endl;
        }
    }
    return 0;
}