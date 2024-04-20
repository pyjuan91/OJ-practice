#include <bits/stdc++.h>
using namespace std;

char toggle_case(char c) {
  if (islower(c)) {
    return toupper(c);
  } else {
    return tolower(c);
  }
}

void kazuha(const vector<int>& right_par_idx, const string& s, bool left_to_right,
            int idx) {
  if (idx == s.size() || idx == -1) return;
  if (left_to_right) {
    if (s[idx] == '(') {
      kazuha(right_par_idx, s, false, right_par_idx[idx] - 1);
      kazuha(right_par_idx, s, true, right_par_idx[idx] + 1);
    } else if (s[idx] == ')') {
      return;
    } else {
      cout << s[idx];
      kazuha(right_par_idx, s, true, idx + 1);
    }
  } else {
    if (s[idx] == ')') {
      kazuha(right_par_idx, s, true, right_par_idx[idx] + 1);
      kazuha(right_par_idx, s, false, right_par_idx[idx] - 1);
    } else if (s[idx] == '(') {
      return;
    } else {
      cout << toggle_case(s[idx]);
      kazuha(right_par_idx, s, false, idx - 1);
    }
  }
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;

  stack<int> left_par_idx;
  vector<int> right_par_idx(s.size(), -1);
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      left_par_idx.push(i);
    } else if (s[i] == ')') {
      right_par_idx[left_par_idx.top()] = i;
      right_par_idx[i] = left_par_idx.top();
      left_par_idx.pop();
    }
  }

  kazuha(right_par_idx, s, true, 0);
  return 0;
}
