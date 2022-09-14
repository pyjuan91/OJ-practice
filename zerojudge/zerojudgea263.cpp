#include <bits/stdc++.h>
using namespace std;
class Calendar {
private:
    int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

public:
    int y, m, d;

    Calendar(int y, int m, int d)
    {
        this->y = y;
        this->m = m;
        this->d = d;
    }

    Calendar& operator=(Calendar b)
    {
        this->y = b.y;
        this->m = b.m;
        this->d = b.d;
        return *this;
    }

    void swap(Calendar& a, Calendar& b)
    {
        Calendar c(a.y, a.m, a.d);
        a = b;
        b = c;
    }

    bool operator<(Calendar& b) const
    {
        if (y == b.y && m == b.m)
            return d < b.d;
        if (y == b.y)
            return m < b.m;
        return y < b.y;
    }

    bool renNian(int y)
    {
        if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
            return true;
        return false;
    }

    long long minus(Calendar& a, Calendar& b)
    {
        long long res = 0;

        if (b.m == 2 && renNian(b.y)) {
            res += (long long)a.d + (long long)(29 - b.d);
        } else {
            res += (long long)a.d + (long long)(month[b.m] - b.d);
        }

        for (int i = b.m + 1; i < 13; i++) {
            if (i == 2 && renNian(b.y))
                res += (long long)29;
            else
                res += (long long)month[i];
        }

        for (int i = a.m - 1; i > 0; i--) {
            if (i == 2 && renNian(a.y))
                res += (long long)29;
            else
                res += (long long)month[i];
        }

        if (a.y == b.y) {
            res -= renNian(a.y) ? (long long)366 : (long long)365;
        } else {
            for (int i = b.y + 1; i < a.y; i++) {
                res += renNian(i) ? (long long)366 : (long long)365;
            }
        }

        return res;
    }

    long long diffZero(Calendar& a)
    {
        long long res = 0;
        for (int i = 0; i < a.y; i++) {
            res += renNian(i) ? 366 : 365;
        }
        for (int i = 1; i < a.m; i++) {
            if (i == 2 && renNian(a.y))
                res += 29;
            else
                res += month[i];
        }
        res += a.d;
        return res;
    }
};
int main(void)
{
    int y1, y2, m1, m2, d1, d2;
    long long la, lb, da, db;
    Calendar c(0, 0, 0);
    while (cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2) {
        Calendar a(y1, m1, d1), b(y2, m2, d2);
        // if (a < b)
        //     a.swap(a, b);
        // cout << a.minus(a, b) << endl;
        la = a.minus(a, c);
        lb = b.minus(b, c);
        da = a.diffZero(a);
        cout << la << " " << da << endl;
        cout << labs(la - lb) << endl;
    }
    return 0;
}