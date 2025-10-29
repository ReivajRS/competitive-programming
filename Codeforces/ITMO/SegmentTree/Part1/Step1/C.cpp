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
pair<ll, ll> tree[MAXN];

void update(int idx, ll val) {
    idx += n;
    tree[idx] = {val, 1};
    for (idx /= 2; idx >= 1; idx /= 2) {
        if (tree[2*idx].first == tree[2*idx+1].first)
            tree[idx] = {tree[2*idx].first, tree[2*idx].second + tree[2*idx+1].second};
        else
            tree[idx] = min(tree[2*idx], tree[2*idx+1]);
    }
}

pair<ll, ll> query(int a, int b) {
    a += n, b += n;
    pair<ll, ll> val = {2e9, 0};
    while (a <= b) {
        if (a%2 == 1) {
            if (val.first == tree[a].first)
                val = {val.first, val.second + tree[a].second};
            else
                val = min(val, tree[a]);
            a++;
        }
        if (b%2 == 0) {
            if (val.first == tree[b].first)
                val = {val.first, val.second + tree[b].second};
            else
                val = min(val, tree[b]);
            b--;
        }
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
        if (op == 1) {
            update(a, b);
            continue;
        }
        pair<ll, ll> val = query(a, b - 1);
        cout << val.first << ' ' << val.second << ENDL;
    }

    return 0;
}