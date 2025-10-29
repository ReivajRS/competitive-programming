#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,m,k;
  cin >> n >> m >> k;
  vector<pair<int,int>> a(n);
  FOR(i,0,n){
    cin >> a[i].first;
    a[i].second = i;
  }
  if(k%m or k==0){
    cout << "impossible" << '\n';
    return 0;
  }
  sort(a.begin(),a.end());
  // x x x x - l / x / x - r x
  k/=m;
  int l = n-k-1,r = n-k+1;
  vector<int> ans;
  ans.push_back(a[n-k].second);
  int goods = 1;
  FOR(i,1,n){
    if(l>=0 && goods * m>a[l].first * i){
      ans.push_back(a[l].second);
      l--;
    }else if(r<n && goods*m <= a[r].first * i){
      ans.push_back(a[r].second);
      goods++;
      r++;
    }else{
      cout << "impossible" << '\n';
      return 0;
    }
  }
  for(auto x:ans){
    cout << x+1 << " ";
  }
  cout << '\n';
  
  return 0;
}