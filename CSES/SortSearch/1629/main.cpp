#include <vector>
#include "iostream"
#include "algorithm"

using namespace std;

class Movie {
public:
    int start, end;

    Movie() {
        start = end = 0;
    }

    Movie(int _start, int _end) {
        start = _start;
        end = _end;
    }

    bool operator<(const Movie &b) const {
        if (this->end == b.end) return this->start < b.start;
        return this->end < b.end;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n, res = 0, a, b, cur = 0;
    vector<Movie> v;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.emplace_back(a, b);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (v[i].start < cur) continue;
        res += 1;
        cur = v[i].end;
    }
    cout << res;
    return 0;
}