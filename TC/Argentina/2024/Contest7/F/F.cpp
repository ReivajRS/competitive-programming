#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define ROF(i, a, b) for(ll i = (ll)a - 1; i >= (ll)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n,m,k;
  cin >> n >> m >> k;
  vector<vi> puntos(m+1,vi(4,0));
  vector<string> s(n+1);
  ll tot=0;
  FOR(i,1,n+1){
    cin >> s[i];
    tot+=i;
    FOR(j,0,m){
      puntos[j][s[i][j]-'A'] += i;
    }
  }
  FOR(i,1,n+1){
    ll error = (tot-i)*k;
    ll ptsganados = 0;
    FOR(j,0,m){
      ptsganados+=puntos[j][s[i][j]-'A'];
    }
    if(tot*m - ptsganados == error){
      cout << i << ENDL;
      return 0;
    }
  }

  return 0;
}