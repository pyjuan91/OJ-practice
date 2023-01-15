#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 1; i < n; i++) {
        int l = 0;
        for (int j = 0; j + i < n; j++, l++)
            if (s[j] == s[j + i]) break;
        cout << l << "\n";
    }
    return 0;
}