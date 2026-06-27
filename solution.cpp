#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if (!(cin >> N)) return 0;
    vector<int> c(N);
    for (int i = 0; i < N; i++) cin >> c[i];
    
    vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
    
    for (int len = 1; len <= N; len++) {
        for (int l = 0; l + len - 1 < N; l++) {
            int r = l + len - 1;
            dp[l][r] = 1 + dp[l+1][r];
            for (int i = l + 1; i <= r; i++) {
                if (c[l] == c[i]) {
                    int mid = (i == l + 1) ? 0 : dp[l+1][i-1];
                    int right = (i == r) ? 0 : dp[i+1][r];
                    dp[l][r] = min(dp[l][r], mid + right);
                }
            }
        }
    }
    cout << dp[0][N-1] << "\n";
    return 0;
}