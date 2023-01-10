#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin >> str;
    vector<char> res;
    for (auto i : str) {
        if (i == 'B') {
            if (res.size())
                res.pop_back();
        } else
            res.emplace_back(i);
    }
    for (auto i : res)
        cout << i;
    return 0;
}