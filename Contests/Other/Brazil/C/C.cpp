#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((ll)x.size())
#define FOR(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll b,n;
  cin >> b >> n;
  ll sumim = 0,sumpa = 0;
  vector<ll> a(n);
  FOR(i,0,n){
    cin >> a[i];
    if(i&1){
      sumim += a[i];
    }else{
      sumpa += a[i];
    }
  }

  ll aux = sumpa-sumim;
  aux %= (b+1);
  if(aux < 0) aux+=b+1;
  if(aux == 0){
    cout << "0 0\n";
    return 0;
  }
  FOR(i,0,n){
    if(i%2 == 0){
      if(a[i]-aux>=0){
        cout << i+1 << " " << a[i]-aux << "\n";
        return 0;
      }
    }else{
      if(a[i]- (b+1-aux) >= 0){
        cout << i+1 << " " << a[i] - (b+1-aux) << '\n';
        return 0;
      }
    }
  }
  cout << "-1 -1" << '\n';

  return 0;
}