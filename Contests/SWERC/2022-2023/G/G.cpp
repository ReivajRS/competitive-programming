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

int main() {__
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll b = 0;
    FOR(i,0,n){
        if(s[i] == 'W') b++;
    }
    ll ans = b;
    FOR(i,n,SZ(s)){
        if(s[i] == 'W') b++;
        if(s[i-n] == 'W') b--;
        ans = max(ans,b);
    }
    cout << ans << ENDL;
    // RRRWWRRRR
}