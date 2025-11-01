#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s1, s2;
    cin >> s1 >> s2;

    int n = int(s1.size()), m = int(s2.size());
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, int(1e9)));
    
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= m; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
            dp[i][j] = min({dp[i][j], dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
        }
    }

    cout << dp[n][m] << '\n';
}