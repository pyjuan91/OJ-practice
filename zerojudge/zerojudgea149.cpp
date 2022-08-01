#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    int t, num;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        num = 1;
        for (int i = 0; i < s.length(); i++) {
            num *= (s[i] - '0');
        }
        cout << num << endl;
    }
    return 0;
}