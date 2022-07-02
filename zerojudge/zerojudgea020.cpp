#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int map[26] = {
    10, 11, 12, 13, 14, 15, 16, 17, 34,
    18, 19, 20, 21, 22, 35, 23, 24, 25,
    26, 27, 28, 29, 32, 30, 31, 33
};
int main(void)
{
    string s;
    cin >> s;
    int len = s.length();
    int checkNum = 0, tmp;
    tmp = map[s[0] - 'A'];
    checkNum = tmp / 10;
    checkNum += (tmp % 10) * 9;
    for (int i = 1; i < len; i++) {
        checkNum += (s[i] - '0') * (9 - i);
    }
    checkNum += s[len - 1] - '0';
    if (checkNum % 10 == 0)
        cout << "real" << endl;
    else
        cout << "fake" << endl;
    return 0;
}