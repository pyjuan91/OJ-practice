#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int a[25], sel[25], n;
long long diff, mi = INT_MAX;
void helper(int cur)
{
    if (cur == n) {
        diff = 0;
        for (int i = 0; i < n; i++) {
            if (sel[i] == 1) {
                diff += (long long)a[i];
            } else {
                diff -= (long long)a[i];
            }
        }
        mi = min(mi, llabs(diff));
        return;
    }
    sel[cur] = 1;
    helper(cur + 1);
    sel[cur] = 0;
    helper(cur + 1);
}
int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    helper(0);
    printf("%d\n", mi);
    return 0;
}