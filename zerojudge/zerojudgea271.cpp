#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int t, x, y, z, w, n, m, radish, poisoning, die;
    stringstream ss;
    string str;
    cin >> t;
    while (t--) {
        cin >> x >> y >> z >> w >> n >> m;
        getchar();
        getline(cin, str);
        ss = stringstream();
        ss << str;
        poisoning = die = 0;
        while (ss >> radish) {
            m -= poisoning * n;
            if (m <= 0) {
                die = 1;
                break;
            }
            switch (radish) {
            case 0:
                break;
            case 1:
                m += x;
                break;
            case 2:
                m += y;
                break;
            case 3:
                m -= z;
                break;
            case 4:
                m -= w;
                poisoning += 1;
                break;
            default:
                break;
            }
            if (m <= 0) {
                die = 1;
                break;
            }
        }
        if (die)
            cout << "bye~Rabbit\n";
        else
            cout << m << "g\n";
    }
    return 0;
}