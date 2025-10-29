#include <bits/stdc++.h>
using namespace std;

#define ENDL '\n'
#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a-1; i >= b; --i)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

void solve() {
    int n;
    cin >> n;

    vi a(n + 2), pre(n + 2), nxt(n + 2);
    vector<bool> inpq(n + 2, 0);
    priority_queue<pi> pq;
    
    auto check = [&](int i) -> bool {
        if (i < 1 || i > n)
            return false;
        return a[pre[i]] == a[i] - 1 || a[nxt[i]] == a[i] - 1;
    };

    FOR (i, 1, n + 1){
        cin >> a[i];
        pre[i] = i - 1;
        nxt[i] = i + 1;
    }

    a[0] = -1e9, a[n + 1] = -1e9;

    FOR (i, 1, n + 1) {
        if (check(i))
            inpq[i] = 1, pq.push({a[i], i});
    }

    while (!pq.empty()) {
        auto [v, i] = pq.top();
        pq.pop();
        // cout << v << ' ' << i << ENDL;

        nxt[pre[i]] = nxt[i];
        pre[nxt[i]] = pre[i];
        
        if (!inpq[pre[i]] && check(pre[i])) {
            inpq[pre[i]] = 1;
            pq.push({a[pre[i]], pre[i]});
        }
        if (!inpq[nxt[i]] && check(nxt[i])) {
            inpq[nxt[i]] = 1;
            pq.push({a[nxt[i]], nxt[i]});
        }
    }

    int cnt = 0, mn = INT_MAX;
    FOR (i, 1, n + 1) {
        cnt += !inpq[i];
        mn = min(mn, a[i]);
    }

    cout << (cnt == 1 && mn == 0 ? "YES" : "NO") << ENDL;
}

int main() {_
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}