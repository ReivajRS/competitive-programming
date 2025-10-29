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
  unordered_map<char, TrieNode *> children;
  bool isEndOfWord;
  int numPrefix;

  TrieNode() : isEndOfWord(false), numPrefix(0) {}
};

class Trie {
  private:
    TrieNode *root;
  
  public:
    Trie() {
      root = new TrieNode();
    }
    
    void insert(string word) {
      TrieNode *curr = root;
      for (char c : word) {
        if (curr->children.find(c) == curr->children.end()) {
          curr->children[c] = new TrieNode();
        }
        curr = curr->children[c];
        curr->numPrefix++;
      }
    }

};

constexpr int maxn = 2e5 + 5;

ll a[maxn];
vi g[maxn];
vector<tuple<int, int, int>> query[maxn];
int ans[maxn];

void dfs(int u, int p) {

}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n;
  cin >> n;
  FOR (i, 0, n) {
    cin >> a[i];
  }
  

  stack<int> st;
  vi lg(n), rg(n);
  FOR (i, 0, n) {
    while (!st.empty() && a[st.top()] >= a[i]) st.pop();
    lg[i] = !st.empty() ? st.top() : -1;
    st.push(i);
  }
  while (!st.empty()) st.pop();
  ROF (i, n, 0) {
    while (!st.empty() && a[st.top()] >= a[i]) st.pop();
    rg[i] = !st.empty() ? st.top() : n;
    st.push(i);
  }

  vi ans(n, -1);
  FOR (i, 0, n) {
    int len = rg[i] - lg[i] - 2;
    ans[len] = max(ans[len], a[i]);
  }

  int mx = -1e9;
  ROF (i, n, 0) {
    mx = max(mx, ans[i]);
    ans[i] = mx;
  }

  FOR (i, 0, n) {
    cout << ans[i] << ' ';
  }
  cout << ENDL;

  return 0;
}