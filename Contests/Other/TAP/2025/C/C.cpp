#include <bits/stdc++.h>
using namespace std;

using ll = long long;


signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<ll> cnt(n,0);
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    cnt[(x+i)%n]++;
  }
  ll ans = 0;
  for(auto x:cnt) ans += ll(x)*x;
  cout << ans << '\n';

}