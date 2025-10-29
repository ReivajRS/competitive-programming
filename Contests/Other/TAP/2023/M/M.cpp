#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)b - 1; i >= (int)a; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

ld EPS = 1e-6;

signed main() { __

  int n;
  ld t;
  cin >> n >> t;
  vector<ld> prio,nprio;
  FOR(i,0,n){
    char c;
    ld x;
    cin >> c >> x;
    if(c == 'P') prio.pb(x);
    else nprio.pb(x);
  }
  int hechosP = 0,hechosNP = 0;
  ld ans = 0;
  while(hechosP < SZ(prio) || hechosNP < SZ(nprio)){
    ld mn = 3e8,mbC = -1,mbNC = -1;
    if(hechosP < SZ(prio)){
      ld totalP = 0;
      FOR(i,0,SZ(prio)){
        if(prio[i] > EPS){
          totalP += prio[i];
        }
      }
      ld mbP;
      if(hechosNP < SZ(nprio)){
        mbP = t*0.75;
      }else{
        mbP = t;
      }

      mbC = mbP / (SZ(prio) -hechosP);
      FOR(i,0,SZ(prio)){
        if(prio[i] < EPS) continue;
        ld tiempo = prio[i] / mbC;
        mn = min(mn,tiempo);
      }
    }
    

    if(hechosNP < SZ(nprio)){
      ld totalP = 0;
      FOR(i,0,SZ(nprio)){
        if(nprio[i] > EPS){
          totalP += nprio[i];
        }
      }
      ld mbP;
      if(hechosP < SZ(prio)){
        mbP = t*0.25;
      }else{
        mbP = t;
      }

      mbNC = mbP/ (SZ(nprio) -hechosNP);
      FOR(i,0,SZ(nprio)){
        if(nprio[i] < EPS) continue;
        ld tiempo = nprio[i] / mbNC;
        mn = min(mn,tiempo);
      }
    }
    if(hechosP < SZ(prio)){
      FOR(i,0,SZ(prio)){

        if(prio[i] < EPS) continue;
      prio[i] -= mn*mbC;
      if(prio[i] < EPS){
        hechosP++;
      }
      }
      
    }

    if(hechosNP < SZ(nprio)){
      FOR(i,0,SZ(nprio)){

        if(nprio[i] < EPS) continue;
      nprio[i] -= mn*mbNC;
      if(nprio[i] < EPS){
        hechosNP++;
      }
      }
    }

    ans += mn;
  }
  cout << setprecision(8) << fixed;
  cout << ans << ENDL;
  
  return 0;
}