#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define ROF(i,a,b) for(ll i = (ll)a-1; i >= (ll)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n,q;
  cin >> n >> q;
  vi a(n);
  FOR(i,0,n) cin >> a[i];
  vi p1(n+1,0);
  vi p2(n+1,0);
  vi p3(n+1,0);
  FOR(i,1,n+1){
      p3[i] = p3[i-1] + (a[i-1] == 1);
        if(__builtin_popcountll(a[i-1]) == 1 && a[i-1] != 1)
      p1[i] = p1[i-1] + a[i-1];
    else{
      p1[i] = p1[i-1];
    }

    if(a[i-1]%2 && a[i-1] != 1){
      p2[i] = p2[i-1] + a[i-1];
    }else{
      p2[i] = p2[i-1];
    }
  }

  while(q--){
    ll l,r;
    cin >> l >> r;
    ll aa = p1[r]-p1[l-1] + (p3[r]-p3[l-1] +1 )/2;
    ll bb = p2[r]-p2[l-1] + (p3[r]-p3[l-1])/2;
    //cout << aa << " " << bb << ENDL;
    if(aa == bb){
      cout << "E" << ENDL;
      
    }else if(aa>bb){
      cout << "A" << ENDL;
    }else{
      cout << "B" << ENDL;
    }
  }

  return 0;
}