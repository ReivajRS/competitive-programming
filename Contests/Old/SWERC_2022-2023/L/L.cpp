#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a-1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

int main() {__
    int n;
    cin >> n;
    ll p = 0, m = 0;
    FOR (i,0 , n) {
        char c;
        cin >> c;
        if (c == '+')
            p++;
        else
            m++;
    }

    auto ans = [&](bool b) -> string {
        return b ? "YES" : "NO";
    };

    int q;
    cin >> q;
    while (q--) {
        ll a, b;
        cin >> a >> b;
        if (p == m) {
            cout << "YES" << ENDL;
            continue;
        }
        if (a < b)
            swap(a, b);

        ll s = a * (p - m), d = abs(a - b);
        if (s < 0) {
            cout << ans(d && abs(s) % d == 0 && abs(s) / d <= m) << ENDL;
            continue;
        }
        cout << ans(d && abs(s) % d == 0 && abs(s) / d <= p) << ENDL;
    }

    // int q;
    // cin >> q;
    // while(q--){
    //     ll a,b;
    //     cin >> a >> b;
    //     if (p == m) {
    //         cout << "YES" << ENDL;
    //         continue;
    //     }
    //     if(a == b){
    //         cout << "NO" << ENDL;
    //         continue;
    //     }
    //     if(a<b) swap(a,b);
    //     ll c = a*min(p,m)-b*max(p,m);

    // }

    return 0;
}