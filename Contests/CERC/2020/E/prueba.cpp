#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((ll)x.size())
#define FOR(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll N = 41;
  vector<ll> a(N+2);
  a[1] = 1;

  FOR(d,0,N-1){
    vector<ll> curr(N+2);
    FOR(i,1,N+1){
      curr[i] = a[i-1] + a[i] + a[i+1];
    }
    swap(a,curr);

    
  }
  vector<ll> ori(a.begin(),a.end());

  sort(a.rbegin(),a.rend());

  FOR(i,0,N){
      cout << a[i] << " ";
      FOR(j,1,N+1){
        if(a[i] == ori[j]){
          cout << j-1 << ENDL;
          break;
        }
      }
  }
  cout << ENDL;



  return 0;
}