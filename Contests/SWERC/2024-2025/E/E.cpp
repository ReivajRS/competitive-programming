#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

#define x first
#define y second

signed main() {
  cin.tie(0)->sync_with_stdio(0);


  int n;
  int mx = 0;
  cin >> n;
  vector<pair<int,int>> pts(n);
  FOR(i,0,n){
    cin >> pts[i].x >> pts[i].y;
    mx = max(pts[i].x,mx);
  } 
  sort(pts.begin(),pts.end(),[&](pair<int,int> a,pair<int,int> b){
    if(a.x == mx && b.x == mx) return a.y>b.y;
    return a<b;
  });
  vector<pair<int,int>> ans;
  ans.push_back({pts[0].x,1});
  ans.push_back(pts[0]);
  FOR(i,1,n){
    if(pts[i].x == pts[i-1].x){
      ans.push_back(pts[i]);
      continue;
    }
    if(pts[i-1].x+1 != mx)
      ans.push_back({pts[i-1].x+1,2});
    if(pts[i].x == mx) ans.push_back({pts[i].x,1});
    else ans.push_back({pts[i].x,2});
    ans.push_back(pts[i]);
  }
  if(mx != 1)
    ans.push_back({mx - 1, 2});
  else{
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << SZ(ans)+1 << "\n";
    for(auto [x,y]:ans){
      cout << x << " " << y << '\n';
    }
    cout << "2 1\n"; 
    return 0;
  }
  sort(ans.begin(),ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  sort(ans.begin(),ans.end(),[&](pair<int,int> a,pair<int,int> b){    
    if(a.y == 1 && b.y == 1) return a.x>b.x;
    if(a.y == 1 || b.y == 1) return a.y>b.y;
    if(a.x == mx && b.x == mx) return a.y>b.y;
    return a<b;
  });

  cout << SZ(ans) << '\n';
  for(auto [x,y]:ans){
    cout << x << " " << y << '\n';
  }

  return 0;
}