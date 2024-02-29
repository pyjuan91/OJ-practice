#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node* ch[2];
  int val, prio;
  char c;
  int siz;
  int incre;

  Node(int _val, char _c) : val(_val), siz(1), incre(0), c(_c) {
    ch[0] = ch[1] = nullptr;
    prio = rand();
  }

  int upd_siz() {
    siz = 1;
    if (ch[0] != nullptr) siz += ch[0]->siz;
    if (ch[1] != nullptr) siz += ch[1]->siz;
    return siz;
  }

  void pushdown() {
    val += incre;
    if (ch[0] != nullptr) ch[0]->incre += incre;
    // 如果原来子节点也要翻转，那两次翻转就抵消了，如果子节点不翻转，那这个
    //  tag 就需要继续被 push 到子节点上
    if (ch[1] != nullptr) ch[1]->incre += incre;
    incre = 0;
  }

  void check_tag() {
    if (incre != 0) pushdown();
  }
};

struct Seg_treap {
  Node* root;
#define siz(_) (_ == nullptr ? 0 : _->siz)

  pair<Node*, Node*> split(Node* cur, int sz) {
    // 按照树的大小划分
    if (cur == nullptr) return {nullptr, nullptr};
    cur->check_tag();
    if (sz <= siz(cur->ch[0])) {
      // 左边的子树就够了
      auto temp = split(cur->ch[0], sz);
      // 左边的子树不一定全部需要，temp.second 是不需要的
      cur->ch[0] = temp.second;
      cur->upd_siz();
      return {temp.first, cur};
    } else {
      // 左边的加上右边的一部分（当然也包括这个节点本身）
      auto temp = split(cur->ch[1], sz - siz(cur->ch[0]) - 1);
      cur->ch[1] = temp.first;
      cur->upd_siz();
      return {cur, temp.second};
    }
  }

  Node* merge(Node* sm, Node* bg) {
    // small, big
    if (sm == nullptr && bg == nullptr) return nullptr;
    if (sm != nullptr && bg == nullptr) return sm;
    if (sm == nullptr && bg != nullptr) return bg;
    sm->check_tag(), bg->check_tag();
    if (sm->prio < bg->prio) {
      sm->ch[1] = merge(sm->ch[1], bg);
      sm->upd_siz();
      return sm;
    } else {
      bg->ch[0] = merge(sm, bg->ch[0]);
      bg->upd_siz();
      return bg;
    }
  }

  void insert(int val, char c) {
    auto temp = split(root, val);
    auto l_tr = split(temp.first, val - 1);
    Node* new_node;
    if (l_tr.second == nullptr) new_node = new Node(val, c);
    Node* l_tr_combined =
        merge(l_tr.first, l_tr.second == nullptr ? new_node : l_tr.second);
    root = merge(l_tr_combined, temp.second);
  }

  void seg_move_to_tail(int l, int r, int n) {
    // 这里的 less 和 more 是相对于 l 的
    auto less = split(root, l - 1);
    // 所有小于等于 l - 1 的会在 less 的左边
    auto more = split(less.second, r - l + 1);
    // 拿出从 l 开始的前 r - l + 1 个
    if (more.first) more.first->incre += n - r;
    if (more.second) more.second->incre += l - r - 1;
    root = merge(less.first, merge(more.second, more.first));
  }

  void print(Node* cur) {
    if (cur == nullptr) return;
    cur->check_tag();
    print(cur->ch[0]);
    cout << cur->val << " ";
    print(cur->ch[1]);
  }

  void inorder(Node* cur) {
    if (cur == nullptr) return;
    cur->check_tag();
    inorder(cur->ch[0]);
    cout << cur->c;
    inorder(cur->ch[1]);
  }
};

Seg_treap tr;

int32_t main() {
  srand(time(0));
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, l, r;
  string s;
  cin >> n >> m >> s;
  s = " " + s;
  for (int i = 1; i <= n; i++) {
    tr.insert(i, s[i]);
  }
  while (m--) {
    cin >> l >> r;
    tr.seg_move_to_tail(l, r, n);
  }
  tr.inorder(tr.root);
  return 0;
}
