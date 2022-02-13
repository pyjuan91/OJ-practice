#include <iostream>
using namespace std;
int main(void) {
    int n, m, entry;
    int matrix[105][105];
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            bool first = true;
            for (int j = 0; j < n; j++) {
                if (first)
                    first = false;
                else
                    cout << " ";
                cout << matrix[j][i];
            }
            cout << endl;
        }
    }
    return 0;
}