#include <iostream>
using namespace std;
int main(void)
{
    string s;
    cin >> s;
    int i = s.length() - 1;
    while (i >= 0 && s[i] == '0')
        i--;
    for (i; i >= 0; i--) {
        cout << s[i];
    }
    if (s[0] == '0')
        cout << 0;
    cout << endl;
    return 0;
}