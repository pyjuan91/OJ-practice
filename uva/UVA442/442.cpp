// // UVa442 Matrix Chain Multiplication
// // Rujia Liu
// //
// 題意：輸入n個矩陣的維度和一些矩陣鏈乘運算式，輸出乘法的次數。假定A和m*n的，B是n*p的，那麼AB是m*p的，乘法次數為m*n*p
// //
// 演算法：用一個堆疊。遇到字母時入堆疊，右括弧時出堆疊並計算，然後結果入堆疊。因為輸入保證合法，括弧無序入堆疊
// #include <cstdio>
// #include <iostream>
// #include <stack>
// #include <string>
// using namespace std;

// struct Matrix {
//    int a, b;
//    Matrix(int a = 0, int b = 0) : a(a), b(b) {}
// } m[26];

// stack<Matrix> s;

// int main() {
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//       string name;
//       cin >> name;
//       int k = name[0] - 'A';
//       cin >> m[k].a >> m[k].b;
//    }
//    string expr;
//    while (cin >> expr) {
//       int len = expr.length();
//       bool error = false;
//       int ans = 0;
//       for (int i = 0; i < len; i++) {
//          if (isalpha(expr[i]))
//             s.push(m[expr[i] - 'A']);
//          else if (expr[i] == ')') {
//             Matrix m2 = s.top();
//             s.pop();
//             Matrix m1 = s.top();
//             s.pop();
//             if (m1.b != m2.a) {
//                error = true;
//                break;
//             }
//             ans += m1.a * m1.b * m2.b;
//             s.push(Matrix(m1.a, m2.b));
//          }
//       }
//       if (error)
//          printf("error\n");
//       else
//          printf("%d\n", ans);
//    }

//    return 0;
// }

#include <iostream>
#include <stack>
#include <string>
using namespace std;
typedef struct {
   int a, b;
} matrix;
matrix m[26];
int main(void) {
   int n;
   char c;
   cin >> n;
   while (n--)
      cin >> c >> m[c - 'A'].a >> m[c - 'A'].b;
   string str;
   while (cin >> str) {
      int len = str.size(), error = 0, ans = 0;
      stack<matrix> s;
      for (int i = 0; i < len; i++) {
         if (isalpha(str[i])) {
            s.push(m[str[i] - 'A']);
         } else if (str[i] == ')') {
            matrix m1 = s.top();
            s.pop();
            matrix m2 = s.top();
            s.pop();
            if (m1.a != m2.b) {
               error = 1;
               break;
            }
            ans += m2.a * m2.b * m1.b;
            matrix neo;
            neo.a = m2.a;
            neo.b = m1.b;
            s.push(neo);
         }
      }
      if (error)
         cout << "error\n";
      else
         cout << ans << "\n";
   }
   return 0;
}