#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

constexpr short alpha = 10;
constexpr char offset = '0';
constexpr int MOD = 998244353;
struct state{
  int l,link,cnt;
  array<int,alpha> go;
  state(){
    l = cnt = 0;
    go.fill(0);
  }
};
struct eertree{
  int n = 2;
  int last = 1;
  vector<state> et;
  string s;
  eertree(){
    et.resize(2);
    et[0].link = et[1].link =1;
    et[1].l = -1;
  }
  int palSuff(int x){
    while(s[SZ(s)-2-et[x].l] != s.back()) x = et[x].link;
    return x;
  }
  int add(char ch,bool b){
    s.pb(ch);
    last = palSuff(last);
    bool new_pal = !et[last].go[ch-offset];
    if(new_pal){
      et.pb(state());
      et[last].go[ch-offset] = n++;
      et.back().link = et[palSuff(et[last].link)].go[ch-offset];
      et.back().l = et[last].l+2;
      if(et.back().l == 1) et.back().link = 0;
    }
    last = et[last].go[ch-offset];
    if(b)
      et[last].cnt++;
    if(et[last].l == SZ(s)) last = et[last].link;
    return new_pal; 
  }
  void computeFrecuency(){
    ROF(i,n,2){
      et[et[i].link].cnt += et[i].cnt;
    }
  }
/*
1 1 2 3 4
1 3 2 1 4
1 1 2 3 4
1 2 3 4 5
*/
  int solve(int len){
    ll ans = 0;
    FOR(i,2,n) if (et[i].l <= len) {
      (ans+=1ll*et[i].cnt * et[i].cnt%MOD * et[i].l % MOD)%=MOD;
    }
    return ans;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  string s;
  cin >> s;
  eertree pt, pt2;
  FOR(i,0,n){
    pt.add(s[i],0);
  }
  FOR(i,0,n){
    pt.add(s[i],1);
  }
  pt.computeFrecuency();
  cout << pt.solve(SZ(s)) << ENDL;

  return 0;
}