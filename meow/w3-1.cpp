#include <iostream>
using namespace std;
long long k, Red, Blue, Purple;
int n, m, nr, nd, mr, md;
long long AR[1000005], AD[1000005], BR[1000005], BD[1000005];
void input(void)
{
    cin >> k >> n >> m;
    int i;
    for (i = 0; i < n / 2; i++) {
        cin >> AR[i] >> AD[i];
        nr = nd = i + 1;
    }
    if (n % 2) {
        cin >> AR[i];
        nr = i + 1;
    }
    for (i = 0; i < m; i++) {
        cin >> BD[i] >> BR[i];
        mr = md = i + 1;
    }
    if (m % 2) {
        cin >> BD[i];
        md = i + 1;
    }
}
void solve(long long r, long long c, int curAR, int curAD, int curBR, int curBD)
{
    
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Red = Blue = Purple = 0;
    input();

    return 0;
}