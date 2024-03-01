#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int t, n;
  char c;
  cin >> t;

  auto ask = [&](int a, int b, int c, int d) {
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
    cout.flush();
    char res;
    cin >> res;
    return res;
  };

  auto answer = [&](int a, int b) {
    cout << "! " << a << " " << b << endl;
    cout.flush();
  };

  while (t--) {
    cin >> n;
    int largest_idx = 0;
    for (int i = 1; i < n; i++) {
      c = ask(largest_idx, largest_idx, i, i);
      if (c == '<') largest_idx = i;
    }
    vector<int> nice_pair_candidates = {largest_idx};
    for (int i = 0; i < n; i++) {
      if (i == largest_idx) continue;
      c = ask(largest_idx, nice_pair_candidates.back(), i, largest_idx);
      if (c == '<') {
        nice_pair_candidates.clear();
        nice_pair_candidates.push_back(i);
      } else if (c == '=') {
        nice_pair_candidates.push_back(i);
      }
    }

    int smallest_idx = nice_pair_candidates[0];
    for (int i = 1; i < nice_pair_candidates.size(); i++) {
      c = ask(smallest_idx, smallest_idx, nice_pair_candidates[i],
              nice_pair_candidates[i]);
      if (c == '>') smallest_idx = nice_pair_candidates[i];
    }

    answer(largest_idx, smallest_idx);
  }
  return 0;
}
