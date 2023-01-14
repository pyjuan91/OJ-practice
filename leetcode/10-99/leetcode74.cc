#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size(), k = n * m;
        int left = 0, right = k - 1, mid;
        if (target < matrix[0][0] || target > matrix[right / m][right % m])
            return false;
        while (left + 1 < right) {
            mid = left + (right - left) / 2;
            if (matrix[mid / m][mid % m] == target)
                return true;
            else if (matrix[mid / m][mid % m] <= target)
                left = mid;
            else
                right = mid;
        }
        if (matrix[right / m][right % m] == target)
            return true;
        if (matrix[left / m][left % m] == target)
            return true;
        return false;
    }
};
int main(void) { return 0; }