#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
    char str[8];
    int cnt = 0, sz;
    vector<string> res;
    cin >> str;
    sz = strlen(str);
    sort(str, str + sz);
    do {
        cnt++;
        string e(str);
        res.push_back(e);
    } while (next_permutation(str, str + sz));
    cout << cnt << "\n";
    for (string& op : res) {
        cout << op << "\n";
    }
    return 0;
}