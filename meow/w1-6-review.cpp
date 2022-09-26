#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
using namespace std;
int x[25], y[25], popu[25], sel[5], ans[5];
long long mi, diff, ad;
class node {
public:
    int x, y, popu;
    node()
    {
        x = y = popu = 0;
    }
    node(int x, int y, int popu)
    {
        this->x = x;
        this->y = y;
        this->popu = popu;
    }
    bool operator<(const node& b) const
    {
        if (x == b.x)
            return y < b.y;
        return x < b.x;
    }
};
node list[25];
void helper(int n, int now, int pos)
{
    if (now == 5) {
        ad = 0;
        for (int i = 0; i < n; i++) {
            diff = INT32_MAX;
            for (int j = 0; j < 5; j++) {
                diff = min(diff,
                    (long long)(abs(x[i] - sel[j] / 5) + abs(y[i] - (sel[j] % 5))) * popu[i]);
            }
            ad += diff;
        }
        if (ad < mi) {
            ans[0] = sel[0];
            ans[1] = sel[1];
            ans[2] = sel[2];
            ans[3] = sel[3];
            ans[4] = sel[4];
            mi = ad;
        }
        return;
    }
    for (int i = pos; i < n; i++) {
        sel[now] = x[i] * 5 + y[i];
        helper(n, now + 1, i + 1);
    }
}
void special(int n)
{
    int remain = 5 - n, checker = 1;
    for (int i = 0; i < n; i++) {
        ans[i] = x[i] * 5 + y[i];
    }
    for (int i = n; i < 5; i++) {
        for (int j = 0; j < 25; j++) {
            checker = 1;
            for (int k = 0; k < i; k++) {
                if (ans[k] == j)
                    checker = 0;
            }
            if (checker == 1) {
                ans[i] = j;
                break;
            }
        }
    }
}
int main(void)
{
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", x + i, y + i, popu + i);
            node e(x[i], y[i], popu[i]);
            list[i] = e;
        }
        sort(list, list + n);
        for (int i = 0; i < n; i++) {
            x[i] = list[i].x;
            y[i] = list[i].y;
            popu[i] = list[i].popu;
        }
        mi = INT32_MAX;
        if (n > 5) {
            helper(n, 0, 0);
        } else {
            special(n);
        }
        sort(ans, ans + 5);
        printf("%d", ans[0]);
        for (int i = 1; i < 5; i++) {
            printf(" %d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}