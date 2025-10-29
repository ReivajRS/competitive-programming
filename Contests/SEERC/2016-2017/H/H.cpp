#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

typedef ll T;
struct Point
{
  T x,y,id;

  Point operator+(Point p) const { return {x+p.x,y+p.y};}
  Point operator-(Point p) const { return {x-p.x,y-p.y};}

  bool operator==(Point p) const { return tie(x,y) == tie(p.x,p.y);}
  bool operator<(Point p) const { return tie(x,y)<tie(p.x,p.y);}

  T cross(Point p) const { return x*p.y-y*p.x;}
  T cross(Point a,Point b) const { return (a-*this).cross(b-*this);}
};

vi vis;
vector<Point> pts;
int n;
int m = 0;

vector<Point> convexHull(){
  if(n-m <=1) return {};
  vector<Point> h(SZ(pts)+1);
  int s=0,t=0;
  for(int it=2;it--;s=--t, reverse(ALL(pts))){
    FOR(i,0,n){
      if(vis[pts[i].id]) continue;
      Point p = pts[i];
      while(t>=s+2 && h[t-2].cross(h[t-1],p) <= 0) t--;
      h[t++] = p;
    }
  }
  return {h.begin(),h.begin()+t - (t==2 && h[0] == h[1])};
}


signed main() {

  
  cin >> n;
  pts.resize(n);
  vis.assign(n+5,0);
  FOR(i,0,n){
    ll x,y;
    cin >> x >> y;
    pts[i].x = x;
    pts[i].y = y;
    pts[i].id = i;
  }
  if(n<=2){
    cout << n << ENDL;
    FOR(i,0,n){
      cout << i+1 << " ";
    }
    return 0;
  }
  sort(ALL(pts));
  cout << n << ENDL;
  
  bool primero = true;
  Point ultimo;
  while(m<n){
    vector<Point> ch = convexHull();
    if(primero){
      FOR(i,0,SZ(ch)){
        vis[ch[i].id] = 1;
        cout << ch[i].id+1 << " ";
      }
      ultimo = ch[SZ(ch)-1];
      primero = false;
      m+=SZ(ch);
      continue;
    }
    if(SZ(ch) == 0){
      FOR(i,0,n){
        if(!vis[pts[i].id]){
          cout << pts[i].id+1 << ENDL;
          return 0;
        }
      }
    }

    FOR(i,0,SZ(ch)){
      if(ch[i].cross(ultimo,ch[i+1])<0){
        FOR(j,0,SZ(ch)){
          vis[ch[(i+j)%SZ(ch)].id] = true;
          cout << ch[(i+j)%SZ(ch)].id+1 << " ";
        } 
        ultimo = ch[(i+SZ(ch)-1)%SZ(ch)];
        m+=SZ(ch);
        break;
      } 
    }
  }
  
   
  return 0;
}