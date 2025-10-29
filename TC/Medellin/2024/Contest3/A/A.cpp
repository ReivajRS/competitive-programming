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
    
    ll insert(string word) {
      ll ans = 0;
      TrieNode *curr = root;
      for (char c : word) {
        if (curr->children.find(c) == curr->children.end()) {
          curr->children[c] = new TrieNode();
        }
        curr = curr->children[c];
        ans += curr->numPrefix;
        curr->numPrefix++;
      }
      return ans;
    }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n;
  cin >> n;
  
  ll ans = 0;
  Trie t;

  FOR (i, 0, n) {
    string s;
    cin >> s;
    ans += t.insert(s);
  }
  cout << ans << ENDL;

  return 0;
}