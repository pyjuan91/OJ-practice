#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    string str;
    cin >> str;
    vector<bool> table(26, false);
    for (auto i : str)
        table[i - 'a'] = !table[i - 'a'];
    for (auto i : table)
        if (i) {
            cout << "No";
            return 0;
        }
    cout << "Yes";
    return 0;
}