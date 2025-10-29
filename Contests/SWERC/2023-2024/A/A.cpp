#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

constexpr int MAX = 1e5+5;
int L[MAX],L_id[MAX];
vi a;
int n;

int solve_LIS(){
  int lis_sz = 0,lis_end =0;
  FOR(i,0,n){
    L[i] = L_id[i] = 0;
  }
  FOR(i,0,n){
    int pos = lower_bound(L,L+lis_sz,a[i])-L;
    L[pos] = a[i];

    if(pos == lis_sz){
      lis_sz = pos+1;
      lis_end = i;
    }
  }
  return lis_sz;
}

signed main() { __
  cin >> n;
  a = vi(n);
  vector<string> input(n);
  FOR(i,0,n){
    string s;
    cin >> input[i];
  }
  int ans = 3e8;
  string perm="ERSW";
  // 2 1 3 4
  // 2 3 1 4
  do{
    FOR(i,0,n){
      string s = input[i];
      int v = stoi(s.substr(1));
      if(s[0] == perm[0]){
        a[i] = v;
      }else if(s[0] == perm[1]){
        a[i] = n+v;
      }else if(s[0] == perm[2]){
        a[i] = n*2+v;
      }else if(s[0] == perm[3]){
        a[i] = n*3+v;
      }else if(s[0] == 'C'){
        a[i] = n*4+v;
      }
    }
    ans = min(ans,n-solve_LIS());
  }while(next_permutation(ALL(perm)));
  cout << ans << ENDL;
  return 0;
}