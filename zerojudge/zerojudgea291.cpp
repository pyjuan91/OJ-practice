#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int pwd[4], test[4], n, A, B, pwdCopy[4];
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while (scanf("%d%d%d%d", &pwd[0], &pwd[1], &pwd[2], &pwd[3]) == 4) {
        scanf("%d", &n);
        while (n--) {
            A = B = 0;
            scanf("%d%d%d%d", &test[0], &test[1], &test[2], &test[3]);
            pwdCopy[0] = pwd[0];
            pwdCopy[1] = pwd[1];
            pwdCopy[2] = pwd[2];
            pwdCopy[3] = pwd[3];

            // check A
            for (int i = 0; i < 4; i++) {
                if (test[i] == pwd[i]) {
                    A++;
                    pwdCopy[i] = -2;
                    test[i] = -1;
                }
            }

            // check B
            for (int i = 0; i < 4; i++) {

                for (int j = 0; j < 4; j++) {
                    if (pwdCopy[i] == test[j]) {
                        B++;
                        test[j] = -1;
                        pwdCopy[i] = -2;
                        break;
                    }
                }
            }
            printf("%dA%dB\n", A, B);
        }
    }
    return 0;
}