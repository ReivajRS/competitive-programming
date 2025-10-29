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

int n, q;
ll bit[200005];

ll get(int idx) {
    ll sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

void upd(int idx, ll val) {
    ll dif = val - (get(idx) - get(idx - 1));
    while (idx <= n) {
        bit[idx] += dif;
        idx += idx & (-idx);
    }
}

int main() { __
    cin >> n >> q;

    n++;

    FOR (i, 1, n) {
        ll x;
        cin >> x;
        upd(i, x);
    }

    while (q--) {
        ll op, a, b;
        cin >> op >> a >> b;
        if (op == 1)
            upd(a, b);
        else
            cout << get(b) - get(a - 1) << ENDL;
    }

    return 0;
}