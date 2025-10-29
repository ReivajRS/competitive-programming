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
map<char,int> mp;
void solve(){


  vector<pair<int,char>> deck(5);
  int aux[2],aux2[3];
  int mimx = 0, mx2 = 0;
  FOR(i,0,5){
    char c;
    cin >> c;
    cin >> deck[i].second;
    deck[i].first = mp[c]; 
    if(i<2){
      aux[i] = deck[i].first;
      mimx = max(mimx,deck[i].first);
    }else{
      aux2[i-2] = deck[i].first;
      mx2 = max(mx2,deck[i].first);
    }
  }
  sort(ALL(deck));
  FOR(i,1,5){
    if(deck[i].second != deck[0].second){
      cout << "check" << ENDL;
      return;
    }
  }
  FOR(i,1,5){
    if(deck[i].first != deck[i-1].first+1){
      sort(aux,aux+2);
      sort(aux2,aux2+3);
      if(aux[0] == 5 && aux[1] == 14 && aux2[0] ==2 && aux2[1] == 3 && aux2[2] == 4){
        cout << "allin" << ENDL;
      }else{
        cout << "check" << ENDL;
      }
      return;
    }
  }
  if(mimx>mx2 || mimx>=10){
    cout << "allin" << ENDL;
    return;
  }
  cout << "check" << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  mp['A'] = 14;
  mp['K'] = 13;
  mp['Q'] = 12;
  mp['J'] = 11;
  mp['T'] = 10;
  FOR(i,1,10) mp[char('0'+i)] = i;
  int t;
  cin >> t;
  while(t--) solve();

  return 0;
}