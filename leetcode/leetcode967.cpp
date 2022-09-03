#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    vector<int> v;

public:
    vector<int> numsSameConsecDiff(int n, int k)
    {
        v.clear();
        solve(n, k);
        return v;
    }

    void solve(int n, int diff)
    {
        int entry, digit = n;
        if (diff == 0) {
            for (int i = 1; i <= 9; i++) {
                entry = 0;
                while (digit--) {
                    entry *= 10;
                    entry += i;
                }
                v.push_back(entry);
            }
            return;
        }
        if (n == 2) {
            for (int i = 1; i <= 9; i++) {
                if (i - diff >= 0) {
                    v.push_back(i * 10 + i - diff);
                }
                if (i + diff < 10) {
                    v.push_back(i * 10 + i + diff);
                }
            }
        } else {
            solve(n - 1, diff);
            int sz = v.size(), isModify, cal, veiai;
            for (int i = 0; i < sz; i++) {
                isModify = 0;
                veiai = v[i];
                cal = veiai % 10 - diff;
                if (cal >= 0) {
                    isModify = 1;
                    v[i] *= 10;
                    v[i] += cal;
                }
                cal = veiai % 10 + diff;
                if (cal < 10) {
                    if (isModify == 0) {
                        v[i] *= 10;
                        v[i] += cal;
                    } else {
                        entry = veiai;
                        entry *= 10;
                        entry += cal;
                        v.push_back(entry);
                    }
                }
            }
        }
        return;
    }
};
int main(void) { return 0; }