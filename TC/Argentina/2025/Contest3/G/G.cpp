#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,m;
  cin >> n >> m;
  ll tot = 0;
  vector<int> l(m+1);
  FOR(i,0,m){
    cin >> l[i+1];
    tot+=l[i+1];
  }
  if(tot<n){
    cout << -1 << '\n';
    return 0;
  }
  FOR(i,1,m+1){
    if(i>n-l[i]+1){
      cout << -1 << '\n';
      return 0;
    }
  }
  vector<int> ans(m+1);
  vector<int> mx(m+1,0);
  FOR(i,1,m+1){
    ans[i] = i;
    mx[i]=max(mx[i-1],l[i]+i-1);
  }
  ans[m] = n-l[m]+1;
  for(int i=m-1;i>=1&&ans[i+1]>mx[i];i--){
    ans[i] = max(i,min(n-l[i]+1,ans[i+1]-l[i]));
  }
  FOR(i,1,m+1){
    cout << ans[i] << " ";
  }
  cout << '\n';

  return 0;
}