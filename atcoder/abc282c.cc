#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool in = false;
    for (auto&c :s) {
        if (c == '\"')
            in = in ^ true;
        else if (c == ',' && !in)
            c = '.';
    }
    cout << s;
    return 0;
}