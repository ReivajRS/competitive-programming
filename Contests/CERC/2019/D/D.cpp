#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

signed main() {

  int n,m,k;
  cin >> n >> m >> k;
  int mnx =1e9,mxx = 0,mny = 1e9,mxy = 0;
  FOR(i,0,k){
    int y,x;
    cin >> y >> x;
    mnx = min(mnx,x);
    mxx = max(mxx,x);
    mny = min(mny,y);
    mxy = max(mxy,y);
  }
  int l = mnx-1,t = mny-1, r = m-mxx,b = n-mxy;
  int sor = l^t^r^b;
  if(sor == 0){
    cout << "pass" << endl;
    string s;
    int x;
    cin >> s;
    if(s[0] == 'y') return 0;
    cin >> x;
    if(s[0] == 'l') l-=x;
    if(s[0] == 'r') r-=x;
    if(s[0] == 't') t-=x;
    if(s[0] == 'b') b-=x;
  }

  sor = l^t^r^b;
  while(true){
    if(l - (sor^l) > 0){
      int x = l-(sor^l);
      cout << "left " << x << endl;
      l-=x;
    }else if(r - (sor^r) > 0){
      int x = r-(sor^r);
      cout << "right " << x << endl;
      r-=x;
    }else if(t - (sor^t) > 0){
      int x = t-(sor^t);
      cout << "top " << x << endl;
      t-=x;
    }else if(b - (sor^b) > 0){
      int x = b-(sor^b);
      cout << "bottom " << x << endl;
      b-=x;
    }

    string s;
    int x;
    cin >> s;
    if(s[0] == 'y') return 0;
    cin >> x;
    if(s[0] == 'l') l-=x;
    if(s[0] == 'r') r-=x;
    if(s[0] == 't') t-=x;
    if(s[0] == 'b') b-=x;
    sor = l^t^r^b;
  }

  return 0;
}