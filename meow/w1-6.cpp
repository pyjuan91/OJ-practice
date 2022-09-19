// #include <bits/stdc++.h>
// using namespace std;
// const int MAP[5][5] {
//     0, 1, 2, 3, 4,
//     5, 6, 7, 8, 9,
//     10, 11, 12, 13, 14,
//     15, 16, 17, 18, 19,
//     20, 21, 22, 23, 24
// };
// int n, x[30], y[30], population[30], offices[5], used[30], hasSet[25], res[5];
// long long dis = INT32_MAX;
// void helper(int now)
// {
//     if (now == 5) {
//         long long sum = 0, tps;
//         for (int i = 0; i < n; i++) {
//             cout << "x: " << x[i] << " y: " << y[i] << endl;
//             if (used[MAP[x[i]][y[i]]]) {
//                 continue;
//             }
//             tps = INT32_MAX;
//             for (int j = 0; j < 5; j++) {
//                 tps = min(tps,
//                     (long long)abs(offices[i] / 5 - x[i]) + (long long)abs((offices[i] % 5) - y[i]));
//             }
//             sum += tps;
//         }
//         if (sum < dis) {
//             for (int i = 0; i < 5; i++)
//                 res[i] = offices[i];
//         }
//         return;
//     }
//     for (int i = 0; i < n; i++) {
//         if (used[i] == 0) {
//             offices[now] = MAP[x[i]][y[i]];
//             used[i] = 1;
//             helper(now + 1);
//             used[i] = 0;
//         }
//     }
// }
// void special(void)
// {
//     for (int i = 0; i < n; i++) {
//         res[i] = MAP[x[i]][y[i]];
//         hasSet[offices[i]] = 1;
//     }
//     int cnt = 0;
//     for (int i = n; i < 5; i++) {
//         while (hasSet[cnt])
//             cnt++;
//         res[i] = cnt;
//         hasSet[cnt] = 1;
//     }
// }
// int main(void)
// {
//     int t;
//     cin >> t;
//     while (t--) {
//         cin >> n;
//         dis = 0;
//         for (int i = 0; i < n; i++) {
//             cin >> x[i] >> y[i] >> population[i];
//             used[i] = hasSet[i] = 0;
//         }
//         if (n <= 5) {
//             special();
//         } else {
//             helper(0);
//         }
//         sort(res, res + 5);
//         printf("%d %d %d %d %d\n", res[0], res[1],
//             res[2], res[3], res[4]);
//     }
//     return 0;
// }

#include <bits/stdc++.h>
#define LOCAL
#define MAXN 30
using namespace std;
int num[MAXN], ans[MAXN], result[MAXN];
int t, n, a, b, c; 
int d = MAXN*MAXN*1000;

void dfs(int p, int office){
    if(office >= 5){ 
        int sum = 0; 
        for(int j = 0; j < 25; j++){ 
            int compute = MAXN*MAXN*1000, temp; 
            for(int i = 0; i < 5; i++){ 
                temp = num[j] * (abs(result[i]/5 - j/5) + abs(result[i]%5 - j%5));
                compute = min(temp, compute); 
            }
            sum += compute; 
        }

        if(sum < d){ 
            d = sum; 
            for(int i = 0; i < 5; i++){ 
                ans[i] = result[i];
            }
        }
        return;
    }
    for(int i = p+1; i < 25; i++){
        result[office] = i; 
        dfs(i, office+1);
    }
}

int main()
{
    cin >> t;
    while(t--){
        cin >> n;
        memset(num, 0, sizeof(num));
        while(n--){ //輸入資料
            cin >> a >> b >> c;
            num[a*5+b] = c;
        }
        d = MAXN*MAXN*1000;
        dfs(-1, 0); 
        cout << ans[0];
        for(int i = 1; i < 5; i++) cout << ' ' << ans[i]; 
        cout << '\n';
    }
    return 0;
}