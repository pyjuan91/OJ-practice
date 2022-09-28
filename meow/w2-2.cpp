#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
int t, n, a[12], b[12], last[12], last_len, b_len;
vector<vector<int>> ans;
vector<int> e;
void output(void);
bool helper(int, int);
bool myCompare(vector<int>, vector<int>);
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> t >> n && t && n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            last_len = b_len = -1;
            b[i] = last[i] = 0;
            ans.clear();
            e.clear();
        }
        cout << "Sums of " << t << ":\n";
        if (!helper(0, 0))
            cout << "NONE\n";
        else {
            sort(ans.begin(), ans.end(), myCompare);
            output();
        }
    }
    return 0;
}
void output(void)
{
    for (int i = 0; i < ans.size(); i++) {
        if (i == 0 || ans[i] != ans[i - 1]) {
            cout << ans[i][0];
            for (int j = 1; j < ans[i].size(); j++) {
                cout << "+" << ans[i][j];
            }
            cout << "\n";
        }
    }
}
bool helper(int selNum, int pos)
{

    int sum = 0;
    bool checker = false;
    for (int i = 0; i < selNum; i++) {
        sum += b[i];
        if (b[i] != last[i])
            checker = true;
    }

    if (checker && sum == t) {
        e.clear();
        for (int i = 0; i < selNum; i++) {
            e.push_back(b[i]);
        }
        ans.push_back(e);
        return true;
    }

    if (sum >= t)
        return false;

    checker = false;
    for (int i = pos; i < n; i++) {
        b[selNum] = a[i];
        if (sum + a[i] <= t)
            checker |= helper(selNum + 1, i + 1);
        else
            continue;
    }
    return checker;
}
bool myCompare(vector<int> a, vector<int> b)
{
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i])
            continue;
        return a[i] > b[i];
    }
    return false;
}

// #include <algorithm>
// #include <iostream>
// #include <vector>
// using namespace std;
// int t, n, NumOfAns, a[12];
// vector<vector<int>> ans;
// vector<int> e;
// void backTracking(int cur, int sum);
// void output(void);
// bool myCompare(vector<int>, vector<int>);
// int main(void)
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     while (cin >> t >> n && t && n) {
//         for (int i = 0; i < n; i++)
//             cin >> a[i];
//         NumOfAns = 0;
//         ans.clear();
//         e.clear();
//         backTracking(0, 0);
//         sort(ans.begin(), ans.end(), myCompare);
//         output();
//     }
//     return 0;
// }
// void backTracking(int cur, int sum)
// {
//     if (sum == t) {
//         ans.push_back(e);
//         NumOfAns++;
//         return;
//     }
//     for (int i = cur; i < n; i++) {
//         if (sum + a[i] <= t) {

//             sum += a[i];
//             e.push_back(a[i]);
//             backTracking(i + 1, sum);
//             sum -= a[i];
//             e.pop_back();
//         }
//     }
// }
// void output(void)
// {
//     cout << "Sums of " << t << ":\n";
//     if (NumOfAns == 0)
//         cout << "NONE\n";
//     else {
//         for (int i = 0; i < NumOfAns; i++) {
//             if (i == 0 || ans[i] != ans[i - 1]) {
//                 cout << ans[i][0];
//                 for (int j = 1; j < ans[i].size(); j++) {
//                     cout << "+" << ans[i][j];
//                 }
//                 cout << "\n";
//             }
//         }
//         // cout << NumOfAns << endl;
//     }
// }
// bool myCompare(vector<int> a, vector<int> b)
// {
//     for (int i = 0; i < a.size(); i++) {
//         if (a[i] == b[i])
//             continue;
//         return a[i] > b[i];
//     }
//     return a.size() > b.size();
// }
