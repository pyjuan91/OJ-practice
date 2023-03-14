#include <bits/stdc++.h>
using namespace std;
int N;
double dp[305][305][305];
int plate[4] = {}, p;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p;
		plate[p] += 1;
	}
	// f(i,j,k) means the excepted number under the situation
	// of i one-plate, j two-plate, k three-plate

	// f(i,j,k) = 1 + finish excepted number(0, 1, 2, 3)
	// = 1 + (N-i-j-k)/N * f(i,j,k) + i/N * f(i-1, j, k)
	//     + j/N * f(i+1, j-1, k) + k/N * f(i, j+1, k-1)
	//
	//
	// => (1 - 1 + (i+j+k)/N) * f(i,j,k) = 1 + i/N * f(i-1,j,k) ...
	// => f(i,j,k) = N/(i+j+k) + i/(i+j+k) * f(i-1,j,k)
	//          +j/(i+j+k) * f(i+1,j-1,k) + k/(i+j+k) * f(i,j+1,k-1)

	// because k is driven by k-1 meeting j+1 when (j, k)
	// k must be outer than j
    // beacause j is driven by j-1 meeting i+1 when (i, j)
    // j must be outer than i

	for (int k = 0; k <= N; k++) {
		for (int j = 0; j <= N; j++) {
			for (int i = 0; i <= N; i++) {
				if (i)
					dp[i][j][k]
					  += (double) i / (i + j + k) * dp[i - 1][j][k];
				if (j)
					dp[i][j][k] += (double) j / (i + j + k)
								 * dp[i + 1][j - 1][k];
				if (k)
					dp[i][j][k] += (double) k / (i + j + k)
								 * dp[i][j + 1][k - 1];
				if (i || j || k)
					dp[i][j][k] += (double) N / (i + j + k);
			}
		}
	}
	cout << setprecision(20) << dp[plate[1]][plate[2]][plate[3]];
	return 0;
}