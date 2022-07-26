#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int map[26] = {
        10, 11, 12, 13, 14,
        15, 16, 17, 34, 18,
        19, 20, 21, 22, 35,
        23, 24, 25, 26, 27,
        28, 29, 32, 30, 31,
        33
    };
    for (int i = 0; i < 26; i++) {
        map[i] = map[i] / 10 + (map[i] % 10) * 9;
        map[i] %= 10;
    }
    int num, checker, sum = 0;
    string s;
    cin >> s;
    checker = (s[8] - '0') % 10;
    if (checker)
        checker = 10 - checker;
    for (int i = 0; i < 8; i++) {
        sum += (8 - i) * (s[i] - '0');
        sum %= 10;
    }
    for (int i = 0; i < 26; i++) {
        if ((sum + map[i]) % 10 == checker) {
            cout << (char)('A' + i);
        }
    }
    cout << endl;
    return 0;
}