#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
struct node {
   node *left, *right;
   int v;
   node() : left(nullptr), right(nullptr), v(0) {}
};
vector<int> in, post;
node* newnode() {
   return new node();
}
node* build(int L1, int R1, int L2, int R2) {
   if (L1 > R1)
      return nullptr;
   node* root = newnode();
   root->v = post[R2];
   int p = L1;
   while (in[p] != root->v)
      p++;
   int left_node_num = p - L1;
   root->left = build(L1, p - 1, L2, L2 + left_node_num - 1);
   root->right = build(p + 1, R1, L2 + left_node_num, R2 - 1);
   return root;
}
int best, best_leave;
void dfs(node* root, int sum) {
   sum += root->v;
   if (root->left == nullptr && root->right == nullptr) {
      if (sum < best || (sum == best && root->v < best_leave)) {
         best = sum;
         best_leave = root->v;
      }
      return;
   }
   if (root->left)
      dfs(root->left, sum);
   if (root->right)
      dfs(root->right, sum);
}
int main(void) {
   string str;
   int num;
   while (getline(cin, str)) {
      in.clear();
      post.clear();
      stringstream ss(str);
      while (ss >> num)
         in.push_back(num);
      getline(cin, str);
      ss.str("");
      ss.clear();
      ss << str;
      while (ss >> num)
         post.push_back(num);
      node* root = build(0, in.size() - 1, 0, post.size() - 1);
      best = 99999999, best_leave = 10005;
      dfs(root, 0);
      cout << best_leave << endl;
   }
   return 0;
}

// // UVa548 Tree
// // Rujia Liu
// #include <algorithm>
// #include <iostream>
// #include <sstream>
// #include <string>
// using namespace std;

// // 因為各個節點的權值各不相同且都是正整數，直接用權值作為節點編號
// const int maxv = 10000 + 10;
// int in_order[maxv], post_order[maxv], lch[maxv], rch[maxv];
// int n;

// bool read_list(int* a) {
//    string line;
//    if (!getline(cin, line))
//       return false;
//    stringstream ss(line);
//    n = 0;
//    int x;
//    while (ss >> x)
//       a[n++] = x;
//    return n > 0;
// }

// // 把in_order[L1..R1]和post_order[L2..R2]建成一棵二元樹，返回樹根
// int build(int L1, int R1, int L2, int R2) {
//    if (L1 > R1)
//       return 0;  // 空樹
//    int root = post_order[R2];
//    int p = L1;
//    while (in_order[p] != root)
//       p++;
//    int cnt = p - L1;  // 左子樹的節點個數
//    lch[root] = build(L1, p - 1, L2, L2 + cnt - 1);
//    rch[root] = build(p + 1, R1, L2 + cnt, R2 - 1);
//    return root;
// }

// int best, best_sum;  // 目前為止的最優解和對應的權和

// void dfs(int u, int sum) {
//    sum += u;
//    if (!lch[u] && !rch[u]) {  // 葉子
//       if (sum < best_sum || (sum == best_sum && u < best)) {
//          best = u;
//          best_sum = sum;
//       }
//    }
//    if (lch[u])
//       dfs(lch[u], sum);
//    if (rch[u])
//       dfs(rch[u], sum);
// }

// int main() {
//    while (read_list(in_order)) {
//       read_list(post_order);
//       build(0, n - 1, 0, n - 1);
//       best_sum = 1000000000;
//       dfs(post_order[n - 1], 0);
//       cout << best << "\n";
//    }
//    return 0;
// }