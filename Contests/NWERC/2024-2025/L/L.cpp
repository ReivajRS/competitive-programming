#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,m,x,y;
  cin >> n >> m >> x >> y;
  vi a(n),b(m);
  FOR(i,0,n) cin >> a[i];
  FOR(i,0,m) cin >> b[i];

  sort(a.begin(),a.end());
  sort(b.begin(),b.end());

  int p2 = 0;
  vector<vi> repisa(n);
  FOR(p1,0,n){
    while(p2<m && b[p2] <= a[p1]){ 
      repisa[p1].push_back(b[p2]);
      p2++;
    }
  }
  
  if(p2 != m) {
    cout << "impossible" << '\n';
    return 0;
  }
  priority_queue<int> q;
  FOR(p1,0,n){
    while(SZ(repisa[p1]) > y){
      q.push(repisa[p1].back());
      repisa[p1].pop_back();
    }
    while(SZ(q) && SZ(repisa[p1]) < y){
      repisa[p1].push_back(q.top());
      q.pop();
    }
  }

/*
  FOR(i,0,n){
    cout << "repisa "<< i <<'\n';
    for(auto x:repisa[i]) cout << x << " ";
    cout << '\n'; 
  }
*/

  int currR = n-1;
  int ans = n;
  while(SZ(q)){
    int libro = q.top();
    q.pop();
    while(currR>=0 && SZ(repisa[currR]) == x) currR--;
    if(currR <0){
      cout << "impossible" << '\n';
      return 0;
    }
    if(SZ(repisa[currR]) == y) ans--;
    if(libro>a[currR]){
      cout << "impossible" << '\n';
      return 0;
    }
    repisa[currR].push_back(libro);
  }
  cout << ans << '\n';
  
  return 0;
}