#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int brother, N, last_sis = -1, t, i;
    vector<int> B, S;
    cin >> brother >> N;
    B.push_back(brother);
    for (i = 0; i < N; i++) {
        cin >> t;
        S.push_back(t);
    }
    for (i = 0; i < N; i++) {
        switch (B[i]) {
        case 0:
            if (S[i] == 2) {
                for (auto j : B) {
                    cout << j << " ";
                }
                cout << ": Won at round " << i + 1 << endl;
                return 0;
            } else if (S[i] == 5) {
                for (auto j : B) {
                    cout << j << " ";
                }
                cout << ": Lost at round " << i + 1 << endl;
                return 0;
            } else {
                if (last_sis == 0)
                    B.push_back(5);
                else
                    B.push_back(0);
                last_sis = 0;
            }
            break;
        case 2:
            if (S[i] == 5) {
                for (auto j : B) {
                    cout << j << " ";
                }
                cout << ": Won at round " << i + 1 << endl;
                return 0;
            } else if (S[i] == 0) {
                for (auto j : B) {
                    cout << j << " ";
                }
                cout << ": Lost at round " << i + 1 << endl;
                return 0;
            } else {
                if (last_sis == 2)
                    B.push_back(0);
                else
                    B.push_back(2);
                last_sis = 2;
            }
            break;
        default:
            if (S[i] == 0) {
                for (auto j : B) {
                    cout << j << " ";
                }
                cout << ": Won at round " << i + 1 << endl;
                return 0;
            } else if (S[i] == 2) {
                for (auto j : B) {
                    cout << j << " ";
                }
                cout << ": Lost at round " << i + 1 << endl;
                return 0;
            } else {
                if (last_sis == 5)
                    B.push_back(2);
                else
                    B.push_back(5);
                last_sis = 5;
            }
            break;
        }
    }
    B.pop_back();
    for (auto j : B) {
        cout << j << " ";
    }
    cout << ": Drew at round " << N << endl;
    return 0;
}