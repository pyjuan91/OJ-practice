#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    int n, k, cur, j;
    cin >> n >> k;
    vector<string> strs(n);
    for (int i = 0; i < n; i++)
        cin >> strs[i];
    j = cur = 0;
    while (j < n) {
        if (cur == 0) {
            cur += strs[j].length();
            cout << strs[j];
        } else if (cur + strs[j].length() <= k) {
            cur += strs[j].length();
            cout << " " << strs[j];
        } else {
            cur = 0;
            cout << "\n";
            j--;
        }
        j++;
    }
    return 0;
}