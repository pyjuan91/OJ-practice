#include <vector>
#include <map>
#include "iostream"

using namespace std;
long long res = 0;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
map<char, int> dir = {{'D', 0},
                      {'R', 1},
                      {'U', 2},
                      {'L', 3}};

// D, R, U, L
void solve(vector<char> &route, int cur,
           vector<vector<bool>> &visit, int cx, int cy,
           int d) {
    if (cur == 48) {
        if (cx == 6 && cy == 0) res += 1;
        return;
    }
    if (route[cur] == '?') {
        // go straight and cut two
        if (d != -1) {
            int fx = cx + dx[d];
            int fy = cy + dy[d];
            int lrd = 1 - (d % 2);
            int lx = cx + dx[lrd];
            int ly = cy + dy[lrd];
            int rx = cx + dx[lrd + 2];
            int ry = cy + dy[lrd + 2];
            if (!(fx >= 0 && fx < 7 && fy >= 0 && fy < 7 && !visit[fx][fy])
                && (lx >= 0 && lx < 7 && ly >= 0 && ly < 7 && !visit[lx][ly]) &&
                (rx >= 0 && rx < 7 && ry >= 0 && ry < 7 && !visit[rx][ry]))
                return;
        }
        //
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || ny < 0 || nx >= 7 || ny >= 7 ||
                visit[nx][ny])
                continue;
            if (nx == 6 && ny == 0 && cur + 1 != 48) continue;
            visit[nx][ny] = true;
            solve(route, cur + 1, visit, nx, ny, i);
            visit[nx][ny] = false;
        }
    } else {
        int nx = cx + dx[dir[route[cur]]];
        int ny = cy + dy[dir[route[cur]]];
        if (nx < 0 || nx >= 7 || ny < 0 || ny >= 7 ||
            visit[nx][ny])
            return;
        if (nx == 6 && ny == 0 && cur + 1 != 48) return;
        visit[nx][ny] = true;
        solve(route, cur + 1, visit, nx, ny,
              dir[route[cur]]);
        visit[nx][ny] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    vector<char> route(48);
    vector<vector<bool>> visit(7, vector<bool>(7, false));
    for (int i = 0; i < 48; i++) cin >> route[i];
    visit[0][0] = true;
    solve(route, 0, visit, 0, 0, -1);
    cout << res;
    return 0;
}