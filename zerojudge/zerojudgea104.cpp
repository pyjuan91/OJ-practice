#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int n;
    while (cin >> n) {
        vector<int> v;
        int entry;
        while (n--) {
            cin >> entry;
            v.push_back(entry);
        }
        sort(v.begin(), v.end());
        bool first = true;
        for (auto i : v) {
            if (first) {
                cout << i;
                first = false;
            } else {
                cout << " " << i;
            }
        }
        cout << endl;
    }

    return 0;
}