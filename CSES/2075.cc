#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node* ch[2];
  int val, prio;
  int cnt;
  int siz;
  int min_child_val;
  bool to_rev = false;  // 需要把这个子树下的每一个节点都翻转过来

  Node(int _val) : val(_val), cnt(1), siz(1), min_child_val(_val) {
    ch[0] = ch[1] = nullptr;
    prio = rand();
  }

  int upd_siz() {
    siz = cnt;
    min_child_val = val;
    if (ch[0] != nullptr) {
      siz += ch[0]->siz;
      min_child_val = min(min_child_val, ch[0]->min_child_val);
    }
    if (ch[1] != nullptr) {
      siz += ch[1]->siz;
      min_child_val = min(min_child_val, ch[1]->min_child_val);
    }
    return siz;
  }

  void pushdown() {
    swap(ch[0], ch[1]);
    if (ch[0] != nullptr) ch[0]->to_rev ^= 1;
    // 如果原来子节点也要翻转，那两次翻转就抵消了，如果子节点不翻转，那这个
    //  tag 就需要继续被 push 到子节点上
    if (ch[1] != nullptr) ch[1]->to_rev ^= 1;
    to_rev = false;
  }

  void check_tag() {
    if (to_rev) pushdown();
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

  void insert(int val) {
    auto temp = split(root, val);
    auto l_tr = split(temp.first, val - 1);
    Node* new_node;
    if (l_tr.second == nullptr) new_node = new Node(val);
    Node* l_tr_combined =
        merge(l_tr.first, l_tr.second == nullptr ? new_node : l_tr.second);
    root = merge(l_tr_combined, temp.second);
  }

  void seg_rev(int l, int r) {
    // 这里的 less 和 more 是相对于 l 的
    auto less = split(root, l - 1);
    // 所有小于等于 l - 1 的会在 less 的左边
    auto more = split(less.second, r - l + 1);
    // 拿出从 l 开始的前 r - l + 1 个
    more.first->to_rev = true;
    root = merge(less.first, merge(more.first, more.second));
  }

  void print(Node* cur) {
    if (cur == nullptr) return;
    cur->check_tag();
    print(cur->ch[0]);
    cout << cur->val << " ";
    print(cur->ch[1]);
  }

  int find(Node* cur, int val) {
    if (cur == nullptr) return 0;
    cur->check_tag();
    if (cur->val == val) return siz(cur->ch[0]) + 1;
    if (cur->ch[0] && cur->ch[0]->min_child_val <= val)
      return find(cur->ch[0], val);
    return siz(cur->ch[0]) + 1 + find(cur->ch[1], val);
  }
};

Seg_treap tr;

int32_t main() {
  srand(time(0));
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, x;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    tr.root = tr.merge(tr.root, new Node(a[i]));

    // tr.print(tr.root);
    // cout << "\n";
  }

  vector<pair<int, int>> res;
  for (int i = 1; i < n; i++) {
    auto [l, r] = tr.split(tr.root, i - 1);
    if (r == nullptr) continue;
    int target_index = tr.find(r, i);
    // cout << "target_index: " << target_index << "\n";
    tr.root = tr.merge(l, r);
    if (target_index != 1) {
      res.push_back(make_pair(i, i + target_index - 1));
      tr.seg_rev(i, i + target_index - 1);
    }
    // tr.print(tr.root);
    // cout << "\n";
  }

  cout << res.size() << "\n";
  for (auto [l, r] : res) cout << l << " " << r << "\n";
  return 0;
}
