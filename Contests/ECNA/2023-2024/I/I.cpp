#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'
// 2^l0 * k0
// k0 * 3 + 1
// 2²

dp(i, j) = min(dist[i][k] + dp(k + 1, j - 1));

// EEEOEEOEE

void solve(){
  string s;
    cin >> s;
    int n = SZ(s);
    if(s[0] == '-' || s[n-1] == '-'){
      cout << "invalid" << ENDL;
      return;
    }
    int cnt = 0,cnt2 = 0;
    FOR(i,0,n){
      cnt += (s[i]=='-');
      cnt2 += (s[i]>='0' && s[i]<='9');
      if(s[i] == 'X'){
        cnt2++;
        if(i != n-1){
          cout << "invalid" << ENDL;
          return;
        }
      }
      if(i>0 && s[i]=='-' && s[i-1] == '-'){
        cout << "invalid" << ENDL;
        return;
      }
    }
    if(cnt2 != 10){
      cout << "invalid" << ENDL;
      return;
    }
    if(cnt>3 || (cnt==3 && s[n-2] != '-')){
      cout << "invalid" << ENDL;
      return;
    }
    cnt = 10;
    int suma = 0;
    FOR(i,0,n){
      if(s[i] == '-') continue;
      if(s[i] == 'X'){
        suma += 10;
        continue;
      }
      suma+= cnt*(s[i]-'0');
      cnt--; 
    }
    int S = suma%11;
    if(S!=0){
      cout << "invalid" << ENDL;
      return;
    }
    string ans = "978-";
    cnt = 0;
    suma = 38;
    FOR(i,0,n-1){
      ans+=s[i];
      if(s[i] == '-') continue;
      suma+= ((cnt%2 ? 1 : 3)*(s[i]-'0'));
      cnt++;
    }
    S = suma%10;
    if(S) ans+=(10-S)+'0';
    else ans += (S+'0');
    cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while(t--){
    solve();
  }
  

  return 0;
}