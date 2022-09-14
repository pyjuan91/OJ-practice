#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    int n, res = 0, num;
    string str;
    cin >> n >> str;
    for (int i = 0; i < n; i++) {
        num = 0;
        while (i < n && str[i] == '1') {
            num++;
            i++;
        }
        res *= 10;
        res += num;
    }
    if (str[n - 1] == '0') {
        res *= 10;
    }
    cout << res << endl;
    return 0;
}