#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

constexpr int maxn = 300001;
int a[maxn];
vector<int> p_facts[maxn];
unordered_set<int> g[maxn];
map<int, int> divi[maxn];
bitset<maxn> is_prime;
vector<int> primes;

void sieve() {
  is_prime.set();
  is_prime[0] = is_prime[1] = 0;
  for (int i = 2; i < maxn; i++) {
    if (!is_prime[i]) {
      continue;
    }
    for (int j = i; j < maxn; j += i) {
      is_prime[j] = 0;
    }
    primes.push_back(i);
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  sieve();
  
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (!p_facts[a[i]].empty()) {
      continue;
    }
    int x = a[i];
    for (auto p : primes) {
      if (p > x) {
        break;
      }
      if (x % p != 0) {
        continue;
      }
      while (x % p == 0) {
        x /= p;
      }
      p_facts[a[i]].push_back(p);
    }
    for (int j = 0; j < SZ(p_facts[a[i]]); j++) {
      for (int k = j + 1; k < SZ(p_facts[a[i]]); k++) {
        int x = p_facts[a[i]][j];
        int y = p_facts[a[i]][k];
        g[x].insert(y);
        g[y].insert(x);
        divi[x][y] = divi[y][x] = i;
      }
    }
  }

  int s, t;
  cin >> s >> t;

  if (s == t) {
    cout << 1 << '\n';
    cout << s << '\n';
    return 0;
  }

  vector<int> dist(maxn, -1);
  vector<int> path(maxn, -1);
  queue<int> q;
  for (auto x : p_facts[a[s - 1]]) {
    q.push(x);
    dist[x] = 1;
  }

  int last = -1;

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (a[t - 1] % u == 0) {
      last = u;
      break;
    }
    for (auto v : g[u]) {
      if (dist[v] != -1) {
        continue;
      }
      dist[v] = dist[u] + 1;
      path[v] = u;
      q.push(v);
    }
  }

  if (last == -1) {
    cout << -1 << '\n';
    return 0;
  }

  vector<int> p_path;
  while (last != -1) {
    p_path.push_back(last);
    last = path[last];
  }
  reverse(p_path.begin(), p_path.end());

  cout << dist[p_path.back()] + 1 << '\n';

  cout << s << ' ';
  for (int i = 0; i < SZ(p_path) - 1; i++) {
    cout << divi[p_path[i]][p_path[i + 1]] + 1 << ' ';
  }
  cout << t << '\n';
}