#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a-1; i >= (int)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

constexpr int MOD = 1e9+7;

int k,n;
vi h;
string s1,s2;
vector<vi> dp;

int solve(int i, int day){
  if(i == k) return 1;
  if(day>=n) return 0;

  int &ans = dp[i][day];
  if(ans != -1) return ans;

  ans = solve(i,day+1) % MOD;
  if(s1[i] == s2[day]){
    ans += solve(i+1,day+h[s1[i]-'A']+1);
    ans %= MOD;
  }
  ans %= MOD;
  return ans%MOD;
}

signed main() { __

  cin >> k >> n;
  h.resize(26);
  FOR(i,0,26){
    cin >> h[i];
  }
  dp.assign(k,vi(n,-1));
  cin >> s1 >> s2;

  cout << solve(0,0)%MOD << ENDL;
  
  return 0;
}