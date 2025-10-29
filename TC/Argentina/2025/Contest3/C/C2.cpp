#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

struct Node{
  map<char,Node*> nxt;
  list<int> a,b;
};

struct Trie{
  Node* root;
  Trie(){
    root = new Node();
  }

  void insert(string &s,int id,int flag){
    Node* curr = root;
    for(auto c:s){
      if(!curr->nxt.count(c)){
        curr->nxt[c] = new Node();
      }
      curr = curr->nxt[c];
    }
    if(flag) curr->b.push_back(id);
    else curr->a.push_back(id);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  Trie trie = Trie();
  int n;
  cin >> n;
  FOR(i,0,n){
    string s;
    cin >> s;
    trie.insert(s,i,0);
  }
  FOR(i,0,n){
    string s;
    cin >> s;
    trie.insert(s,i,1);
  }

  vector<pair<int,int>> ans;
  ll res = 0;
  auto dfs = [&](auto self,Node* u,int d = 0) -> void {
    FOR(i,'a','z'+1){
      if(u->nxt.count(i)) {
        self(self,u->nxt[i],d+1);
        u->a.splice(u->a.end(),u->nxt[i]->a);
        u->b.splice(u->b.end(),u->nxt[i]->b);
      }
    }
    int cnt = min(SZ(u->a),SZ(u->b));
    while(cnt--){
      ans.push_back({u->a.back(),u->b.back()});
      u->a.pop_back();
      u->b.pop_back();
      res +=d;
    }
  };
  dfs(dfs,trie.root);
  cout << res << '\n';
  for(auto [x,y]:ans){
    cout << x+1 << " " << y+1 << '\n';
  }


  return 0;
}