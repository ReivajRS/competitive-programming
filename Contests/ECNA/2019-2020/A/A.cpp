#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a-1; i >= b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

struct Point{
  double x,y;
};

double dist(Point a,Point b){
  return hypot(a.x-b.x,a.y-b.y);
}

signed main() { __
  
  int n,m,p;
  cin >> n >> m >> p;
  vector<Point> jueces(n);
  vector<Point> repos(m);
  vector<Point> plumas(p);
  FOR(i,0,n){
    cin >> jueces[i].x >> jueces[i].y;
  }

  FOR(i,0,m){
    cin >> repos[i].x >> repos[i].y;
  }

  FOR(i,0,p){
    cin >> plumas[i].x >> plumas[i].y;
  }

  double ans = 0;

  vector<tuple<double,int,int>> distancias;
  FOR(i,0,n){
    FOR(j,0,m){
      distancias.pb({dist(jueces[i],repos[j]),i,j});
    }
  }
  
  sort(ALL(distancias));
  vi visJ(n,0);
  vi visR(m,0);
  for(auto [d,i,j]:distancias){
    if(visJ[i] || visR[j]) continue;
    ans+=d;
    visJ[i] = visR[j] = true;
  }

  distancias.clear();;
  FOR(i,0,n){
    FOR(j,0,p){
      distancias.pb({dist(jueces[i],plumas[j]),i,j});
    }
  }
  
  sort(ALL(distancias));
  visJ.assign(n,0);
  visR.assign(p,0);
  for(auto [d,i,j]:distancias){
    if(visJ[i] || visR[j]) continue;
    ans+=d;
    visJ[i] = visR[j] = true;
  }

  
  cout << setprecision(9) << fixed;
  cout << ans << ENDL;

  return 0;
}