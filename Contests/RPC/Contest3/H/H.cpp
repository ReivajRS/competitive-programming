#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0);

signed main() { __

  int n;
  cin >> n;
  vi a(n);
  FOR(i,0,n){
    cin >> a[i];
  }
  sort(ALL(a));
  vi ans;
/*  */
  auto check = [&]()->bool {
    FOR(i,1,n-1){
      if(abs(ans[i-1] - ans[i]) > abs(ans[i]-ans[i+1])) return false;
    }
    return true;
  };
  if(n % 2 != 0){
    ans.pb(a[n/2]);
    int r = (n/2)+1;
    int l = (n/2)-1;
    while(true){
      if(l>= 0){
        ans.pb(a[l]);
        l--;
      }
      if(r<n){
        ans.pb(a[r]);
        r++;
      }
      
      if(l<0 && r>=n) break;
    }
    if(check()){
      for(auto x:ans){
        cout << x << " ";
      }
      return 0;
    }

    ans.clear();

    ans.pb(a[n/2]);
    r = (n/2)+1;
    l = (n/2)-1;
    while(true){
      if(r<n){
        ans.pb(a[r]);
        r++;
      }
      if(l>= 0){
        ans.pb(a[l]);
        l--;
      }
      
      if(l<0 && r>=n) break;
    }
    if(check()){
      for(auto x:ans){
        cout << x << " ";
      }
      return 0;
    }
  }else{
    int r = (n/2)+1;
    int l = (n/2);
    while(true){
      if(l>= 0){
        ans.pb(a[l]);
        l--;
      }
      if(r<n){
        ans.pb(a[r]);
        r++;
      }
      
      if(l<0 && r>=n) break;
    }
    if(check()){
      for(auto x:ans){
        cout << x << " ";
      }
      return 0;
    }

    ans.clear();

    r = (n/2);
    l = (n/2)-1;
    while(true){
      if(l>= 0){
        ans.pb(a[l]);
        l--;
      }
      if(r<n){
        ans.pb(a[r]);
        r++;
      }
      if(l<0 && r>=n) break;
    }
    if(check()){
      for(auto x:ans){
        cout << x << " ";
      }
      return 0;
    }
  }

  cout << "impossible" << ENDL;
  
  return 0;
}