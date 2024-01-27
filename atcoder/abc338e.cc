#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, a, b;
  cin >> n;
  vector<pair<int, int>> node(2 * n);
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a > b) swap(a, b);
    a--, b--;
    node[a] = make_pair(0, i);
    node[b] = make_pair(1, i);
  }
  stack<int> st;
  for (int i = 0; i < 2 * n; i++) {
    if (node[i].first == 0)
      st.push(i);
    else {
      if (node[i].second != node[st.top()].second) {
        cout << "Yes\n";
        return 0;
      }
      st.pop();
    }
  }
  cout << "No\n";
  return 0;
}