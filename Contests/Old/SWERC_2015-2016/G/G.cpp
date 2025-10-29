#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end();
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(nullptr);

signed main() { __
    ll p, k;
    cin >> p >> k;

    ll nimsum = 0;
    FOR (zzz, 0, p) {
        ll n;
        cin >> n;
        vector<ll> a(n + 1, 0), val(n + 1, 0);
        FOR (i, 1, n + 1)
            cin >> a[i];
        FOR (i, 1, n + 1) {
            set<ll> s;
            if (a[i] <= i)
                s.insert(val[i - a[i]]);
            for (int d = 1; d <= k && i - d >= 1; d++) {
                int j = i - d;
                if (a[j] <= j)
                    s.insert(val[j - a[j]]);
            }
            val[i] = 0;
            while (s.count(val[i]))
                val[i]++;
        }
        nimsum ^= val[n];
    }
    
    if (nimsum == 0)
        cout << "Bob will win." << ENDL;
    else
        cout << "Alice can win." << ENDL;

    return 0;
}