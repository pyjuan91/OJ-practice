#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main(void)
{
    string num;
    string s;
    cin >> s;
    for (int i = 1; i < 7; i++) {
        num += to_string(abs((int)s[i] - (int)s[i - 1]));
    }
    cout << num << endl;
    return 0;
}