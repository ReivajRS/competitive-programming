#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.rbegin(), x.rend()
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __

  int n;
  cin >> n;
  vector<string> nombres(n);
  vector<pi> pts;
  FOR(i,0,n){
    cin >> nombres[i];
    int p;
    cin >> p;
    int puntos = p*10;
    int mn = 100;
    int mx = 0;
    FOR(i,0,6){
      int x;
      cin >> x;
      puntos+=x;
      mn = min(mn,x);
      mx = max(mx,x);
    }
    puntos-=mn;
    puntos-=mx;
    pts.pb({puntos,-i});
  }
  sort(ALL(pts));
  FOR(i,0,n){
    pts[i].second*=-1;
  }
  cout << nombres[pts[0].second] << " " << pts[0].first << ENDL;
  int ant = pts[0].first;
  int cnt2 = 1;
  FOR(i,1,min(1000,n)){
    if(pts[i].first != ant){
      if(cnt2>=3) break;  
    }
    ant = pts[i].first;
    cnt2++;
    cout << nombres[pts[i].second] << " " << pts[i].first << ENDL;
    
  }

  return 0;
}