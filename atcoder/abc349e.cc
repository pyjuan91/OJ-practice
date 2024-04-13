#include <bits/stdc++.h>
#define int long long
using namespace std;

int score[3][3];

struct State {
  int color[3][3];
  int takahashi_score, aoki_score;
  bool takahashi_turn;
  State() {
    takahashi_score = 0;
    aoki_score = 0;
    takahashi_turn = true;
    memset(color, 0, sizeof(color));
  }
  bool operator==(const State& other) const {
    return takahashi_score == other.takahashi_score &&
           aoki_score == other.aoki_score &&
           takahashi_turn == other.takahashi_turn &&
           memcmp(color, other.color, sizeof(color)) == 0;
  }
  bool operator<(const State& other) const {
    if (takahashi_score != other.takahashi_score)
      return takahashi_score < other.takahashi_score;
    if (aoki_score != other.aoki_score) return aoki_score < other.aoki_score;
    if (takahashi_turn != other.takahashi_turn)
      return takahashi_turn < other.takahashi_turn;
    return memcmp(color, other.color, sizeof(color)) < 0;
  }
};

map<State, bool> memo_takahashi_wins;

bool takahashi_wins(const State& state) {
  // wins returns 1, loses returns 0, not determined returns -1
  if (memo_takahashi_wins.count(state)) return memo_takahashi_wins[state];
  // check takahashi same row or column or diagonal
  for (int i = 0; i < 3; i++) {
    if (state.color[i][0] == state.color[i][1] &&
        state.color[i][1] == state.color[i][2]) {
      if (state.color[i][0] == 1) {
        memo_takahashi_wins[state] = true;
        return true;
      }
      if (state.color[i][0] == 2) {
        memo_takahashi_wins[state] = false;
        return false;
      }
    }
    if (state.color[0][i] == state.color[1][i] &&
        state.color[1][i] == state.color[2][i]) {
      if (state.color[0][i] == 1) {
        memo_takahashi_wins[state] = true;
        return true;
      }
      if (state.color[0][i] == 2) {
        memo_takahashi_wins[state] = false;
        return false;
      }
    }
  }
  if (state.color[0][0] == state.color[1][1] &&
      state.color[1][1] == state.color[2][2]) {
    if (state.color[0][0] == 1) {
      memo_takahashi_wins[state] = true;
      return true;
    }
    if (state.color[0][0] == 2) {
      memo_takahashi_wins[state] = false;
      return false;
    }
  }
  if (state.color[0][2] == state.color[1][1] &&
      state.color[1][1] == state.color[2][0]) {
    if (state.color[0][2] == 1) {
      memo_takahashi_wins[state] = true;
      return true;
    }
    if (state.color[0][2] == 2) {
      memo_takahashi_wins[state] = false;
      return false;
    }
  }

  // if no white cell, check the score;
  int white_cnt = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (state.color[i][j] == 0) white_cnt++;
    }
  }
  if (white_cnt == 0) {
    if (state.takahashi_score > state.aoki_score) {
      memo_takahashi_wins[state] = true;
      return true;
    }
    memo_takahashi_wins[state] = false;
    return false;
  }

  // try draws one of the white cells
  bool res = false;
  if (state.takahashi_turn) {
    res = false;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (state.color[i][j] == 0) {
          State next_state = state;
          next_state.color[i][j] = 1;
          next_state.takahashi_score += score[i][j];
          next_state.takahashi_turn = false;
          res |= takahashi_wins(next_state);
        }
      }
    }
  } else {
    res = true;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (state.color[i][j] == 0) {
          State next_state = state;
          next_state.color[i][j] = 2;
          next_state.aoki_score += score[i][j];
          next_state.takahashi_turn = true;
          res &= takahashi_wins(next_state);
        }
      }
    }
  }
  memo_takahashi_wins[state] = res;
  return res;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> score[i][j];
    }
  }
  State init_state;
  cout << (takahashi_wins(init_state) ? "Takahashi" : "Aoki") << '\n';
  return 0;
}
