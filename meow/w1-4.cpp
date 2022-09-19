#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    vector<string> v;
    char str[10];
    int cnt = 0, len;
    scanf("%s", str);
    len = strlen(str);
    sort(str, str + len);
    do {
        cnt++;
        string entry(str);
        v.push_back(entry);
    } while (next_permutation(str, str + len));
    cout << cnt << "\n";
    for (string& i : v) {
        cout << i << "\n";
    }
    return 0;
}