#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using ld = long double;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

struct Line {
  mutable ld k,m,p;
  bool operator<(const Line& o) const { return k<o.k;}
  bool operator<(ld x) const {return p<x;}
};

struct LineContainer:multiset<Line,less<>> {
  ld inf = 1/.0;
  ld div(ld a,ld b){
    return a/b;
  }
  bool isect(iterator x,iterator y){
    if(y == end()) return x->p = inf,0;
    if(x->k == y->k)
      x->p = x->m > y->m ? inf : -inf;
    else
      x->p = div(y->m - x->m,x->k - y->k);
    return x->p >= y->p;
  }
  void add(ld k,ld m){
    auto z = insert({k,m,0}),y = z++,x = y;
    while(isect(y,z)) z = erase(z);
    if(x != begin() && isect(--x,y)) isect(x,y = erase(y));
    while((y =x) != begin() && (--x)->p >= y->p)
      isect(x,erase(y));
  }
  ld query(ld x){
    assert(!empty());
    auto l = *lower_bound(x);
    return l.k * x + l.m;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<ld> prob(n+1);
  FOR(i,1,n+1){
    cin >> prob[i];
  }
  prob[0] = 1.0;
  LineContainer cht;
  vector<ld> dp(n+1);
  FOR(i,0,n+1){
    dp[i] = i*prob[i];
  }
  ld mx = *max_element(dp.begin(),dp.end());
  cht.add(1-prob[n],dp[n]);
  for(int i=n-1;i>=0;i--){
    ld x = cht.query(i);
    dp[i] = max(dp[i],x*prob[i]);
    cht.add(1-prob[i],dp[i]);
  }
  cout << setprecision(15) << fixed;
  cout << max(dp[0],mx) << ENDL;

  return 0;
}