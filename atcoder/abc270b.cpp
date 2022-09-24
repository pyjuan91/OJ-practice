#include <cmath>
#include <cstdio>
using namespace std;
int main(void)
{
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    if (x == 0) {
        printf("0\n");
        return 0;
    }
    if (x > 0) {
        if (y < 0 || x < y) {
            printf("%d\n", x);
            return 0;
        } else {
            if (z > y) {
                printf("-1\n");
                return 0;
            } else {
                printf("%d\n", abs(z) - z + x);
                return 0;
            }
        }
    } else {
        if (y > 0 || y < x) {
            printf("%d\n", 0 - x);
            return 0;
        } else {
            if (z < y) {
                printf("-1\n");
                return 0;
            } else {
                printf("%d\n", abs(z) + z - x);
                return 0;
            }
        }
    }
    return 0;
}