#include <bits/stdc++.h>
using namespace std;
int main(void) {
    string s, t;
    cin >> s >> t;
    if (s.find(t) != string::npos)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}