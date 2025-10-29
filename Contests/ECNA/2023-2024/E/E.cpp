#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;

  if (s.back() != 'O') {
    cout << "INVALID" << ENDL;
    return 0;
  }

  FOR (i, 0, SZ(s) - 1) {
    if ((s[i] == 'O' && s[i] == s[i + 1] )|| (s[i] != 'O' && s[i] != 'E')) {
      cout << "INVALID" << ENDL;
      return 0;
    }
  }

  // 6 3 10 5 16 8 4 2 1 4 2 1
  // E O E OR
  vector<ll> posibles;
  ll aux = 4;
  FOR(i,0,50){
    aux*=2;
    if((aux-1)%3 == 0) posibles.pb((aux-1)/3);
  }
  ll ans = 1e15;
  for(auto posible:posibles){
    bool sirve = true;
    ROF(i,SZ(s)-1,0){
      if(s[i] == 'E') posible *=2;
      else{
        if((posible-1)%3 != 0) {
          sirve = false;
          break;
        }else{
          posible = (posible-1)/3;
        }
      }
    }
    if(sirve){
      cout << posible << ENDL;
      return 0;
    }
  }
  if(ans == 1e15){
    cout << "INVALID" << ENDL;
    return 0;
  }
  cout << ans << ENDL;

  return 0;
}