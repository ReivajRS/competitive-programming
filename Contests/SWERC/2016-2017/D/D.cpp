#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

double comb[51][51];
double dp[11][11][11];
bool nums[51][2];
int n, d, c;

void precalculateComb() {
    FOR (i, 0, 51) {
        comb[i][0] = comb[i][i] = 1;
        FOR (j, 1, i) {
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
        }
    }
}

double solve(int s, int a, int b) {
    if ((!a || !b) && !s)
        return 0;
    double &ans = dp[s][a][b];
    if (ans > -1)
        return ans;
    ans = 0;
    for (int i = 0; i <= s; i++) {
        for (int j = 0; j <= min(d - i, a); j++) {
            for (int k = 0; k <= min(d - i - j, b); k++) {
                ans += comb[s][i] * comb[a][j] * comb[b][k] * comb[n - s - a - b][d - i - j - k] * (1 + solve(s - i, a - j, b - k)) / comb[n][d];
            }
        }
    }
    return ans /= 1 - comb[n - s - a - b][d] / comb[n][d];
}

signed main() { __
    cin >> n >> d >> c;

    FOR (i, 0, c) {
        int x;
        cin >> x;
        nums[x][0] = 1;
    }
    FOR (i, 0, c) {
        int x;
        cin >> x;
        nums[x][1] = 1;
    }
    
    int s = 0, a = 0, b = 0;
    FOR (i, 1, n + 1) {
        if (nums[i][0] & nums[i][1])
            s++;
        else if (nums[i][0])
            a++;
        else if (nums[i][1])
            b++;
    }
    
    precalculateComb();
    memset(dp, -1, sizeof dp);

    cout << setprecision(8) << fixed << solve(s, a, b) << ENDL;

    return 0;
}