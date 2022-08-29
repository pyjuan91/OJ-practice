#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int N, L;
    cin >> N;
    while (N--) {
        cin >> L;
        vector<int> a(L), b(L), c(L);
        string str;
        int diffB = 0, diffC = 0, flag = 1;
        for (int i = 0; i < L; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < L; i++) {
            cin >> b[i];
        }
        cin >> str;
        for (int i = 1; i < str.length(); i++) {
            if (flag && str[i] == '0') {
                diffB++;
            } else if (str[i] == '0') {
                diffC++;
            } else {
                flag = 0;
            }
        }
        for (int i = 0; i < L; i++) {
            c[(i + diffC) % L] = a[i] + b[(i + diffB) % L];
        }
        for (int i = 0; i < L; i++) {
            cout << ((i == 0) ? "" : " ");
            cout << c[i];
        }
        cout << endl;
    }

    return 0;
}