#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  int n;
  while(cin >> n && n){
    vector<pair<int,int>> a(n);
    FOR(i,0,n){
      cin >> a[i].first >> a[i].second;
    }
    
    auto can = [&](double gap) -> bool {
      vector<int> order(n);
      iota(order.begin(),order.end(),0);
      do{
        double curr = -99999;
        bool ok = true;
        FOR(i,0,n){
          if(curr+gap > a[order[i]].second){
            ok = false;
            break;
          }
          curr = max(curr+gap,1.0*a[order[i]].first);
        }
        if(ok) return true;
      }while(next_permutation(order.begin(),order.end()));
      return false;
    };
    
    double l=0,r = 1445;
    FOR(_,0,200){
      double mid = (l+r)/2.0;
      if(can(mid)) l = mid;
      else r = mid; 
    }
    int minute = (int)l;
    int second = round((l - double(minute)) * 60.0);
    if(second == 60.0){
      minute++;
      second = 0;
    }
    cout << "Case " << t++ << ": " << minute<<":" << (second < 10 ? "0" : "") <<second << '\n';
  }

  return 0;
}