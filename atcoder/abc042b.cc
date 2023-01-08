#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
    int n, l;
    cin >> n >> l;
    string str;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        cin >> str;
        v.emplace_back(str);
    }
    sort(v.begin(), v.end());
    for (auto& i : v)
        cout << i;
    return 0;
}