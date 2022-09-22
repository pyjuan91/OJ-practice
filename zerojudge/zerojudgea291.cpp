#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int pwd[4], test[4], n, A, B, checkedOrg[4], checkedTest[4];
    while (cin >> pwd[0]) {
        cin >> pwd[1] >> pwd[2] >> pwd[3];
        cin >> n;
        while (n--) {
            A = B = 0;
            memset(checkedOrg, 0, sizeof(checkedOrg));
            memset(checkedTest, 0, sizeof(checkedTest));
            cin >> test[0] >> test[1] >> test[2] >> test[3];

            // check A
            for (int i = 0; i < 4; i++) {
                if (test[i] == pwd[i]) {
                    A++;
                    checkedOrg[i] = checkedTest[i] =1;
                }
            }

            // check B
            for (int i = 0; i < 4; i++) {
                if (checkedOrg[i] == 0) {
                    for (int j = 0; j < 4; j++) {
                        if (checkedTest[j] == 0 && pwd[i] == test[j]) {
                            B++;
                            checkedOrg[i] = checkedTest[j] = 1;
                            break;
                        }
                    }
                }
            }
            printf("%dA%dB\n", A, B);
        }
    }
    return 0;
}