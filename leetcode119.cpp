#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> rows;
        vector<int> ini;
        ini.push_back(1);
        rows.push_back(ini);
        for (int i = 1; i <= rowIndex; i++)
        {
            vector<int> row;
            row.push_back(1);
            for (int j = 0; j < i - 1; j++)
            {
                row.push_back(rows[i - 1][j] + rows[i - 1][j + 1]);
            }
            row.push_back(1);
            rows.push_back(row);
        }
        return rows[rowIndex];
    }
};
int main(void)
{
    Solution s;
    vector<int> v = s.getRow(5);
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}