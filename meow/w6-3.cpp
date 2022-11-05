#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { 1, -1, 0, 0 };
const string dir[4] = { "R", "L", "D", "U" };
const string dirB[4] = { "L", "R", "U", "D" };
char grid[1005][1005];
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    pair<int, int> start, end;
    // input
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                start = { i, j };
            if (grid[i][j] == 'B')
                end = { i, j };
        }

    for (int i = 0; i <= n + 1; i++)
        grid[i][0] = grid[i][m + 1] = '#';
    for (int j = 0; j <= m + 1; j++)
        grid[0][j] = grid[n + 1][j] = '#';

    queue<pair<int, int>> point;
    queue<int> step;
    queue<string> route;
    map<pair<int, int>, int> A, B;
    map<pair<int, int>, string> AA, BB;

    point.push(start);
    step.push(0);
    route.push("");
    point.push(end);
    step.push(0);
    route.push("");
    A[start] = 0;
    B[end] = 0;
    AA[start] = "";
    BB[end] = "";

    while (!point.empty()) {
        pair<int, int> cur_point = point.front();
        bool isA
            = grid[cur_point.first][cur_point.second] == 'A';
        
        int cur_step = isA?A[cur_point]:B[cur_point];
        string cur_route = isA?AA[cur_point]:BB[cur_point];

        point.pop();

        for (int i = 0; i < 4; i++) {

            pair<int, int> new_point
                = make_pair(cur_point.first + dx[i], cur_point.second + dy[i]);

            if (isA && grid[new_point.first][new_point.second] == 'B') {
                std::cout << "YES\n"
                          << cur_step + B[new_point] + 1 << "\n"
                          << cur_route + dir[i] + BB[new_point] << "\n";
                return 0;
            }

            if (!isA && grid[new_point.first][new_point.second] == 'A') {
                std::cout << "YES\n"
                          << A[new_point] + cur_step + 1 << "\n"
                          << AA[new_point] + dirB[i] + cur_route << "\n";
                return 0;
            }

            if (grid[new_point.first][new_point.second] != '.')
                continue;
            point.push(new_point);
            step.push(cur_step + 1);
            if (isA) {
                route.push(cur_route + dir[i]);
                A[new_point] = cur_step + 1;
                AA[new_point] = cur_route + dir[i];

                grid[new_point.first][new_point.second] = 'A';
            } else {
                route.push(dirB[i] + cur_route);
                B[new_point] = cur_step + 1;
                BB[new_point] = dirB[i] + cur_route;

                grid[new_point.first][new_point.second] = 'B';
            }
        }
    }
    std::cout << "NO\n";

    return 0;
}