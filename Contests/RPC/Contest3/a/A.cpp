#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define ROF(i, a, b) for (ll i = (ll)a-1; i >= (ll)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0);


signed main() { __

ll n,q;
cin >> n >> q;
vi a(n+1);
FOR(i,1,n+1) cin >> a[i];

vi dp(10001, 1e18);
dp[0] = 0;
FOR (i, 1, 10001) {
  if (i <= n) {
    dp[i] = a[i];
    continue;
  }
  FOR (j, 1, n + 1) {
    dp[i] = min(dp[i], a[j] + dp[i - j]);
  }
}

int menor = 1;
FOR (i,1, 10001) {
  if (dp[menor] * i > dp[i]*menor) {
    menor = i;
  }
}

while(q--){
  ll k;
  cin >> k;
  if(k <= 10000){
    cout << dp[k] << ENDL;
    continue;
  }
  ll aux = (k - 10000 + menor - 1) / menor;
  ll k2 = k - aux * menor;
  cout << dp[menor] * aux + dp[k2] << ENDL;
}
  
  return 0;
}