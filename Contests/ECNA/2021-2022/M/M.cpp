#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a - 1; i>= (int)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

int cnt = 0;

struct TrieNode{
  unordered_map<char,TrieNode *> children;
  bool isEndOfWord;
  int idx;
  TrieNode():isEndOfWord(false){
    idx = cnt++;
  }
};

class Trie{
  public:
  TrieNode *root;
  Trie(){
    root = new TrieNode();
  }

  void insert(string word){
    TrieNode *curr = root;
    for(char c:word){
      if(curr->children.find(c) == curr->children.end()){
        curr->children[c] = new TrieNode();
      }
      curr = curr->children[c];
    }
    curr->isEndOfWord = true;
  }
};

constexpr int INF = 1e6;

constexpr int dx[3] = {0,1,0}, dy[3] = {-1,0,1};

int n,m;
bool isValid(int x,int y){
  return (x>=0 && x<n && y>=0 && y<m);
}

signed main() { __

  int k;
  cin >> n >> m >> k;
  vector<vector<char>> grid(n,vector<char>(m));
  FOR(i,0,n){
    FOR(j,0,m){
      cin >> grid[i][j];
    }
  }
  Trie trie;
  while(k--){
    string s;
    cin >> s;
    trie.insert(s);
  }
  TrieNode *inicio = trie.root; 
  queue<tuple<int,int,TrieNode*,int>> q;
  vector<vector<vector<vi>>> dist(n,vector<vector<vi>>(m,vector<vi>(cnt+5,vi(3,INF))));
  FOR(i,0,m){
    if(inicio->children.count(grid[0][i])){
      q.push({0,i,inicio->children[grid[0][i]],1});
      dist[0][i][inicio->children[grid[0][i]]->idx][1] = 0;
    }
  }

  int ans = INF;

  while(SZ(q)){
    auto [x,y,curr,dir] = q.front();
    q.pop();
    if(x == n-1 && curr->isEndOfWord){
      ans = min(ans, dist[x][y][curr->idx][dir]);
    }
    FOR(k,0,3){
      if((dir == 0 && k == 2) || (dir == 2 && k==0)) continue;
      int sigX = x+dx[k],sigY = y+dy[k];
      if(!isValid(sigX,sigY)) continue;
      if(curr->isEndOfWord){
        if(trie.root->children.count(grid[sigX][sigY])){
          TrieNode* sig = trie.root->children[grid[sigX][sigY]];
          if(dist[sigX][sigY][sig->idx][k] < INF) continue;
          dist[sigX][sigY][sig->idx][k] = dist[x][y][curr->idx][dir]+1;
          q.push({sigX,sigY,sig,k});
        }
      }
        if(curr->children.count(grid[sigX][sigY])){
          TrieNode* sig = curr->children[grid[sigX][sigY]];
          if(dist[sigX][sigY][sig->idx][k] < INF) continue;
          dist[sigX][sigY][sig->idx][k] = dist[x][y][curr->idx][dir]+1;
          q.push({sigX,sigY,sig,k});
        }
    }
  }
  if(ans >= INF){
    cout << "impossible" << ENDL;
    return 0;
  }
  cout << ans+1 << ENDL;

  return 0;
}