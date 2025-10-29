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
#define ROF(i, a, b) for (ll i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

ll n, r, p;
vi dp;
ll cnt = 0;
ll solve(ll x){
    if(x <= 1) return 0;
    ll &ans = dp[x];
    if(ans != -1) return ans;
    dp[x] = 3e17;
    FOR(i,2,x+1){
        dp[x] = min(dp[x],(i-1)*p + solve(((x + i - 1) / i)) + r);
    }
    return ans;
}

signed main () { __
    
    cin >> n >> r >> p;

    dp.assign(n+5,-1);

    cout << solve(n) << ENDL;

    return 0;
}