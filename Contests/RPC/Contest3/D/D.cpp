#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define ROF(i, a, b) for (ll i = (ll)a-1; i >= (ll)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0);

typedef long long T;

ll sgn(T x) { return (T(0) < x) - (x < T(0)); }

struct Poll {
  T x, y;
  Poll operator+(Poll p) const { return {x + p.x, y + p.y}; }
  Poll operator-(Poll p) const { return {x - p.x, y - p.y}; }
  Poll operator*(T d) const { return {x * d, y * d}; }
  T sq() { return x * x + y * y; }
  Poll perp() { return {-y, x}; }
  Poll operator/(T d) const { return {x / d, y / d}; }
};

ll circleCircle(Poll o1, ll r1, Poll o2, ll r2, pair<Poll, Poll> &out) {
  Poll d = o2 - o1;
  ll d2 = d.sq();
  if (d2 == 0) {
    assert(r1 != r2);
    return 0;
  }
  ll pd = (d2 + r1- r2) / 2;
  ll h2 = r1 - pd * pd / d2;
  if (h2 >= 0) {
    Poll p = o1 + d * pd / d2, h = d.perp() * sqrt(h2 / d2);
    out = {p - h, p + h};
  }
  return 1 + sgn(h2);
}

ll dx[8]={1, 1, 0, -1, -1, -1, 0, 1};
ll dy[8]={0, 1, 1, 1, 0, -1, -1, -1};

signed main() { __
  ll n;
  cin >> n;
  ll cambio = 50, cambioy = 50;
  ll cnt = 0;

  while(n){
    cout << cambio << " " << cambioy << endl;
    cnt++;
    assert(cnt<=1000);
    ll d1;
    cin >> d1;
    if(d1 == 0){
      n--;
      cambio = 0;
      cambioy = 0;
      continue;
    }
    bool encontro = false;
    FOR(k,0,8){
      cout << cambio+dx[k] << " " << cambioy+dy[k] << endl;
      cnt++;
    assert(cnt<=1000);
      ll d2;
      cin >> d2;
      if(d2 == 0){
        encontro = true;
        break;
      }

      pair<Poll,Poll> ans;
      ll ller = circleCircle(Poll{cambio,cambioy},d1,Poll{cambio+dx[k],cambioy+dy[k]},d2,ans);
      if(ller >=1 and !(ans.first.x < 0 || ans.first.y < 0)){
        cout << ans.first.x<< " "<< ans.first.y << endl;
        cnt++;
    assert(cnt<=1000);
        ll aux;
        cin >> aux;
        if(aux == 0){
          encontro = true;
          break;
        }
      }
      if(ller>=2 and !(ans.second.x < 0 || ans.second.y < 0)){
        cout << ans.second.x << " "<< ans.second.y << endl;
        cnt++;
    assert(cnt<=1000);
        ll aux;
        cin >> aux;
        if(aux == 0){
          encontro = true;
          break;
        }
      }

    }
    if(!encontro){
      cambio+=10;
      cambioy+=5;
    }
      
      else{
        cambio = 0;
        cambioy = 0;
        n--;
      }
  }
  return 0;
}