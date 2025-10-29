#include <bits/stdc++.h>
using namespace std;

using ll =  long long;
using vi = vector<int>;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  ll sum = 0,mx = 0;
  FOR(i,0,n){
    ll x;
    cin >> x;
    sum+=x;
    mx = max(mx,x);
  }
  if(mx != 0 && sum-mx < n){
    cout << "Donkey" << '\n';
  }else{
    cout << "Puss in Boots" << '\n';
  }

  return 0;
}