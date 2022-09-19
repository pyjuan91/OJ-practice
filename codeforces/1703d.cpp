#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
int main(void)
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<string> v(n);
        unordered_set<string> us;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            us.insert(v[i]);
        }
        for (int i = 0; i < n; i++) {
            int len = v[i].length(), j, k;
            string part1, part2;
            bool hasSol = false;
            for (j = 0; j < len; j++) {
                part1 = v[i].substr(0, j);
                part2 = v[i].substr(j, len - j);
                if (us.find(part1) != us.end() && us.find(part2) != us.end()) {
                    hasSol = true;
                    break;
                }
            }
            cout << (hasSol ? 1 : 0);
        }
        cout << "\n";
    }
    return 0;
}