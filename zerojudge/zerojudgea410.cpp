// #include <bits/stdc++.h>
// using namespace std;
// int main(void)
// {
//     bool tm = false;
//     long long a, b, c, d, e, f;
//     double x, y;
//     scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e, &f);
//     if (a * e == b * d) {
//         if (a == b && b == 0) {
//             if (c != 0) {
//                 printf("No answer\n");
//                 return 0;
//             }
//             tm = true;
//         }
//         if (d == e && e == 0) {
//             if (f != 0) {
//                 printf("No answer\n");
//                 return 0;
//             }
//             tm = true;
//         }
//         if (tm) {
//             printf("Too many\n");
//             return 0;
//         }
//         if (b == e && e == 0) {
//             if (a * f == c * d)
//                 printf("Too many\n");
//             else
//                 printf("No answer\n");
//             return 0;
//         }
//         if (a == d && d == 0) {
//             if (b * f == c * e)
//                 printf("Too many\n");
//             else
//                 printf("No answer\n");
//             return 0;
//         }
//     }
//     if (a != 0 && d != 0) {
//         long long tmpa = a;
//         a *= d, b *= d, c *= d;
//         d *= tmpa, e *= tmpa, f *= tmpa;
//         y = (double)(c - f) / (double)(b - e);
//         x = (double)(c - b * y) / (double)a;
//     } else {
//         long long tmpb = b;
//         a *= e, b *= e, c *= e;
//         d *= tmpb, e *= tmpb, f *= tmpb;
//         x = (double)(c - f) / (double)(a - d);
//         y = (double)(c - a * x) / double(b);
//     }
//     printf("x=%.2lf\n", x);
//     printf("y=%.2lf\n", y);
//     return 0;
// }

#include <stdio.h>

#include <math.h>

int main()
{

    float a[2][3], v, vx, vy;

    for (int i = 0; i < 2; i++) {

        for (int j = 0; j < 3; j++) {

            scanf("%f", &a[i][j]);
        }
    }

    v = a[0][0] * a[1][1] - a[0][1] * a[1][0];

    vx = a[0][2] * a[1][1] - a[0][1] * a[1][2];

    vy = a[0][0] * a[1][2] - a[0][2] * a[1][0];

    if (v == 0 && vy == 0 && vx == 0) {

        printf("Too many");
    }

    if (v != 0) {

        printf("x=%.2f\n", vx /= v);

        printf("y=%.2f\n", vy /= v);
    }

    if (v == 0 && (vy != 0 || vx != 0)) {

        printf("No answer");
    }

    return 0;
}