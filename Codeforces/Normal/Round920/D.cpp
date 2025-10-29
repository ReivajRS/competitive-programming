#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
    int n, m;
    cin >> n >> m;

    multiset<int> a, b;
    FOR (i, 0, n) {
        int x;
        cin >> x;
        a.insert(x);
    }
    FOR (i, 0, m) {
        int x;
        cin >> x;
        b.insert(x);
    }

    int cnt = 0;
    ll sum = 0;

    while (cnt < n) {
        auto mna = a.begin(), mxa = prev(a.end());
        auto mnb = b.begin(), mxb = prev(b.end());
        if (abs(*mna - *mxb) >= abs(*mnb - *mxa)) {
            sum += abs(*mna - *mxb);
            a.erase(mna);
            b.erase(mxb);
        }
        else {
            sum += abs(*mnb - *mxa);
            a.erase(mxa);
            b.erase(mnb);
        }
        cnt++;
    }

    cout << sum << ENDL;
}

signed main() { __
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}