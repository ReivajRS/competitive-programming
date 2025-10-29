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

vector<vi> g, cc;
vi colors;
vector<pi> comps;
pi cnt;

bool dfs(int u, int color) {
    colors[u] = color;
    cc[SZ(comps)].pb(u);
    if (color == 0)
        cnt.first++;
    else
        cnt.second++;
    for (auto &v : g[u]) {
        if (colors[v] != -1) {
            if (colors[v] == color)
                return false;
            continue;
        }
        if (!dfs(v, color ^ 1))
            return false;
    }
    return true;
}

int dp[11][1 << 11];
int mn = 1e9, msk = 0;

int solve(int i, int mask) {
    if (i == SZ(comps)) {
        int a = 0, b = 0;
        for (int j = 0; j < i; j++) {
            int bit = mask & (1 << j);
            a += bit ? comps[j].second : comps[j].first;
            b += bit ? comps[j].first : comps[j].second;
        }
        int diff = abs(a - b);
        if (diff < mn)
            mn = diff, msk = mask;
        return diff;
    }

    int &ans = dp[i][mask];
    if (ans != -1)
        return ans;
    
    return min(solve(i + 1, mask), solve(i + 1, mask | (1 << i)));
}

signed main() { __
    int n, m;
    cin >> n >> m;

    g.assign(n, vi()), cc.assign(n, vi());
    colors.assign(n, -1);

    FOR (i, 0, m) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    bool bipartite = true;

    FOR (i, 0, n) {
        if (colors[i] == -1) {
            cnt = {0, 0};
            bipartite &= dfs(i, 0);
            comps.pb(cnt);
        }
    }

    if (!bipartite) {
        cout << "NO" << ENDL;
        return 0;
    }

    // memset(dp, -1, sizeof dp);
    
    // solve(0, 0);

    FOR (mask, 0, (1 << (SZ(comps)))) {
        int a = 0, b = 0;
        for (int j = 0; j < SZ(comps); j++) {
            int bit = mask & (1 << j);
            a += bit ? comps[j].second : comps[j].first;
            b += bit ? comps[j].first : comps[j].second;
        }
        int diff = abs(a - b);
        if (diff < mn)
            mn = diff, msk = mask;
        // return diff;
    }

    vi c1, c2;

    FOR (i, 0, SZ(comps)) {
        bool bit = msk & (1 << i);
        for (auto &x : cc[i]) {
            if (colors[x] == bit)
                c1.pb(x);
            else
                c2.pb(x);
        }
    }

    cout << "YES" << ENDL;
    cout << mn << ENDL;

    cout << SZ(c1) << ' ';
    for (auto &c : c1)
        cout << c << ' ';
    cout << ENDL;

    cout << SZ(c2) << ' ';
    for (auto &c : c2)
        cout << c << ' ';
    cout << ENDL;

    return 0;
}