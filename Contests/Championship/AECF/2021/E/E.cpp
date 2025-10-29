#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

map<char,int> mp;


void solve(){
  int n,m;
  cin >> n >> m;
  vi a(n),b(m);
  FOR(i,0,n){
    char c,_;
    cin >> c >> _;
    a[i] = mp[c];
  }
  FOR(i,0,m){
    char c,_;
    cin >> c >> _;
    b[i] = mp[c];
  }
  char c,_;
  cin >> c >> _;
  int p = mp[c];
  sort(ALL(a));
  sort(ALL(b));
  if(n == 1){
    cout << "Shou" << ENDL;
    return;
  }

   // checar
  if(a[0] >= p){
    cout << "Shou" << ENDL;
    return;
  }

  if(m == 1){
    FOR(i,0,n){
      if(a[i] >= b[0] && a[i]<p){
        cout << "Pang" << ENDL;
        return;
      }
    }
    cout << "Shou" << ENDL;
    return;
  }


  int cnt =0;
  FOR(i,0,m){
    if(b[i]<p)cnt++;
  }
  if(cnt>=2){
    cout << "Pang" << ENDL;
    return;
  }

 


  

  // A 5 3 
  // 1 K
  // 7
  bool c1 = false;
  if(a[n-1] > b[m-1]) c1 = true;
  FOR(i,1,n-1){
    if(a[i]>=b[0] && a[i]<p && n>3 && c1){
      cout << "Pang" << ENDL;
      return;
    }
  }
  cout << "Shou" << ENDL;


}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  FOR(i,2,10){
    mp[i+'0'] = i;
  }
  mp['T'] = 10;
  mp['J'] = 11;
  mp['Q'] = 12;
  mp['K']  =13;
  mp['A'] = 14;

  int t;
  cin >> t;
  while(t--) solve();
  

  return 0;
}