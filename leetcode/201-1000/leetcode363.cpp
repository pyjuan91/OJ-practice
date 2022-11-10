#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
private:
    int m, n;
    int max1D(vector<int>& v)
    {
        int ans = INT_MIN, sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum > 0)
                sum += v[i];
            else
                sum = v[i];
            ans = max(ans, sum);
        }
        return ans;
    }

    int max2D(vector<vector<int>> v, int limit)
    {
        int ans = INT_MIN, ret = INT_MIN;

        for (int i = 0; i < m; i++) {
            vector<int> sum(n);
            for (int j = i; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    sum[k] += v[j][k];
                }
                ans = max(ans, max1D(sum));
                if (ans <= limit) {
                    ret = max(ans, ret);
                    continue;
                }
                set<int> s = { 0 };
                int summing = 0;
                for (int k = 0; k < n; k++) {
                    summing += sum[k];
                    set<int>::iterator iter = s.lower_bound(summing - limit);
                    if (iter != s.end()) {
                        ret = max(ret, summing - *iter);
                    }
                    s.insert(summing);
                }
            }
        }
        return ret;
    }

public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k)
    {
        m = matrix.size(), n = matrix[0].size();
        int ans = max2D(matrix, k);
        if (ans == INT_MIN)
            return -1;
        return ans;
    }
};

// class Solution {
// public:
//     int maxSumSubmatrix(vector<vector<int>>& m, int k)
//     {
//         int res = INT_MIN, rows = m.size(), cols = m[0].size();
//         for (int l = 0; l < cols; ++l) {
//             vector<int> sums(rows);
//             for (int r = l; r < cols; ++r) {
//                 int kadane = 0, max_kadane = INT_MIN;
//                 for (int i = 0; i < rows; ++i) {
//                     sums[i] += m[i][r];
//                     kadane = max(kadane + sums[i], sums[i]);
//                     max_kadane = max(max_kadane, kadane);
//                 }
//                 if (max_kadane <= k) {
//                     res = max(res, max_kadane);
//                     cout << "l: " << l << " r: " << r << " res: " << res << endl;
//                     continue;
//                 }
//                 set<int> s = { 0 };
//                 int run_sum = 0;
//                 for (int sum : sums) {
//                     run_sum += sum;
//                     auto it = s.lower_bound(run_sum - k);
//                     if (it != end(s))
//                         res = max(res, run_sum - *it);
//                     s.insert(run_sum);
//                 }
//                 cout << "l: " << l << " r: " << r << " res: " << res << endl;
//             }
//         }
//         return res;
//     }
// };
int main(void)
{
    Solution s;
    vector<vector<int>> matrix;
    // vector<int> v(4);
    // v = { 5, -4, -3, 4 };
    // matrix.push_back(v);
    // v = { -3, -4, 4, 5 };
    // matrix.push_back(v);
    // v = { 5, 1, 5, -4 };
    // matrix.push_back(v);
    vector<int> v(3);
    v = { 2, 2, -1 };
    matrix.push_back(v);
    cout << s.maxSumSubmatrix(matrix, 3) << endl;
    return 0;
}