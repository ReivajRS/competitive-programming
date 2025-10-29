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
#define ROF(i, a, b) for (int i = a-1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(nullptr);

ll sum(ll x){
    return x*(x+1)/2;
}

signed main() { __
    ll d,r,t;
    cin >> d >> r >> t;
    FOR(i,d+3,1000){
        ll c1 = sum(i) - sum(3);
        ll j = i-d;
        ll c2 = sum(j) - sum(2);
        ll x1 = abs(r-c1);
        ll x2 = abs(t-c2);
        if(x1 == x2){
            cout << x1 << ENDL;
            break;
        }
    }
    return 0;
}