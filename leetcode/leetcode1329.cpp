#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat)
    {
        int m = mat.size(), n = mat[0].size(), i, j;
        for (int index = 0; index < m; index++) {
            priority_queue<int, vector<int>, greater<int>> pq;
            i = index, j = 0;
            while (i < m && j < n) {
                pq.push(mat[i][j]);
                i++, j++;
            }
            i = index, j = 0;
            while (i < m && j < n) {
                mat[i][j] = pq.top();
                i++, j++;
                pq.pop();
            }
        }
        for (int index = 0; index < n; index++) {
            priority_queue<int, vector<int>, greater<int>> pq;
            j = index, i = 0;
            while (i < m && j < n) {
                pq.push(mat[i][j]);
                i++, j++;
            }
            j = index, i = 0;
            while (i < m && j < n) {
                mat[i][j] = pq.top();
                i++, j++;
                pq.pop();
            }
        }
        return mat;
    }
};
int main(void) { return 0; }