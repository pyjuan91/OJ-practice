#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;
#define endl '\n'
string ans_a, ans_b, ans_c;
bool hasSol = false;
bool check(string a, string b, string c)
{
    long long val_a = 0, val_b = 0, val_c = 0;
    for (int i = 0; i < a.length(); i++)
        val_a += (long long)(a[i] - '0') * pow(10, i);

    for (int i = 0; i < b.length(); i++)
        val_b += (long long)(b[i] - '0') * pow(10, i);

    for (int i = 0; i < c.length(); i++)
        val_c += (long long)(c[i] - '0') * pow(10, i);

    return val_a + val_b == val_c;
}
void dfs(string a, string b, string c, int pendding)
{
    if (hasSol == true)
        return;
    if (pendding == 0 && check(a, b, c)) {
        ans_a = a;
        ans_b = b;
        ans_c = c;
        hasSol = true;
        return;
    }
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == 'X') {
            pendding -= 1;
            for (int j = 0; j < 10; j++) {
                if (i == a.length() && j == 0)
                    continue;
                a[i] = (char)('0' + j);
                // cout << a << endl;
                // cout << "pedding: " << pendding << endl;
                dfs(a, b, c, pendding);
                if (hasSol)
                    return;
            }
        }
    }

    for (int i = 0; i < b.length(); i++) {
        if (b[i] == 'X') {
            pendding -= 1;
            for (int j = 0; j < 10; j++) {
                if (i == b.length() - 1 && j == 0)
                    continue;
                b[i] = (char)('0' + j);
                // cout << b << endl;
                // cout << "pedding: " << pendding << endl;
                dfs(a, b, c, pendding);
                if (hasSol)
                    return;
            }
        }
    }

    for (int i = 0; i < c.length(); i++) {
        if (c[i] == 'X') {
            pendding -= 1;
            for (int j = 0; j < 10; j++) {
                if (i == c.length() - 1 && j == 0)
                    continue;
                c[i] = (char)('0' + j);
                // cout << c << endl;
                // cout << "pedding: " << pendding << endl;
                dfs(a, b, c, pendding);
                if (hasSol)
                    return;
            }
        }
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, op, b, eq, c;
    bool minus = false;
    cin >> a >> op >> b >> eq >> c;
    if (op == "-") {
        minus = true;
        swap(a, c);
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());

    int pedding = 0;
    for (int i = 0; i < a.length(); i++)
        if (a[i] == 'X')
            pedding += 1;
    for (int i = 0; i < b.length(); i++)
        if (b[i] == 'X')
            pedding += 1;
    for (int i = 0; i < c.length(); i++)
        if (c[i] == 'X')
            pedding += 1;

    dfs(a, b, c, pedding);

    if (minus)
        swap(ans_a, ans_c);

    reverse(ans_a.begin(), ans_a.end());
    reverse(ans_b.begin(), ans_b.end());
    reverse(ans_c.begin(), ans_c.end());

    cout << ans_a << " " << ans_b << " " << ans_c << endl;

    return 0;
}