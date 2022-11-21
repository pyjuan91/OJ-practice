#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
    {
        const int m = maze.size();
        const int n = maze[0].size();

        const int dx[4] = { 0, 0, 1, -1 };
        const int dy[4] = { 1, -1, 0, 0 };

        queue<pair<int, int>> q;
        queue<int> step;

        maze[entrance[0]][entrance[1]] = '+';
        q.push({ entrance[0], entrance[1] });
        step.push(0);

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            int cs = step.front();
            step.pop();

            for (int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n
                    && maze[nx][ny] == '.') {
                    if (nx == 0 || nx == m - 1 || ny == 0 || ny == n - 1)
                        return cs + 1;
                    maze[nx][ny] = '+';
                    q.push({ nx, ny });
                    step.push(cs + 1);
                }
            }
        }

        return -1;
    }
};
int main(void) { return 0; }