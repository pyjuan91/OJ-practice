#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    while (cin >> n && n != 0) {
        bool first = true;
        for (int i = 1; i < n; i++) {

            if (i % 7 != 0) {
                if (first)
                    first = false;
                else
                    cout << " ";
                cout << i;
            }
        }
        cout << "\n";
    }
    return 0;
}