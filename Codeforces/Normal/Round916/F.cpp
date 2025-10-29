#include <bits/stdc++.h>
using namespace std;

#define ENDL '\n'
#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a-1; i >= b; --i)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

vector<vi> g;
vi depth;

void bfs(int src) {
    queue<int> q;
    q.push(src);
    depth[src] = 0;

    while(!q.empty()) {
        int f = q.front();
        q.pop();
        for (int &c : g[f]) {
            if (depth[c] != -1)
                continue;
            depth[c] = depth[f] + 1;
            q.push(c);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    g.assign(n, vi());
    depth.assign(n, -1);

    FOR(i, 1, n) {
        int p;
        cin >> p;
        p--;
        g[p].pb(i), g[i].pb(p);
    }

    bfs(0);

    vi cntDepth(n);
    int mxD = -1;

    for (int &x : depth)
        cntDepth[x]++, mxD = max(mxD, x);

    int ans = 0;

    FOR (d, 1, mxD)
        if (cntDepth[d] >= 2)
            ans++, cntDepth[d] -= 2, cntDepth[d+1] += cntDepth[d];

    cout << ans + cntDepth[mxD]/2 << ENDL;
}

int main() {_
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}