#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        
        vector<vector<int>> rows;
        vector<int> ini;
        ini.push_back(1);
        rows.push_back(ini);
        for(int i=2;i<=numRows;i++)
        {
            vector<int> row;
            row.push_back(1);
            for(int j=0;j<i-2;j++)
            {
                row.push_back(rows[i-2][j]+rows[i-2][j+1]);
            }
            row.push_back(1);
            rows.push_back(row);
        }
    return rows;
    }
};
int main(void)
{
    return 0;
}