#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#define int long long
    int t, l, n;

    cin >> t;
    for (int kase = 1; kase <= t; kase++) {

        cin >> l >> n;

        vector<int> d(n);
        vector<char> c(n);
        bool cw;
        int pos = 0;
        int res = 0;

        for (int i = 0; i < n; i++) {
            cin >> d[i] >> c[i];
        }

        for (int i = 0; i < n; i++) {
            if (pos == 0) {
                cw = c[i] == 'C' ? true : false;
                res += d[i] / l;
                if (cw) {
                    pos = d[i] % l;
                } else {
                    pos = l - (d[i] % l);
                }
            } else {
                // same direction
                if (cw && c[i] == 'C' || !cw && c[i] == 'A') {
                    if (cw) {
                        res += (d[i] + pos) / l;
                        pos = (d[i] + pos) % l; 
                    } else {
                        res += (d[i] / l) + (pos - d[i] % l <= 0 ? 1 : 0);
                        pos = pos - d[i] % l;
                        pos = pos < 0 ? pos + l : pos;
                    }
                }
                // diff direction
                else {
                    if (c[i] == 'C') {
                        if (pos + d[i] < l) {
                            pos += d[i];
                        } else {
                            cw = true;
                            res += (d[i] / l) + (pos + d[i] % l >= l ? 1 : 0) - 1;
                            pos = (d[i] + pos) % l;
                        }
                    } else {
                        if (pos - d[i] > 0) {
                            pos -= d[i];
                        } else {
                            cw = false;
                            res += (d[i] / l) + (pos - d[i] % l <= 0 ? 1 : 0) - 1;
                            pos = pos - d[i] % l;
                            pos = pos < 0 ? pos + l : pos;
                        }
                    }
                }
            }
            // cout << "d: " << d[i] << " c: " << c[i] << endl;
            // cout << "pos: " << pos << " res: " << res << " cw: " << cw << endl;
        }
        cout << "Case #" << kase << ": " << res << "\n";
    }

    return 0;
}