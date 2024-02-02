#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int a, b, c;
  while (cin >> a >> b >> c) {
    using pii = pair<int, int>;
    pii king = make_pair(a / 8, a % 8);
    pii queen = make_pair(b / 8, b % 8);
    pii tar = make_pair(c / 8, c % 8);
    auto check_same = [&]() { return a == b; };
    auto check_illegal_move = [&]() {
      set<pii> us;
      for (int diff = 1; diff < 8; diff++) {
        pii up_node = make_pair(queen.first - diff, queen.second);
        if (up_node == king) break;
        us.insert(up_node);
      }
      for (int diff = 1; diff < 8; diff++) {
        pii down_node = make_pair(queen.first + diff, queen.second);
        if (down_node == king) break;
        us.insert(down_node);
      }
      for (int diff = 1; diff < 8; diff++) {
        pii left_node = make_pair(queen.first, queen.second - diff);
        if (left_node == king) break;
        us.insert(left_node);
      }
      for (int diff = 1; diff < 8; diff++) {
        pii right_node = make_pair(queen.first, queen.second + diff);
        if (right_node == king) break;
        us.insert(right_node);
      }
      return us.count(tar);
    };
    auto check_allowed_move = [&]() {
      set<pii> us;
      for (int diff = 1; diff < 8; diff++) {
        pii up_node = make_pair(queen.first - diff, queen.second);
        if (abs(up_node.first - king.first) +
                abs(up_node.second - king.second) <=
            1)
          continue;
        us.insert(up_node);
      }
      for (int diff = 1; diff < 8; diff++) {
        pii down_node = make_pair(queen.first + diff, queen.second);
        if (abs(down_node.first - king.first) +
                abs(down_node.second - king.second) <=
            1)
          continue;
        us.insert(down_node);
      }
      for (int diff = 1; diff < 8; diff++) {
        pii left_node = make_pair(queen.first, queen.second - diff);
        if (abs(left_node.first - king.first) +
                abs(left_node.second - king.second) <=
            1)
          continue;
        us.insert(left_node);
      }
      for (int diff = 1; diff < 8; diff++) {
        pii right_node = make_pair(queen.first, queen.second + diff);
        if (abs(right_node.first - king.first) +
                abs(right_node.second - king.second) <=
            1)
          continue;
        us.insert(right_node);
      }
      return us.count(tar);
    };
    auto check_continue = [&]() {
      const int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
      for (int i = 0; i < 4; i++) {
        int neo_x = king.first + dx[i];
        int neo_y = king.second + dy[i];
        if (neo_x < 0 || neo_x >= 8 || neo_y < 0 || neo_y >= 8) continue;
        if (neo_x != tar.first && neo_y != tar.second) return true;
      }
      return false;
    };
    if (check_same())
      cout << "Illegal state\n";
    else if (!check_illegal_move())
      cout << "Illegal move\n";
    else if (!check_allowed_move())
      cout << "Move not allowed\n";
    else if (check_continue())
      cout << "Continue\n";
    else
      cout << "Stop\n";
  }
  return 0;
}
