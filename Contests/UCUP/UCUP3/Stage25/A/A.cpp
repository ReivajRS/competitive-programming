#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

struct DSU {
  vector<int> e;
  void init(int n) {e = vector<int>(n,-1);}
  int size(int x) {return -e[get(x)];}
  int get(int x){return e[x]<0?x:e[x]=get(e[x]);}
  bool join(int a,int b){
    a = get(a),b =get(b);
    if(a==b) return false;
    if(e[a]>e[b]) swap(a,b);
    e[a]+=e[b];
    e[b] = a;
    return true;
  }
};

void solve(){
  string s1,s2,s3;
  cin >> s1 >> s2 >> s3;
  int n1 = SZ(s1),n2=SZ(s2),n3=SZ(s3);
  if(n1 == n2 && n1 != n3){
    cout << "YES" << ENDL;
    return;
  }
  if(n1!=n2){
    cout << "NO" << ENDL;
    return;
  }

  DSU dsu;
  dsu.init(30);

  FOR(i,0,n1){
    int c1 = s1[i]-'a';
    int c2 = s2[i]-'a';
    dsu.join(c1,c2);
  }

  FOR(i,0,n1){
    int c1 = s1[i]-'a';
    int c3 = s3[i]-'a';
    int a = dsu.get(c1),b = dsu.get(c3);
    if(a != b){
      cout << "YES" << ENDL;
      return;
    }
  }
  cout << "NO" << ENDL;

}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while(t--) solve();
  
  return 0;
}