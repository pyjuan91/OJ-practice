#include <bits/stdc++.h>
using namespace std;
int main(void) {
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < s.length(); i++)
        if (s[i] != t[i]) {
            cout << i + 1;
            return 0;
        }
    cout << t.length();
    return 0;
}