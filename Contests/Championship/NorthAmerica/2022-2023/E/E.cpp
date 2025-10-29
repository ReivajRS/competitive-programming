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

vector<vi> cnt(3,vi(3,0));
map<vector<vi>,int> dp[3];

int can(int x,vector<vi> cnt2){
  if(dp[x].count(cnt2)) return dp[x][cnt2];
  int &ans = dp[x][cnt2];
  ans = 0;
  FOR(y,0,3){
    if(!cnt2[x][y]) continue;
    cnt2[x][y]--;
    if(!can(y,cnt2)) {
      return ans = 1;
    }
    cnt2[x][y]++; 
  }
  return false;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  map<char,int> mapa;
    string s;
    vector<pi> a(n);
  FOR(i,0,n){
    cin >> s;
    if(!mapa.count(s[0])) mapa[s[0]] = SZ(mapa);
    if(!mapa.count(s.back())) mapa[s.back()] = SZ(mapa);
    cnt[mapa[s[0]]][mapa[s.back()]]++;
    a[i] = {mapa[s[0]],mapa[s.back()]};
  }
  FOR(i,0,3){
    cnt[i][i] %=2;
  }
  FOR(i,0,3){
    FOR(j,0,3){
      int mn = max(min(cnt[i][j],cnt[j][i]) - 1,0);
      cnt[i][j] -= mn;
      cnt[j][i] -= mn;
    }// ab ba ab ba
  }
  int ans = 0;
  for(auto [x,y]:a){
    if(!cnt[x][y]) continue;
    cnt[x][y]--;
    ans += !can(y,cnt);
    cnt[x][y]++;
  }
  cout << ans << ENDL;

  return 0;
}