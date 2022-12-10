#include <iostream>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin >> str;
    if (str.length() != 8)
        cout << "No\n";
    else {
        if (str[0] < 'A' || str[0] > 'Z')
            cout << "No\n";
        else {
            if (str[7] < 'A' || str[7] > 'Z')
                cout << "No\n";
            else {
                int num = 0;
                for (int i = 1; i < 7; i++) {
                    if (str[i] < '0' || str[i] > '9') {
                        cout << "No\n";
                        return 0;
                    }
                    num *= 10;
                    num += str[i] - '0';
                }
                if (num >= 100000 && num <= 999999)
                    cout << "Yes\n";
                else
                    cout << "No\n";
            }
        }
    }
    return 0;
}