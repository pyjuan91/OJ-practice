#include <bits/stdc++.h>
using namespace std;
int main(void) {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    int a, b, c, ca, cb, cc;
    cin >> a >> ca >> b >> cb >> c >> cc;
    for (int i = 0; i < 33; i++) {
        if (ca + cb > b) {
            ca = ca + cb - b;
            cb = b;
        } else {
            cb += ca;
            ca = 0;
        }

        if (cb + cc > c) {
            cb = cb + cc - c;
            cc = c;
        } else {
            cc += cb;
            cb = 0;
        }

        if (cc + ca > a) {
            cc = cc + ca - a;
            ca = a;
        } else {
            ca += cc;
            cc = 0;
        }
    }
    if (ca + cb > b) {
        ca = ca + cb - b;
        cb = b;
    } else {
        cb += ca;
        ca = 0;
    }
    cout << ca << endl << cb << endl << cc;
    return 0;
}