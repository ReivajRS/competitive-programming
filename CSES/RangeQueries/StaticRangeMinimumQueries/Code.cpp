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

class SparseTable {
 private:
    int LOG, n;
    vi a;
    vector<vi> spT;
    int L2(int x) { return 31 - __builtin_clz(x); }
    int P2(int x) { return 1<<x; }
 public:
    SparseTable(vector<int>& _a) {
        a = _a, n = SZ(a);
        LOG = L2(n) + 1;
        spT.assign(n, vi(LOG));
        FOR (i, 0, n)
            spT[i][0] = a[i];
        FOR (k, 1, LOG) {
            for (int i = 0; i + P2(k) - 1 < n; i++) {
                spT[i][k] = min(spT[i][k - 1], spT[i + P2(k - 1)][k - 1]);
            }
        }
    }
    int query(int a, int b) {
        int LOG = L2(b - a + 1);
        return min(spT[a][LOG], spT[b - P2(LOG) + 1][LOG]);
    }
};

int main() { __
    int n, q;
    cin >> n >> q;
    
    vi a(n);
    for (auto &x : a)
        cin >> x;
    
    SparseTable spt(a);
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << spt.query(l - 1, r - 1) << ENDL;
    }

    return 0;
}