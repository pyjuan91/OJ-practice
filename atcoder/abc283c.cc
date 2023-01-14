#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    string s;
    cin >> s;
    int len = s.length();
    int i = 0, res = 0;
    while (i < len) {
        if (s[i] == '0') {
            if (i + 1 < len && s[i + 1] == '0')
                i += 1;
        }
        i += 1;
        res += 1;
    }
    cout << res;
    return 0;
}