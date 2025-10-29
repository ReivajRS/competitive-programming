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
#define ROF(i, a, b) for (int i = (int)b - 1; i >= (int)a; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

int solve(int x,int y){
  int opc1 = 0,opc2 = 0;
  int x2 = x,y2 = y;
  opc1 = min(x2/2,y2);
  x2 -= opc1 * 2;
  y2-= opc1;
  if(x2>=1 && y2>=3){
    opc1++;
    y2-=3;
    x2--;
  }
  opc1 += (x2/5 + y2/5);

  opc2 = min(y/3,x);
  x-=opc2;y-=opc2*3;
  
  int aux = min(x/2,y);
  opc2+=aux;
  y-=aux,x-=(aux*2);
  opc2 += (x/5 + y/5);

  return max(opc1,opc2);
}

signed main() { __

  vi cnt(5,0);
  int n;
  cin >> n;
  FOR(i,0,n){
    int x;
    cin >> x;
    cnt[x%5]++;
  }

  int ans = cnt[0];

    int mn = min(cnt[4],cnt[1]);
    ans += mn;
    cnt[4] -= mn;
    cnt[1] -= mn;

    mn = min(cnt[3],cnt[2]);
    ans += mn;
    cnt[3] -= mn;
    cnt[2] -= mn;
  

  if(cnt[1] && cnt[3]){
    ans+=solve(cnt[1],cnt[3]);

  }
  else if(cnt[2] && cnt[1]){

    ans+=solve(cnt[2],cnt[1]);

  }
  else if(cnt[3] && cnt[4]){

    ans+=solve(cnt[3],cnt[4]);

  }
  else if(cnt[4] && cnt[2]){

    ans+=solve(cnt[4],cnt[2]);

  }else{
    ans += cnt[1]/5 + cnt[2]/5 + cnt[3]/5 + cnt[4]/5;
  }

  cout << ans << ENDL;
  
  return 0;
}