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

struct SparseTableMin {
    int LOG;
    vector<vi> st;
    SparseTableMin(vi& a) {
        int n = a.size();
        LOG = 31 - __builtin_clz(n) + 1;
        st.assign(n, vi(LOG));
        FOR (i, 0, n)
            st[i][0] = a[i];   
        FOR (k, 1, LOG) {
            for (int i = 0; i + (1 << k) - 1 < n; i++) {
                st[i][k] = min(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
            }
        }
    }
    int query(int a, int b) {
        int k = 31 - __builtin_clz(b - a + 1);
        return min(st[a][k], st[b - (1 << k) + 1][k]);
    }
};

struct SparseTableMax {
    int LOG;
    vector<vi> st;
    SparseTableMax(vi& a) {
        int n = a.size();
        LOG = ceil(log2(n)) + 1;
        st.assign(n, vi(LOG));
        FOR (i, 0, n)
            st[i][0] = a[i];   
        FOR (k, 1, LOG) {
            for (int i = 0; i + (1 << k) - 1 < n; i++) {
                st[i][k] = max(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
            }
        }
    }
    int query(int a, int b) {
        int k = 31 - __builtin_clz(b - a + 1);
        return max(st[a][k], st[b - (1 << k) + 1][k]);
    }
};

signed main() { __
    int n;
    cin >> n;
    
    vi a(n), b(n);
    FOR (i, 0, n) {
        cin >> a[i] >> b[i];
    }

    SparseTableMin spMin(b);
    SparseTableMax spMax(a);

    auto check = [&](int m) -> bool {
        for (int i = 0; i + m - 1 < n; i++)
            if (spMin.query(i, i + m - 1) - spMax.query(i, i + m - 1) + 1 >= m)
                return true;
        return false;
    };

    int l = 0, r = n;

    while (l < r) {
        int m = (l + r + 1) / 2;
        if (check(m))
            l = m;
        else
            r = m - 1;
    }

    cout << l << ENDL;
    
    return 0;
}