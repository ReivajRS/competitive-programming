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

constexpr int MAXN = 2e5 + 5;
int n, m;
ll tree[MAXN];

void update(int idx, ll val) {
    idx += n;
    tree[idx] = val;
    for (idx /= 2; idx >= 1; idx /= 2) {
        tree[idx] = min(tree[2*idx], tree[2*idx+1]);
    }
}

ll query(int a, int b) {
    a += n, b += n;
    ll val = 2e9;
    while (a <= b) {
        if (a%2 == 1) val = min(val, tree[a++]);
        if (b%2 == 0) val = min(val, tree[b--]);
        a /= 2, b /= 2;
    }
    return val;
}

int main() { __
    cin >> n >> m;

    FOR (i, 0, n) {
        ll x;
        cin >> x;
        update(i, x);
    }

    while (m--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1)
            update(a, b);
        else
            cout << query(a, b - 1) << ENDL;
    }

    return 0;
}