// #include <algorithm>
// #include <iostream>
// #include <map>
// #include <set>
// using namespace std;
// map<int, set<int>> row, col;
// set<int>::iterator iter;
// int main(void)
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int h, w, rs, cs, n, q, r, c, l;
//     char d;
//     cin >> h >> w >> rs >> cs >> n;
//     while (n--) {
//         cin >> r >> c;
//         row[r].insert(c);
//         col[c].insert(r);
//     }
//     cin >> q;
//     while (q--) {
//         cin >> d >> l;
//         int i = -1;
//         switch (d) {
//         case 'U':
//             iter = col[cs].lower_bound(rs - l);
//             while (iter != col[cs].end()) {
//                 if (*iter > rs)
//                     break;
//                 i = *iter;
//                 iter++;
//             }
//             if (i == -1) {
//                 rs = max(1, rs - l);
//             } else {
//                 rs = i + 1;
//             }
//             cout << rs << " " << cs << "\n";
//             break;
//         case 'D':
//             iter = col[cs].upper_bound(rs);
//             if (iter == col[cs].end()) {
//                 rs = min(h, rs + l);
//             } else {
//                 rs = *iter - 1;
//             }
//             cout << rs << " " << cs << "\n";
//             break;
//         case 'L':
//             iter = row[rs].lower_bound(cs - l);
//             while (iter != row[rs].end()) {
//                 if (*iter > cs)
//                     break;
//                 i = *iter;
//                 iter++;
//             }
//             if (i == -1) {
//                 cs = max(1, cs - l);
//             } else {
//                 cs = i + 1;
//             }
//             cout << rs << " " << cs << "\n";
//             break;
//         case 'R':
//             iter = row[rs].upper_bound(cs);
//             if (iter == row[rs].end()) {
//                 cs = min(w, cs + l);
//             } else {
//                 cs = *iter - 1;
//             }
//             cout << rs << " " << cs << "\n";
//             break;
//         default:
//             break;
//         }
//     }
//     return 0;
// }

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int h, w, n, r, c, Q;
map<int, vector<int>> amp, bmp;
int main(void)
{
    cin >> h >> w >> r >> c >> n;
    for (int i = 1; i <= n; i++) {
        int rr, cc;
        cin >> rr >> cc;
        amp[rr].push_back(cc), bmp[cc].push_back(rr);
    }
    for (auto& p : amp)
        sort(p.second.begin(), p.second.end());
    for (auto& p : bmp)
        sort(p.second.begin(), p.second.end());

    cin >> Q;
    char d;
    int l;
    for (int i = 1; i <= Q; i++) {
        cin >> d >> l;
        if (d == 'L') {
            auto it = amp.find(r);
            int lb = 0;
            if (it != amp.end()) {
                vector<int>& vec = it->second;
                auto it2 = lower_bound(vec.begin(), vec.end(), c);
                if (it2 != vec.begin())
                    it2--, lb = *it2;
            }
            c = max(c - l, lb + 1);
        }
        if (d == 'U') {
            auto it = bmp.find(c);
            int lb = 0;
            if (it != bmp.end()) {
                vector<int>& vec = it->second;
                auto it2 = lower_bound(vec.begin(), vec.end(), r);
                if (it2 != vec.begin())
                    it2--, lb = *it2;
            }
            r = max(r - l, lb + 1);
        }
        if (d == 'R') {
            auto it = amp.find(r);
            int ub = w + 1;
            if (it != amp.end()) {
                vector<int>& vec = it->second;
                auto it2 = upper_bound(vec.begin(), vec.end(), c);
                if (it2 != vec.end())
                    ub = *it2;
            }
            c = min(c + l, ub - 1);
        }
        if (d == 'D') {
            auto it = bmp.find(c);
            int ub = h + 1;
            if (it != bmp.end()) {
                vector<int>& vec = it->second;
                auto it2 = upper_bound(vec.begin(), vec.end(), r);
                if (it2 != vec.end())
                    ub = *it2;
            }
            r = min(r + l, ub - 1);
        }
        cout << r << " " << c << "\n";
    }

    return 0;
}