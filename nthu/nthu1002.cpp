#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    string str;
    while (cin >> str) {
        reverse(str.begin(), str.end());
        cout << str << endl;
    }

    return 0;
}