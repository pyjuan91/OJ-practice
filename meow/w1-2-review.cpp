#include <bits/stdc++.h>
using namespace std;
vector<string> v;
void helper(int n)
{
    if (n == 1) {
        v.push_back("0");
        v.push_back("1");
        return;
    }
    helper(n - 1);
    vector<string> clone = v;
    reverse(clone.begin(), clone.end());
    int sz = v.size();
    for (int i = 0; i < sz; i++) {
        v[i] = "0" + v[i];
        clone[i] = "1" + clone[i];
        v.push_back(clone[i]);
    }
}
int main(void)
{
    int n;
    cin >> n;
    helper(n);
    for (string& str : v) {
        cout << str << "\n";
    }
    return 0;
}