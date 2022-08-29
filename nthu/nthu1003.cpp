#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
int main(void)
{
    int n, m, k, num;
    unordered_set<string> us;
    string str;
    while (cin >> n) {
        us.clear();

        cin >> m;
        while (n--) {
            cin >> str;
            us.insert(str);
        }
        while (m--) {
            cin >> k;
            num = 0;
            for (int i = 0; i < k; i++) {
                cin >> str;
                if (us.find(str) != us.end()) {
                    num++;
                }
            }
            if (num * 2 > k)
                cout << "Y\n";
            else
                cout << "N\n";
        }
    }
    return 0;
}