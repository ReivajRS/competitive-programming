#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define ROF(i, a, b) for (ll i = a-1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

vector<vector<ll>> dp;
vector<ll> x;
ll n, h;

ll diagonal(int l, int r) {
    return (x[r] - x[l]) >> 1;
}

ll solve(int l, int r) {
    if (l == r)
        return 0;
    ll &ans = dp[l][r];
    if (ans != -1)
        return ans;
    ans = 0;
    for (int k = l; k < r; k ++){
        ans = min(ans, solve(l, k) + max(0LL,(h+1 - diagonal(l, k))) + max(0LL,(h+1-diagonal(k + 1, r))) + solve(k + 1, r));
    }
        
    return ans;
}

int main() {__
    cin >> n >> h; 
    x.assign(n, 0);
    FOR (i,0,n)
        cin >> x[i];
    dp.assign(n, vector<ll>(n, -1));
    ll dia = diagonal(0,n-1),torre = 0;
    if(dia < h){
        torre = h-dia;
    }
    // .###.
    // #..#
    //
    //
    ll ans = solve(0, n - 1) + (min(diagonal(0, n - 1), h)) * 2 + torre; 
    cout << ans << ENDL;
}