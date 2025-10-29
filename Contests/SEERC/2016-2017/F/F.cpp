#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() {

  vector<ll> tope(10,0);
  ll pot26=1;
  FOR(i,1,10){
    pot26*=26;
    tope[i] = tope[i-1]+(pot26*i);
  }

  ll n;
  cin >> n;
  int i = 0;
  while(n>= tope[i]) i++;
  ll aux = (n-tope[i-1])/i;
  ll pos = (n-tope[i-1])%i;

  string num = "";
  FOR(j,0,i){
    num+=char(aux%26)+'A';
    aux/=26;
  }
  reverse(ALL(num));
  cout << num[pos] << ENDL;
   
  return 0;
}