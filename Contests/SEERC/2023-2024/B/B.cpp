#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define ENDL '\n'

using ll = long long;

using vi = vector<ll>;
signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n;
  cin >> n;
  vector<ll> a(n);
  ll tot = 0;
  map<ll,vi> mp;
  FOR(i,0,n){
    cin >> a[i];
    mp[a[i]].push_back(i);
    tot+=a[i];
  }
  if(tot*2 % n != 0){
    cout << "-1" << ENDL;
    return 0;
  }
  ll media = tot*2/n;
  vi ans(n);
  FOR(i,0,n){

    if(mp[media-a[i]].empty()){
      cout << "-1" << ENDL;
      return 0;
    }
    
    ans[i] = mp[media-a[i]].back();
    ans[mp[media-a[i]].back()] = i;
    mp[media-a[i]].pop_back();
  }
  FOR(i,0,n){
    cout << ans[i]+1 << " ";
  }
  cout << ENDL;


  return 0;
}