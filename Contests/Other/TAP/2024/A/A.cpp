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
constexpr int maxn = 100000 + 5;
int pot3[9];
int encode(vi a) {
  int msk = 0;
  FOR(i,0,9)FOR(j,0,a[i])msk+=pot3[i];
  return msk;
}
vi decode(int msk) {
  vi a(9);
  ROF(i,9,0)while(msk-pot3[i]>=0)a[i]++,msk-=pot3[i];
  return a;
}
int winner(vi a) {
  if(a[0]&&a[0]==a[1]&&a[1]==a[2])return a[0];
  if(a[3]&&a[3]==a[4]&&a[4]==a[5])return a[3];
  if(a[6]&&a[6]==a[7]&&a[7]==a[8])return a[6];
  if(a[0]&&a[0]==a[3]&&a[3]==a[6])return a[0];
  if(a[1]&&a[1]==a[4]&&a[4]==a[7])return a[1];
  if(a[2]&&a[2]==a[5]&&a[5]==a[8])return a[2];
  if(a[0]&&a[0]==a[4]&&a[4]==a[8])return a[0];
  if(a[2]&&a[2]==a[4]&&a[4]==a[6])return a[2];
  return 0;
}
int memo[maxn][2];
vi need[9];
int f(vi a, int i){
  for(auto& j:need[i])if(!a[j])return 0;
  return 1;
}
int dp(int msk, int turn) {
  vi a = decode(msk);
  int w = winner(a);
  if(w)return w - 1;
  int &ans = memo[msk][turn];
  if(~ans)return ans;
  FOR(i,0,9)if(!a[i]&&f(a,i)){
    a[i]=turn+1;
    w=dp(encode(a),!turn);
    a[i]=0;
    if(w==turn)return ans=turn;
    if(w==2||ans==-1)ans=w;
  }
  if(ans==-1)ans=2;
  return ans;
}
int check[9][9];
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  pot3[0] = 1;
  FOR(i,1,9)pot3[i]=pot3[i-1]*3;
  int n;
  cin >> n;
  FOR (i, 0, n) {
    int x, y;
    cin >> x >> y;
    --x,--y;
    if(check[x][y])continue;
    check[x][y]=1;
    need[y].pb(x);
  }
  memset(memo,-1,sizeof memo);
  int ans=dp(0,0);
  if(ans==0){
    cout<<"X"<<ENDL;
    return 0;
  }
  if(ans==1){
    cout<<"O"<<ENDL;
    return 0;
  }
  cout<<"E"<<ENDL;
  return 0;
}