#include <bits/stdc++.h>
using namespace std;

using ll =  long long;
using vi = vector<int>;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vi a(n),cnt(1e5+5,0);
  map<int,vi> pos;
  map<int,int> ans;
  FOR(i,0,n){
    cin >> a[i];
    pos[a[i]].push_back(i);
    cnt[a[i]]++;
  }

  for(auto &[x,b]: pos){
    ans[x] = n-cnt[x]+1;
    for(auto i:b){
      int mn = min({a[(i-2+n)%n],a[(i-1+n)%n],a[i]});
      int mx = max({a[(i-2+n)%n],a[(i-1+n)%n],a[i]});
      if(x == mn or x == mx){
        ans[x]--;
        break;
      }

      mn = min({a[(i-1+n)%n],a[i],a[(i+1)%n]});
      mx = max({a[(i-1+n)%n],a[i],a[(i+1)%n]});
      if(x == mn or x == mx){
        ans[x]--;
        break;
      }

      mn = min({a[i],a[(i+1)%n],a[(i+2)%n]});
      mx = max({a[i],a[(i+1)%n],a[(i+2)%n]});
      if(x == mn or x == mx){
        ans[x]--;
        break;
      }
    }
  }

  FOR(i,0,n){
    cout << ans[a[i]] << " ";
  }
  cout << ENDL;

  return 0;
}