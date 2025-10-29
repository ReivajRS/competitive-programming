#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)



signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<ll> fib(75);
  fib[0] = fib[1] = 1;
  FOR(i,2,75){
    fib[i] = fib[i-1] + fib[i-2];
  }

  reverse(fib.begin(),fib.end());
  fib.pop_back();
  fib.pop_back();

  ll n;
  cin >> n;

  vector<ll> ans;
  auto solve = [&](auto self,ll n,int i) -> void {
    if(i >= SZ(fib)) return;
    if(n == 1){
      for(auto x:ans){
        FOR(j,0,x){
          cout << "A";
        }
        cout << "B";
      }
      exit(0);
    }
    if(n>=fib[i] && n%fib[i] == 0){
      ans.push_back(73-i);
      self(self,n/fib[i],i);
      ans.pop_back();
    }
    self(self,n,i+1);
  };

  solve(solve,n,0);
  cout << "IMPOSSIBLE\n";

  return 0;
}