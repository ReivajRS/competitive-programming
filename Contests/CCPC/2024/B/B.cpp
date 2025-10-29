#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

vector<int> mp(255);

void solve(){
  int n;
  cin >> n;
  vector<int> cnt(4,0);
  FOR(i,0,n){
    string s;
    cin >> s;
    cnt[mp[s[1]]]++;
  }
  int ans = 0;
  int restantes = 0;
  FOR(i,0,4){
    ans+=cnt[i]/5;
    restantes+=cnt[i]%5;
    cnt[i]%=5;
  }

  vector<int> t(6);
  FOR(i,0,6) cin >> t[i];
  int wc = t[4]+t[5];
  priority_queue<int> sobras;
  int res = 0;
  FOR(i,0,4){
    int curr = cnt[i]+3*t[i];
    res+=curr/5;
    sobras.push(curr%5);
  }
  while(SZ(sobras) && wc){
    int x = sobras.top();
    sobras.pop();
    if(x+wc >= 5){
      res++;
      wc -= 5-x;
    }
  }
  ans+= min(res,restantes/5);
  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  
  mp['D'] = 0;
  mp['C'] = 1;
  mp['H'] = 2;
  mp['S'] = 3;

  int t;
  cin >> t;
  while(t--) solve();

  return 0;
}