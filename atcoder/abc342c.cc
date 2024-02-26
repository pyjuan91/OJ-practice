#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
  int pos;
  Node* next;
  Node() : pos(-1), next(nullptr) {}
};

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  string s;
  cin >> n >> s >> q;
  vector<Node*> head(26);
  vector<Node*> tail(26);
  for (int i = 0; i < 26; i++) {
    auto node = new Node();
    head[i] = tail[i] = node;
  }
  for (int i = 0; i < s.size(); i++) {
    int c = s[i] - 'a';
    tail[c]->next = new Node();
    tail[c] = tail[c]->next;
    tail[c]->pos = i;
  }
  // for (int i=0;i<26;i++) {
  //   cout << head[i]->pos << " " << tail[i]->pos << endl;
  // }
  while (q--) {
    char c1, c2;
    cin >> c1 >> c2;
    int org = c1 - 'a';
    int rep = c2 - 'a';
    Node* org_head = head[org]->next;
    // cout << org << " " << rep << endl;
    if (org_head == nullptr || org == rep) continue;
    tail[rep]->next = org_head;
    tail[rep] = tail[org];
    // auto cur = head[rep]->next;
    // while (cur != nullptr) {
    //   cout << cur->pos << " ";
    //   cur = cur->next;
    // }
    // cout << endl;
    tail[org] = head[org];
    head[org]->next = nullptr;
    // cout << head[rep]->pos << " " << tail[rep]->pos << endl;
    // auto cur = head[rep]->next;
    // while (cur != nullptr) {
    //   cout << cur->pos << " ";
    //   cur = cur->next;
    // }
    // cout << endl;
  }
  string ans(n, ' ');
  for (int i = 0; i < 26; i++) {
    Node* cur = head[i]->next;
    while (cur != nullptr) {
      ans[cur->pos] = (char)('a' + i);
      cur = cur->next;
    }
  }
  cout << ans << '\n';
  return 0;
}
