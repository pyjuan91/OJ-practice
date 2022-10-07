#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
// class Task {
// public:
//     int duration, deadline;
//     Task()
//     {
//         duration = deadline = 0;
//     }
//     Task(int du, int de)
//     {
//         duration = du;
//         deadline = de;
//     }
//     bool operator<(const Task& b) const
//     {
//         if (duration == b.duration)
//             return deadline < b.deadline;
//         return duration < b.duration;
//     }
// };
int main(void)
{
    long long n, du, de, res = 0, cur = 0, deSum = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> du >> de;
        deSum += de;
        v.emplace_back(du);
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 1; i <= n; i++) {
        deSum -= v[i-1] * (long long)i;
    }
    cout << deSum << "\n";
    return 0;
}