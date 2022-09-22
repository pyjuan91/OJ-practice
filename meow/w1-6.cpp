#include <bits/stdc++.h>
using namespace std;
const int MAP[5][5] {
    0, 1, 2, 3, 4,
    5, 6, 7, 8, 9,
    10, 11, 12, 13, 14,
    15, 16, 17, 18, 19,
    20, 21, 22, 23, 24
};
int n, x[30], y[30], population[30], offices[5], used[30], hasSet[25], res[5], cur = 0;
long long dis = INT32_MAX;
vector<pair<int, int>> v;
struct myPairComp {
    bool operator()(pair<int, int> const& left, pair<int, int> const& right)
    {
        if (left.first == right.first)
            return left.second < right.second;
        return left.first < right.first;
    }
};

void dfs(int p, int office)
{
    if (office >= 5) {
        int sum = 0;
        for (int j = 0; j < 25; j++) {
            int compute = INT32_MAX, temp;
            for (int i = 0; i < 5; i++) {
                temp = population[j] * (abs(offices[i] / 5 - j / 5) + abs(offices[i] % 5 - j % 5));
                compute = min(temp, compute);
            }
            sum += compute;
        }

        if (sum < dis) {
            dis = sum;
            for (int i = 0; i < 5; i++) {
                res[i] = offices[i];
            }
        }
        return;
    }
    for (int i = p + 1; i < 25; i++) {
        offices[office] = i;
        dfs(i, office + 1);
    }
    // for (int i = p + 1; i < n; i++) {
    //     offices[office] = MAP[x[i]][y[i]];
    //     dfs(i, office + 1);
    // }
}
void helper(int now, int pos)
{
    if (now >= 5) {
        int sum = 0;
        for (int j = 0; j < 25; j++) {
            int compute = INT32_MAX, temp;
            for (int i = 0; i < 5; i++) {
                temp = population[j] * (abs(offices[i] / 5 - j / 5) + abs(offices[i] % 5 - j % 5));
                compute = min(temp, compute);
            }
            sum += compute;
        }

        if (sum < dis) {
            dis = sum;
            for (int i = 0; i < 5; i++) {
                res[i] = offices[i];
            }
        }
        return;
    }
    for (int i = pos + 1; i < n; i++) {
        offices[now] = MAP[x[i]][y[i]];
        helper(now + 1, i);
    }
}
void special(void)
{
    for (int i = 0; i < n; i++) {
        res[i] = MAP[x[i]][y[i]];
        hasSet[res[i]] = 1;
    }
    int cnt = 0;
    for (int i = n; i < 5; i++) {
        while (hasSet[cnt])
            cnt++;
        res[i] = cnt;
        hasSet[cnt] = 1;
    }
}
int main(void)
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        dis = INT32_MAX;
        memset(population, 0, sizeof(population));
        memset(hasSet, 0, sizeof(hasSet));
        v.clear();
        for (int i = 0; i < n; i++) {
            pair<int, int> p;
            cin >> p.first >> p.second;
            v.push_back(p);
            cin >> population[MAP[p.first][p.second]];
        }
        sort(v.begin(), v.begin() + n, myPairComp());
        for (int i = 0; i < n; i++) {
            x[i] = v[i].first;
            y[i] = v[i].second;
        }
        if (n <= 5) {
            special();
        } else {
            // helper(0, -1);
            dfs(-1, 0);
        }
        sort(res, res + 5);
        printf("%d %d %d %d %d\n", res[0], res[1],
            res[2], res[3], res[4]);
    }
    return 0;
}

// #include <bits/stdc++.h>
// #define LOCAL
// #define MAXN 30
// using namespace std;
// int num[MAXN], ans[MAXN], result[MAXN];
// int t, n, a, b, c;
// int d = MAXN*MAXN*1000;

// void dfs(int p, int office){
//     if(office >= 5){
//         int sum = 0;
//         for(int j = 0; j < 25; j++){
//             int compute = MAXN*MAXN*1000, temp;
//             for(int i = 0; i < 5; i++){
//                 temp = num[j] * (abs(result[i]/5 - j/5) + abs(result[i]%5 - j%5));
//                 compute = min(temp, compute);
//             }
//             sum += compute;
//         }

//         if(sum < d){
//             d = sum;
//             for(int i = 0; i < 5; i++){
//                 ans[i] = result[i];
//             }
//         }
//         return;
//     }
//     for(int i = p+1; i < 25; i++){
//         result[office] = i;
//         dfs(i, office+1);
//     }
// }

// int main()
// {
//     cin >> t;
//     while(t--){
//         cin >> n;
//         memset(num, 0, sizeof(num));
//         while(n--){ //輸入資料
//             cin >> a >> b >> c;
//             num[a*5+b] = c;
//         }
//         d = MAXN*MAXN*1000;
//         dfs(-1, 0);
//         cout << ans[0];
//         for(int i = 1; i < 5; i++) cout << ' ' << ans[i];
//         cout << '\n';
//     }
//     return 0;
// }