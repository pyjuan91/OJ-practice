#include <cstdio>
int a[25], sel[25], n, m;
void helper(int now, int pos)
{
    if (now == m) {
        printf("%d", sel[0]);
        for (int i = 1; i < m; i++)
            printf(" %d", sel[i]);
        printf("\n");
        return;
    }
    for (int i = pos; i < n; i++) {
        sel[now] = a[i];
        helper(now + 1, i + 1);
    }
}
int main(void)
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    helper(0, 0);
    return 0;
}