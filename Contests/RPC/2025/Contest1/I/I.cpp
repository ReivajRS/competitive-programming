#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using iii = tuple<ll,ll,ll>;
#define SZ(x) ((ll)x.size())
#define FOR(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)

#define ENDL '\n'

struct STree {
  #define ls (k<<1)+1
  #define rs (k<<1)+2
  #define lp ls,s,m
  #define rp rs,m,e

  ll n;
  vector<ll> st;

  STree(ll n): n(n),st((n<<2)+5) {}

  ll merge(ll x,ll y){
    return x+y;
  }
  void pull(ll k){
    st[k] = merge(st[ls],st[rs]);
  }
  ll query(ll k,ll s,ll e,ll a,ll b){
    if(a<=s && e<=b) return st[k];
    ll m = (s+e)>>1;
    if(a>=m) return query(rp,a,b);
    if(b<=m) return query(lp,a,b);
    return merge(query(lp,a,b),query(rp,a,b));
  }

  void upd(ll k,ll s,ll e,ll i,ll v){
    if(s+1 == e){
      st[k] += v;
      return;
    }
    ll m = (s+e) >> 1;
    if(i<m) upd(lp,i,v);
    else upd(rp,i,v);
    pull(k);
  }

  ll query(ll a,ll b){
    return query(0,0,n,a,b);
  }
  void upd(ll i,ll v){
    upd(0,0,n,i,v);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n;
  cin >> n;
  vector<tuple<string,string,ll,ll>> input(n);
  vector<ll> nums;
  FOR(i,0,n){
    string a,b;
    ll c,d;
    cin >> a >> b >> c >> d;
    input[i] = {a,b,c,d};
    nums.push_back(c);
  }

  sort(nums.begin(), nums.end());
  nums.erase(unique(nums.begin(), nums.end()), nums.end());
  auto get = [&](ll x) -> ll {
    return ll(lower_bound(nums.begin(), nums.end(), x) - nums.begin());
  };

  ll m = SZ(nums)+5;
  STree stbuys(m);
  STree stsells(m);
  priority_queue<iii,vector<iii>,greater<iii>> sells;
  priority_queue<iii> buys;

  vector<iii> ans;

  FOR(i,0,n){
    auto &[s,t,p,a] = input[i];
    p = get(p);
    if(t[0] == 'n'){
      //llenta comprar todo el sell menor a el
      if(s[0] == 'b'){
        while(a>0 && SZ(sells)){
          auto [priceSell,idxSell,amountSell] = sells.top();
         
          sells.pop();
          stsells.upd(priceSell,-amountSell);
          if(priceSell>p) {
            sells.push({priceSell,idxSell,amountSell});
           
            stsells.upd(priceSell,amountSell);
            break;
          }

          if(amountSell>=a){
            ans.push_back({idxSell+1,i+1,a});
            amountSell -= a;
            a = 0;
            if(amountSell>0){
              sells.push({priceSell,idxSell,amountSell});
             
              stsells.upd(priceSell,amountSell);
            }
            break;
          }

            ans.push_back({idxSell+1,i+1,amountSell});
            a-=amountSell;
        }

        //falto sell
        if(a>0){
          buys.push({p,-i,a});
          stbuys.upd(p,a);
        }
      }else{
        while(a>0 && SZ(buys)){
          auto [priceBuy,idxBuy,amountBuy] = buys.top();
          buys.pop();
          stbuys.upd(priceBuy,-amountBuy);
          if(priceBuy<p) {
            buys.push({priceBuy,idxBuy,amountBuy});
            stbuys.upd(priceBuy,amountBuy);
            break;
          }

          if(amountBuy>=a){
            ans.push_back({i+1,(-idxBuy)+1,a});
            amountBuy -= a;
            a = 0;
            if(amountBuy>0){
            
              buys.push({priceBuy,idxBuy,amountBuy});
              stbuys.upd(priceBuy,amountBuy);
            }
            break;
          }

            ans.push_back({i+1,(-idxBuy)+1,amountBuy});
            a-=amountBuy;
        }

        //falto buy
        if(a>0){
          sells.push({p,i,a});

          stsells.upd(p,a);
        }
      }
      continue;
    }

    // ahora con fok
    if(s[0] == 'b'){
      //checar si hay suficientes sell menores o igual a buys
      ll cnt = stsells.query(0,p+1);
      if(cnt<a) continue; // se cancela;
      // se hace la machaca

      while(a){
        auto [priceSell,idxSell,amountSell] = sells.top();
          sells.pop();
          stsells.upd(priceSell,-amountSell);

          if(amountSell>=a){
            ans.push_back({idxSell+1,i+1,a});
            amountSell -= a;
            a = 0;
            if(amountSell>0){
              sells.push({priceSell,idxSell,amountSell});
              stsells.upd(priceSell,amountSell);
            }
            break;
          }

            ans.push_back({idxSell+1,i+1,amountSell});
            a-=amountSell;
      }

    }else{
      //checar si hay suficiente buys mayores a sells
      ll cnt = stbuys.query(p,m);
      if(cnt<a) continue; // se cancela;
      // se hace la machaca

      while(a){
        auto [priceBuy,idxBuy,amountBuy] = buys.top();
          buys.pop();
          stbuys.upd(priceBuy,-amountBuy);

          if(amountBuy>=a){
            ans.push_back({i+1,(-idxBuy)+1,a});
            amountBuy -= a;
            a = 0;
            if(amountBuy>0){
              buys.push({priceBuy,idxBuy,amountBuy});
              stbuys.upd(priceBuy,amountBuy);
            }
            break;
          }

            ans.push_back({i+1,(-idxBuy)+1,amountBuy});
            a-=amountBuy;
      }
    }

  }

  cout << SZ(ans) << '\n';
  for(auto [x,y,z]:ans){
    cout << x << " " << y << " " << z << '\n';
  }

  return 0;
}