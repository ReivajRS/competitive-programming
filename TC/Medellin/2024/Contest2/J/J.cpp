#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

const int MAXN = 200005;
vi inicio,termina;

struct AhoCorasick {
  enum { alpha = 26,
         first = 'a' };  // change this!
  struct Node {
    // (nmatches is optional)
    int back, next[alpha], start = -1, end = -1, nmatches = 0;
    Node(int v) { memset(next, v, sizeof(next)); }
  };
  vector<Node> N;
  vi backp;
  void insert(string& s, int j) {
    assert(!s.empty());
    int n = 0;
    for (char c : s) {
      int& m = N[n].next[c - first];
      if (m == -1) {
        n = m = SZ(N);
        N.emplace_back(-1);
      } else
        n = m;
    }
    if (N[n].end == -1) N[n].start = j;
    backp.push_back(N[n].end);
    N[n].end = j;
    N[n].nmatches++;
  }
  // O(sum|pat| * C)
  AhoCorasick(vector<string>& pat) : N(1, -1) {
    FOR(i, 0, SZ(pat))
    insert(pat[i], i);
    N[0].back = SZ(N);
    N.emplace_back(0);

    queue<int> q;
    for (q.push(0); !q.empty(); q.pop()) {
      int n = q.front(), prev = N[n].back;
      FOR(i, 0, alpha) {
        int &ed = N[n].next[i], y = N[prev].next[i];
        if (ed == -1)
          ed = y;
        else {
          N[ed].back = y;
          (N[ed].end == -1 ? N[ed].end : backp[N[ed].start]) = N[y].end;
          N[ed].nmatches += N[y].nmatches;
          q.push(ed);
        }
      }
    }
  }

  // O(|word|)
  vi find(string word) {
    int n = 0;
    vi res;  // ll count = 0;
    for (char c : word) {
      n = N[n].next[c - first];
      res.push_back(N[n].end);
      // count += N[n].nmatches;
    }
    return res;
  }
  void findAll(vector<pair<string,int>>& pat, string word) {
    vi r = find(word);
    FOR(i, 0, SZ(word)) {
      int ind = r[i];
      while (ind != -1) {
        int x = i - SZ(pat[ind].first) + 1;
        inicio[x]+=pat[ind].second;
        termina[x + SZ(pat[ind].first)]+=pat[ind].second;
        ind = backp[ind];
      }
    }
  }
};



signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string t;
  cin >> t;

  int n;
  cin >> n;

  
  map<string,int> mapa; 
  inicio.assign(SZ(t)+5,0);
  termina.assign(SZ(t)+5,0);

  FOR (i, 0, n) {
    string s;
    cin >> s;
    mapa[s]++;
  }
  vector<string> pat(SZ(mapa));
  vector<pair<string,int>> pat2(SZ(mapa));
  int cnt = 0;
  for(auto &[s,x]:mapa){
    pat2[cnt] = {s,x};
    pat[cnt++] = s;
  }
  AhoCorasick aho(pat);

  aho.findAll(pat2, t);

  ll ans = 0;

  FOR (i, 0, SZ(t) + 1) {
    // cout << inicio[i] << ' ' << termina[i] << ENDL;
    ans += 1ll * termina[i] * inicio[i];
  }

  cout << ans << ENDL;

  return 0;
}