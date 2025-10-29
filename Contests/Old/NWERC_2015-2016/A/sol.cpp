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
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main () { __
    ll n, m;
    cin >> n >> m;
    vector<pi> a(n);
    for (auto &[x, y] : a)
        cin >> x >> y;
    sort(ALL(a));
    priority_queue<ll> pq;
    ll ans = n;
    for (auto &[x, y] : a) {
        while (!pq.empty() && -pq.top() + m < x)
            pq.pop();
        if (pq.empty() || -pq.top() > x)
            ans--;
        else if (!pq.empty())
            pq.pop();
        pq.push(-(x + y));
    }
    cout << ans << ENDL;
    return 0;
}