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
#define ROF(i, a, b) for (int i = a-1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(nullptr);

const int MAXN = 1e5 + 5;

int n = MAXN - 1;
ll bit[MAXN];

void upd(int idx, int val) {
    while (idx <= n) {
        bit[idx] += val;
        idx += idx & (-idx);
    }
}

ll get(int idx) {
    ll sum = 0;
    while (idx > 1) {
        sum += bit[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

vi g[MAXN];
ll rnk[MAXN], rt[MAXN], rtime[MAXN];

void dfs(int u) {
    upd(rnk[u], rt[u]);
    ll inval = get(rnk[u] - 1);
    for (auto v : g[u])
        dfs(v);
    rtime[u] = get(rnk[u] - 1) - inval;
}

signed main() { __
    int e;
    cin >> e;

    int root = -1;

    FOR (i, 0, e) {
        int p, r, t;
        cin >> p >> rnk[i] >> rt[i];
        if (p == -1) {
            root = i;
            continue;
        }
        g[p - 1].pb(i);
    }

    dfs(root);

    FOR (i, 0, e) {
        cout << rtime[i] << ENDL;
    }

    return 0;
}