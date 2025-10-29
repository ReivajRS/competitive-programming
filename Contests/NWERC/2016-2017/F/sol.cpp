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

template <typename T>
struct SparseTable {
    vector<vector<T>> SpT;
    inline int L2(int x) { return 31-__builtin_clz(x); }
    inline int P2(int x) { return 1<<x; }
    
    SparseTable(vector<T> &initialA) {  // O(n log n)
        int n = SZ(initialA), LOG = L2(n) + 1;
        SpT.assign(LOG, vi(n));
        for (int j = 0; j < n; ++j)
            SpT[0][j] = initialA[j];
        for (int i = 1; i <= LOG; ++i)
            for (int j = 0; j+P2(i)-1 < n; ++j)
                SpT[i][j] = max(SpT[i-1][j], SpT[i-1][j + P2(i-1)]);
    }

    T RMQ(int i, int j) {   // O(1) [i, r]
        int k = L2(j-i+1);
        return max(SpT[k][i], SpT[k][j-P2(k)+1]);
    }
};

signed main() { __
    int n;
    cin >> n;
    vi w(2 * n);
    unordered_map<int, pi> pos;
    set<int> idxs;
    FOR (i, 0, 2 * n) {
        cin >> w[i];
        if (!pos.count(w[i]))
            pos[w[i]].first = i;
        else
            pos[w[i]].second = i;
        idxs.insert(i);
    }

    int mx = 0;
    set<int> unord;
    for (auto &[k, v] : pos) {
        if (v.second - v.first > 1 && !(v.first < n && v.second >= n))
            unord.insert(k);
        if (v.first < n && v.second >= n)
            mx = max(mx, k);
    }

    if (unord.empty()) {
        cout << mx << ENDL;
        return 0;
    }

    SparseTable<int> spt(w);

    while (!unord.empty()) {
        int last = *unord.rbegin();
        int maxInRange = spt.RMQ(pos[last].first + 1, pos[last].second - 1);
        mx = max(mx, min(last, maxInRange));
        int i = pos[last].first;
        while (i <= pos[last].second) {
            unord.erase(w[i]);
            idxs.erase(pos[w[i]].first);
            idxs.erase(pos[w[i]].second);
            auto it = idxs.lower_bound(i + 1);
            if (it == idxs.end())
                break;
            i = *it;
        }
    }

    cout << mx << ENDL;

    return 0;
}