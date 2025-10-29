#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= b; i--)
#define ENDL '\n'


struct TrieNode {
  TrieNode* children[2];
  bool isEndOfWord;
  int numPrefix;

  TrieNode() : isEndOfWord(false), numPrefix(0) {
    children[0] = NULL;
    children[1] = NULL;
  }
};

class Trie {
  private:
    TrieNode *root;

    TrieNode* merge2(TrieNode *t1,TrieNode *t2){
      if(t1 == NULL) return t2;
      if(t2 == NULL) return t1;

/*
      if(t1->children.count(0) || t2->children.count(0)){
        bool nohubo = false;
        if(!t1->children.count(0)){
          t1->children[0] = t2->children[0];
          nohubo = true;
        }
        if(t2->children.count(0)){
          nohubo = true;
        }
        if(!nohubo) {
          t1->children[0] = merge2(t1->children[0],t2->children[0]);
        }
      }

      if(t1->children.count(1) || t2->children.count(1)){
        bool nohubo = false;
        if(!t1->children.count(1)){
          t1->children[1] = t2->children[1];
          nohubo = true;
        }
        if(t2->children.count(1)){
          nohubo = true;
        }
        if(!nohubo) {
          t1->children[1] = merge2(t1->children[1],t2->children[1]);
        }
      }
      */
      
      TrieNode* hijo0 = merge2(t1->children[0],t2->children[0]);
      if(hijo0 != NULL) t1->children[0] = hijo0;
      TrieNode* hijo1 = merge2(t1->children[1],t2->children[1]);
      if(hijo1 != NULL) t1->children[1] = hijo1;
      
      return t1;
    }
  public:
    Trie() {
      root = new TrieNode();
    }
    
    void insert(int x) {
      TrieNode *curr = root;
      ROF(i,31,0) {
        bool c = (1 << i) & x;
        if (curr->children[c] == NULL) {
          curr->children[c] = new TrieNode();
        }
        curr = curr->children[c];
        curr->numPrefix++;
      }
    }

    void merge(Trie t2){
      merge2(this->root,t2.root);
    }
    // 1100
    // N
    // M² = N² + N*K
    int ans(int x){
      int res = 0;
      TrieNode *curr = root;
      ROF(i,31,0){
        bool c = (1 << i) & x;
        if(c == 0){
          if(curr->children[1] != NULL) curr = curr->children[1], res |= (1<<i);
          else curr = curr->children[0];
        }else{
          if(curr->children[0] != NULL) curr = curr->children[0], res |= (1<<i);
          else curr = curr->children[1];
        }
      }
      return res;
    }

};

/*
  1 3
  2 6
  3 9
  4 5
  5 15
  6 22
  7 21
  8 10
  9 16
  10 30
*/

constexpr int maxn = 2e5 + 5;

ll a[maxn];
vi g[maxn];
vector<pair<int, int>> query[maxn];
int ans[maxn];

Trie dfs(int u, int p) {
  Trie t;
  for (auto &v : g[u]) {
    if (v == p) {
      continue;
    }
    Trie t2 = dfs(v, u);
    t.merge(t2);
  }

  t.insert(a[u]);

  for (auto &[x, i] : query[u]) {
    ans[i] = t.ans(x);
  }
  return t;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  FOR (i, 0, n) {
    cin >> a[i];
  }
  FOR (i, 1, n) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  int q;
  cin >> q;
  FOR (i, 0, q) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    query[v].pb({a[u], i});
  }

  dfs(0, -1);
  
  FOR (i, 0, q) {
    cout << ans[i] << ENDL;
  }

  return 0;
}