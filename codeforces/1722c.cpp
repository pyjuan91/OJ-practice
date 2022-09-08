#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main(void)
{
    string str;
    int t, n, sc[3], id[3] = { 1, 2, 4 };
    cin >> t;
    while (t--) {
        cin >> n;
        unordered_map<string, int> um;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                cin >> str;
                if (um.find(str) == um.end())
                    um[str] = 0;
                um[str] += id[i];
            }
        }
        sc[0] = sc[1] = sc[2] = 0;
        ;
        for (auto i : um) {
            // cout << i.first << " " << i.second << endl;
            switch (i.second) {
            case 1:
                sc[0] += 3;
                break;
            case 2:
                sc[1] += 3;
                break;
            case 4:
                sc[2] += 3;
                break;
            case 3:
                sc[0] += 1;
                sc[1] += 1;
                break;
            case 6:
                sc[1] += 1;
                sc[2] += 1;
                break;
            case 5:
                sc[0] += 1;
                sc[2] += 1;
            default:
                break;
            }
        }
        cout << sc[0] << " " << sc[1] << " " << sc[2] << endl;
    }
    return 0;
}