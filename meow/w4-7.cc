#include <bits/stdc++.h>
using namespace std;
bool check(vector<long long>&, vector<long long>&,
    vector<long long>&, long long, long long);
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#define int long long
    int t, n, k, a, b, c;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> myHorse(n);
        vector<int> growsRate(n);
        vector<int> oppoHorse(n);
        for (int i = 0; i < n; i++) {
            cin >> myHorse[i] >> growsRate[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> oppoHorse[i];
        }
        sort(oppoHorse.begin(), oppoHorse.end());
        int left = -1, right = 1e8 + 5, hasSol = false;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (check(myHorse, growsRate, oppoHorse, k, mid)) {
                right = mid;
                hasSol = true;
            } else
                left = mid;
        }
        if (hasSol)
            cout << right << "\n";
        else
            cout << "-1\n";
    }
    return 0;
}
bool check(vector<int>& myHorse, vector<int>& growsRate,
    vector<int>& oppoHorse, int targetWinning, int trainning)
{
    int n = myHorse.size();
    vector<int> afterTrainning(n);
    for (int i = 0; i < n; i++) {
        afterTrainning[i] = myHorse[i] + growsRate[i] * trainning;
    }
    sort(afterTrainning.begin(), afterTrainning.end(), greater<int>());
    int chose = 0;
    for (int i = targetWinning - 1; i >= 0; i--) {
        if (afterTrainning[chose] <= oppoHorse[i])
            return false;
        chose += 1;
    }
    return true;
}