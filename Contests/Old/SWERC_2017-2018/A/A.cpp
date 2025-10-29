#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define ROF(i, a, b) for (ll i = a-1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() {__

    map<ll,ll> mapa;
    ll n,m;
    cin >> n >> m;
    vi a(n);
    for(auto &x:a) cin >> x;
    vi b(m);
    for(auto &x:b) cin >> x;
    FOR(i,0,n){
        FOR(j,0,m){
            if(b[j] > a[i])
                mapa[b[j]-a[i]]++;
        }
    }
    if(!SZ(mapa)){
        cout << 0 << ENDL;
        return 0;
    }
    set<pi> s;
    for(auto &a:mapa){
        //cout << a.first << " " << a.second << ENDL;
        s.insert({-a.second,a.first});
    }

    pi ans = *s.begin();
    cout << ans.second << ENDL;
    

    return 0;
}