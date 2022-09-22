#include <bits/stdc++.h>
using namespace std;
void helperHook(int n);
void helperRemove(int n);
int main(void)
{
    int n;
    cin >> n;
    helperRemove(n);
    return 0;
}
void helperHook(int n)
{
    if (n == 1) {
        printf("Move ring 1 in\n");
        return;
    }

    if (n == 2) {
        printf("Move ring 1 in\n");
        printf("Move ring 2 in\n");
        return;
    }

    helperHook(n - 1);
    helperRemove(n - 2);
    printf("Move ring %d in\n", n);
    helperHook(n - 2);
}
void helperRemove(int n)
{
    if (n == 1) {
        printf("Move ring 1 out\n");
        return;
    }

    if (n == 2) {
        printf("Move ring 2 out\n");
        printf("Move ring 1 out\n");
        return;
    }

    helperRemove(n - 2);
    printf("Move ring %d out\n", n);
    helperHook(n - 2);
    helperRemove(n - 1);
}