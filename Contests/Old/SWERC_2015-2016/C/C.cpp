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

void solve(){
    ll n;
    cin >> n;
    priority_queue<ll> pq;
    FOR(i,0,n){
        ll x;
        cin >> x;
        pq.push(-x);
    }
    ll ans = 0;
    while(SZ(pq) >= 2){
        ll x = pq.top();
        pq.pop();
        ll y = pq.top();
        pq.pop();
        x *= -1;
        y *= -1;
        ans += x+y;
        pq.push(-(x+y));
    }
    cout << ans << ENDL;

}

signed main() { __
    
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}