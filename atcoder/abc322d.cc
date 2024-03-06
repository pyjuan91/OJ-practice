#include <bits/stdc++.h>
using namespace std;

void Rotate(vector<string>& g) {
  vector<string> res = g;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      res[i][j] = g[3 - j][i];
    }
  }
  swap(g, res);
}

bool chaewon(vector<vector<string>>& g, vector<vector<bool>>& vis, int x, int y,
             int cur) {
  pair<int, int> up_left = {-1, -1};
  vector<vector<bool>> neo_vis = vis;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (g[cur][i][j] == '#') {
        if (up_left.first == -1) up_left = {i, j};
        pair<int, int> relative_pos = {i - up_left.first + x,
                                       j - up_left.second + y};
        if (relative_pos.first < 0 || relative_pos.first >= 4 ||
            relative_pos.second < 0 || relative_pos.second >= 4 ||
            neo_vis[relative_pos.first][relative_pos.second]) {
          return false;
        }
        neo_vis[relative_pos.first][relative_pos.second] = true;
      }
    }
  }
  swap(neo_vis, vis);
  return true;
}

bool kazuha(vector<vector<string>>& g, vector<vector<bool>>& vis, int cur = 0) {
  if (cur == 3) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (!vis[i][j]) {
          return false;
        }
      }
    }
    return true;
  }

  vector<vector<bool>> neo_vis = vis;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (neo_vis[i][j] == false && chaewon(g, neo_vis, i, j, cur)) {
        if (kazuha(g, neo_vis, cur + 1)) {
          return true;
        }
        neo_vis = vis;
      }
    }
  }
  return false;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<vector<string>> g(3, vector<string>(4));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> g[i][j];
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      vector<vector<bool>> vis(4, vector<bool>(4, false));
      if (kazuha(g, vis)) {
        cout << "Yes" << '\n';
        return 0;
      }
      Rotate(g[1]);
    }
    Rotate(g[2]);
  }
  cout << "No" << '\n';
  return 0;
}
