#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  long long y,k,x=1;
  cin >> y >> k;
  while(k){
    if(gcd(x,y) == y) break;
    x += gcd(x,y);
    k--;
  }
  cout << x + y*k << '\n';

  return 0;
}