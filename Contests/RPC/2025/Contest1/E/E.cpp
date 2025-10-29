#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int cc,cm,cy,ck;
  cin >> cc >> cm >> cy >> ck;
  int vc,vm,vy,vk;
  cin >> vc >> vm >> vy >> vk;
  int h,w;
  cin >> h >> w;
  ll ans = 0;
  int negros = 0;
  FOR(i,0,h){
    string s;
    cin >> s;
    for(auto c:s){
      if(c == 'W') continue;
      if(c == 'R'){
        ans += cm+cy;
        vm--,vy--;
      }else if(c == 'G'){
        ans+=cc+cy;
        vc--,vy--;
      }else if(c == 'B'){
        ans+=cc+cm;
        vc--,vm--;
      }else if(c == 'C'){
        ans+=cc;
        vc--;
      }else if(c == 'M'){
        ans+=cm;
        vm--;
      }else if(c == 'Y'){
        ans+=cy;
        vy--;
      }else{
        negros++;
      }
    }
  }

  if(ck <= cc+cm+cy){
    ans+= min(negros,vk) * ck;
    negros-=vk;
    if(negros>0){
      ans+= (cc+cm+cy) * negros;
    }
  }else{
    int mn = min({vc,vm,vy});
    ans += min(mn,negros) * (cc+cm+cy);
    negros-=mn;
    if(negros>0){
      ans+= ck * negros;
    } 
  }
  cout << ans << '\n';
  
  return 0;
}