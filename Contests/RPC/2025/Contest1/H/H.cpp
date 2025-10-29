#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int d,c;
  cin >> d >> c;
  auto can = [&](int x) -> bool {
    int avanzo = 0;
    for(int i=x;i>1;i--){
      int disp = c-avanzo;
      if(disp < 0) return 0; // no puede regresar :(
      avanzo += disp/(i+1);
    }
    return (avanzo+c>=d);
  };
  //cout << can(10);
  int l = 1,r = 1e6+5;
  while(l<r){
    int mid = (l+r)/2;
    if(can(mid)) r = mid;
    else l = mid+1;
  }
  if(l == 1e6+5){
    cout << "impossible" << '\n';
    return 0;
  }
  cout << l-1 << '\n';

  return 0;
}