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

vi PI(string s){
  vi p(SZ(s));
  FOR(i,1,SZ(s)){
    int g = p[i-1];
    while(g &&s[i] != s[g]) g = p[g-1];
    p[i] = g+(s[i] == s[g]);
  }
  return p;
}

int KMP(const string& s,const string& pat){
  vi phi = PI(pat+'\0'+s),res;
  int cnt = 0;
  FOR(i,SZ(phi)-SZ(s),SZ(phi))
  if(phi[i] == SZ(pat)) cnt++;
  return cnt;
}

void solve(){
  string a,s,t;
  cin >> a >> s >> t;
  if(SZ(s)<SZ(t)) swap(s,t);
  queue<string> q;
  q.push(s);

  auto can = [&](string curr) -> bool {
    curr = curr + curr.substr(0,SZ(s)-1);
    return (KMP(curr,s) <= KMP(curr,t));
  };

  FOR(i,0,1000){
    string curr = q.front();
    q.pop();
    if(can(curr)){
      for(char c:a) q.push(curr+c);
    }else{
      cout << 0 << ENDL;
      return;
    }
  }
  cout << 1 << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while(t--) solve();

  return 0;
}