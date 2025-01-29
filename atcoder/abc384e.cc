#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int int64_t
using namespace std;

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int H, W, X, P, Q;
  cin >> H >> W >> X >> P >> Q;
  P--, Q--;
  vector<vector<int>> grid(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> grid[i][j];
    }
  }
  vector<vector<bool>> visited(H, vector<bool>(W));
  struct Node {
    int x, y, strength;
    Node(int x, int y, int strength) : x(x), y(y), strength(strength) {}
    Node() {}
    bool operator<(const Node& other) const {
      return strength > other.strength;
    }
  };
  priority_queue<Node> adjacents;
  int current_strength = grid[P][Q];
  visited[P][Q] = true;

  const int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
  for (int i = 0; i < 4; i++) {
    int x = P + dx[i], y = Q + dy[i];
    if (x >= 0 and x < H and y >= 0 and y < W) {
      adjacents.push(Node(x, y, grid[x][y]));
      visited[x][y] = true;
    }
  }

  auto int128 = [](int x) -> __int128_t {
    return static_cast<__int128_t>(x);
    };

  while (not adjacents.empty()) {
    // cout << "Current strength: " << current_strength << '\n';
    Node smallest = adjacents.top();
    // cout << "Smallest strength: " << smallest.strength << '\n';
    adjacents.pop();
    if (int128(smallest.strength) * X >= int128(current_strength)) break;
    current_strength += grid[smallest.x][smallest.y];
    for (int i = 0; i < 4; i++) {
      int x = smallest.x + dx[i], y = smallest.y + dy[i];
      if (x >= 0 and x < H and y >= 0 and y < W and not visited[x][y]) {
        adjacents.push(Node(x, y, grid[x][y]));
        visited[x][y] = true;
      }
    }
  }
  cout << current_strength << '\n';
  return 0;
}
