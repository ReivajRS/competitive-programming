#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

void solve(){
  int n,k;
  cin >> n >> k;
  string s;
  vi l(k),r(k);
  cin >> s;
  FOR(i,0,k) cin >>l[i],l[i]--;
  FOR(i,0,k) cin >> r[i],r[i]--;
  int q;
  cin >> q;
  vi cnt(n+5,0);
  while(q--){
    int x;
    cin >> x;
    x--;
    cnt[x]++;
  }

  FOR(i,0,k){
    int L= l[i],R=r[i];
    int mid = (L+R)/2;
    int suma = 0;
    FOR(i,L,mid+1){
      suma += cnt[i]+cnt[R-i+L];
      if(suma&1) swap(s[i],s[R-i+L]);
    }
  }
  cout << s << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  
  int t;
  cin >> t;
  while(t--) solve();

  return 0;


}