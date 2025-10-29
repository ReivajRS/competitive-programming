#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ask(int a,int b,int c){
  cout << "? " << a << " " << b << " " << c << endl;
  int x;
  cin >> x;
  return x;
}

void solve(){
  int n;
  cin >> n;
  int a = 1,b = 2,c=3;
  while(true){
    int x = ask(a,b,c);
    if(!x){
      cout << "! " << a << " " << b << " " << c << endl;
      return;
    }
    int opc = uniform_int_distribution<int>(1,3)(rng);
    if(opc == 1){
      a = x;
    }else if(opc == 2){
      b = x;
    }else{
      c = x;
    }

  }
}

signed main() {

  int t;
  cin >> t;
  while(t--) solve();

  return 0;
}