#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,a;
  cin >> n >> a;
  int b = n-a;
  int ans = b*3;
  vi cnt(n,0);
  FOR(i,0,n){
    int x;
    cin >> x;
    if(x){
      cnt[i]++;
      cnt[(i+1)%n]++;
      cnt[(i-1+n)%n]++;
    }
  }
  sort(cnt.rbegin(),cnt.rend());
  FOR(i,0,a) ans+=cnt[i];
  cout << ans << ENDL;

  return 0;
}