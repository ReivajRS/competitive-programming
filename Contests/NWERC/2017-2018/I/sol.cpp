#include <bits/stdc++.h>
using namespace std;
// BRO... CSMS
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = a - 1; i >= b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
int N, C;
vi a, b, p, res;
vector<vector<ll>> dp;
vector<vector<bool>> taked;

ll solve(int i, int c) {
    if (i == N) return 0;
    ll &ans = dp[i][c];
    if (ans != -1) return ans;
    ans = solve(i + 1, c);
    if (c - max(a[p[i]], b[p[i]]) >= 0) {
        ll nw = 1 + solve(i + 1, c - b[p[i]]);
        if (nw > ans) {
            taked[i][c] = 1;
            ans = nw;
        }
    }
    return ans;
}

void track(int i, int c) {
    if (i == N) return;
    if (!taked[i][c]) {
        track(i + 1, c);
        return;
    }
    res.pb(p[i] + 1);
    track(i + 1, c - b[p[i]]);
}

signed main() {
    cin >> N >> C;
    a.resize(N), b.resize(N);
    FOR (i, 0, N) {
        cin >> a[i] >> b[i];
    }
    p.resize(N);
    iota(ALL(p), 0);
    sort(ALL(p), [&](int i, int j) { 
        return (a[i]-b[i] > a[j]-b[j]);
    });
    taked.assign(N, vector<bool>(C + 1, 0));
    dp.assign(N, vector<ll>(C + 1, -1));
    cout << solve(0, C) << ENDL;
    track(0, C);
    for (auto &x : res) cout << x << ' ';
    cout << ENDL;

    return 0;   
}