#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int p, int& t, vector<vector<pair<int, int>>>& g, vector<int>& time_in, vector<int>& parent, vector<bool>& back_edge_to_1) {
  time_in[u] = t++;
  parent[u] = p;
  for (auto [v, _] : g[u]) {
    if (v == p) {
      continue;
    }
    if (v == 1 && time_in[v] != -1 && time_in[v] < time_in[u]) {
      back_edge_to_1[u] = true;
    }
    if (time_in[v] == -1) {
      dfs(v, u, t, g, time_in, parent, back_edge_to_1);
    }
  }
}

vector<pair<int, int>> bfs(int s, int t, vector<vector<pair<int, int>>>& g, vector<bool>& open) {
  int n = (int)g.size();
  vector<pair<int, int>> path(n, {-1, -1});
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u == t) {
      return path;
    }
    for (auto [v, i] : g[u]) {
      if (path[v].first != -1 || !open[i]) {
        continue;
      }
      path[v] = {u, i};
      q.push(v);
    }
  }
  return {};
}

void add_moves(vector<int>& nodes, vector<string>& steps) {
  for (auto x : nodes) {
    steps.push_back("MOVE " + to_string(x));
  }
}

string get_keys(vector<int>& keys) {
  string s = "";
  for (auto x : keys) {
    s += (to_string(x) + " ");
  }
  return s;
}

void print_ans(int m, vector<string>& steps, vector<int>& alice_keys) {
  vector<int> bob_keys;
  vector<bool> used_keys(m, false);
  for (auto x : alice_keys) {
    used_keys[x] = true;
  }
  for (int i = 0; i < m; i++) {
    if (!used_keys[i]) {
      bob_keys.push_back(i);
    }
  }

  cout << get_keys(alice_keys) << '\n';
  cout << get_keys(bob_keys) << '\n';

  for (auto x : steps) {
    cout << x << '\n';
  }
}

bool both_in_cycle(int n, int m, vector<vector<pair<int, int>>>& g) {
  vector<int> nodes, keys;
  vector<string> steps;
  vector<int> alice_keys;
  vector<bool> open(m, true);
  vector<pair<int, int>> path = bfs(0, 1, g, open);
  if (path.empty()) {
    return false;
  }
  int now = 1;
  while (now != 0) {
    nodes.push_back(now);
    keys.push_back(path[now].second);
    open[path[now].second] = false;
    now = path[now].first;
  }
  reverse(nodes.begin(), nodes.end());
  reverse(keys.begin(), keys.end());
  alice_keys = keys;
  add_moves(nodes, steps);
  steps.push_back("DONE");

  path = bfs(1, 0, g, open);
  if (path.empty()) {
    return false;
  }
  nodes.clear();
  now = 0;
  while (now != 1) {
    nodes.push_back(now);
    now = path[now].first;
  }
  reverse(nodes.begin(), nodes.end());
  add_moves(nodes, steps);
  steps.push_back("DONE");

  print_ans(m, steps, alice_keys);

  return true;
}

bool other_subtree(int n, int m, int Z, vector<vector<pair<int, int>>>& g) {
  vector<int> nodes, keys;
  vector<string> steps;
  vector<int> alice_keys;
  vector<bool> open(m, true);
  vector<pair<int, int>> path = bfs(0, Z, g, open);
  if (path.empty()) {
    return false;
  }
  int now = Z;
  while (now != 0) {
    nodes.push_back(now);
    if (path[now].first != 1) {
      keys.push_back(path[now].second);
      open[path[now].second] = false;
    }
    now = path[now].first;
  }
  reverse(nodes.begin(), nodes.end());
  reverse(keys.begin(), keys.end());
  alice_keys = keys;
  add_moves(nodes, steps);
  steps.push_back("DROP " + get_keys(keys));
  for (auto [v, i] : g[Z]) {
    if (v == 1) {
      open[i] = false;
      alice_keys.push_back(i);
      break;
    }
  }
  steps.push_back("MOVE 1");
  steps.push_back("DONE");

  path = bfs(1, Z, g, open);
  if (path.empty()) {
    return false;
  }
  nodes.clear();
  now = Z;
  while (now != 1) {
    nodes.push_back(now);
    now = path[now].first;
  }
  reverse(nodes.begin(), nodes.end());
  add_moves(nodes, steps);
  steps.push_back("GRAB");

  open.assign(m, true);
  open[alice_keys.back()] = false;

  path = bfs(Z, 0, g, open);
  if (path.empty()) {
    return false;
  }
  nodes.clear();
  now = 0;
  while (now != Z) {
    nodes.push_back(now);
    now = path[now].first;
  }
  reverse(nodes.begin(), nodes.end());
  add_moves(nodes, steps);
  steps.push_back("DONE");

  print_ans(m, steps, alice_keys);

  return true;
}

bool same_subtree(int n, int m, int Z, vector<vector<pair<int, int>>>& g) {
  vector<int> nodes, keys;
  vector<string> steps;
  vector<int> alice_keys;
  vector<bool> open(m, true);
  vector<pair<int, int>> path = bfs(0, Z, g, open);
  if (path.empty()) {
    return false;
  }
  int now = Z;
  while (now != 0) {
    nodes.push_back(now);
    keys.push_back(path[now].second);
    open[path[now].second] = false;
    now = path[now].first;
  }
  reverse(nodes.begin(), nodes.end());
  reverse(keys.begin(), keys.end());
  alice_keys = keys;
  add_moves(nodes, steps);
  steps.push_back("DROP " + get_keys(keys));
  path = bfs(Z, 1, g, open);
  if (path.empty()) {
    return false;
  }
  nodes.clear();
  keys.clear();
  now = 1;
  while (now != Z) {
    nodes.push_back(now);
    keys.push_back(path[now].second);
    open[path[now].second] = false;
    now = path[now].first;
  }
  reverse(nodes.begin(), nodes.end());
  reverse(keys.begin(), keys.end());
  for (auto x : keys) {
    alice_keys.push_back(x);
  }
  add_moves(nodes, steps);
  steps.push_back("DONE");

  path = bfs(1, Z, g, open);
  if (path.empty()) {
    return false;
  }
  nodes.clear();
  now = Z;
  while (now != 1) {
    nodes.push_back(now);
    now = path[now].first;
  }
  reverse(nodes.begin(), nodes.end());
  add_moves(nodes, steps);
  steps.push_back("GRAB");

  open.assign(m, true);
  open[alice_keys.back()] = false;

  path = bfs(Z, 0, g, open);
  if (path.empty()) {
    return false;
  }
  nodes.clear();
  now = 0;
  while (now != Z) {
    nodes.push_back(now);
    now = path[now].first;
  }
  reverse(nodes.begin(), nodes.end());
  add_moves(nodes, steps);
  steps.push_back("DONE");

  print_ans(m, steps, alice_keys);

  return true;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }

  int t = 0;
  vector<int> time_in(n, -1), parent(n, -1);
  vector<bool> back_edge_to_1(n, false);
  dfs(1, -1, t, g, time_in, parent, back_edge_to_1);

  int X = -1;
  for (int i = 0; i < n; i++) {
    if (back_edge_to_1[i]) {
      X = i;
      break;
    }
  }
  
  if (X == -1) {
    cout << "No solution" << '\n';
    return 0;
  }

  vector<bool> in_cycle(n, false);
  int now = X;
  while (now != -1) {
    in_cycle[now] = true;
    now = parent[now];
  }

  int Y = -1;
  now = 0;
  while (now != 1) {
    if (in_cycle[now]) {
      Y = now;
      break;
    }
    now = parent[now];
  }

  if (both_in_cycle(n, m, g)) {
    return 0;
  }
  if (other_subtree(n, m, X, g)) {
    return 0;
  }
  same_subtree(n, m, Y, g);

  return 0;
}