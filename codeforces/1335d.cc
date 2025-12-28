#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

char get_not_me(char c) {
  if (c == '1') return '2';
  return '1';
}

void make_anti_suduku(vector<string>& sudoku) {
  sudoku[0][0] = get_not_me(sudoku[0][0]);
  sudoku[1][3] = get_not_me(sudoku[1][3]);
  sudoku[2][6] = get_not_me(sudoku[2][6]);
  sudoku[3][1] = get_not_me(sudoku[3][1]);
  sudoku[4][4] = get_not_me(sudoku[4][4]);
  sudoku[5][7] = get_not_me(sudoku[5][7]);
  sudoku[6][2] = get_not_me(sudoku[6][2]);
  sudoku[7][5] = get_not_me(sudoku[7][5]);
  sudoku[8][8] = get_not_me(sudoku[8][8]);
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    vector<string> sudoku(9);
    for (auto& s : sudoku) cin >> s;
    make_anti_suduku(sudoku);
    for (const auto& s : sudoku) cout << s << "\n";
    cout << "\n";
  }
  return 0;
}
