#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

map<string, int> mp_id;
map<int, string> mp_name;
vector<vector<int>> g;

void map_id(string& s) {
  if (!mp_id.count(s)) {
    mp_id[s] = SZ(mp_id);
    mp_name[mp_id[s]] = s;
    g.push_back({});
  }
}

string dfs_encode(int u) {
  cout << mp_name[u] << '\n';
  string s = "0";
  for (auto v : g[u]) {
    s += dfs_encode(v);
  }
  s += "1";
  return s;
}

void encode() {
  string s;
  cin.ignore();
  while (getline(cin, s)) {
    stringstream ss(s);
    string w;
    ss >> w;
    w = w.substr(0, SZ(w) - 1);
    map_id(w);
    int boss_id = mp_id[w];
    while (ss >> w) {
      map_id(w);
      int person_id = mp_id[w];
      g[boss_id].push_back(person_id);
    }
  }
  string code = dfs_encode(0);
  cout << code << '\n';
}

void decode() {
  string s;
  string code;
  while (cin >> s) {
    if (isdigit(s[0])) {
      code = s;
      break;
    }
    map_id(s);
  }

  int nxt = 1;
  stack<int> st;
  st.push(0);
  for (int i = 1; i < SZ(code); i++) {
    if (code[i] == '0') {
      g[st.top()].push_back(nxt);
      st.push(nxt);
      nxt++;
    }
    else {
      st.pop();
    }
  }
  for (int i = 0; i < SZ(g); i++) {
    if (g[i].empty()) {
      continue;
    }
    cout << mp_name[i] << ":";
    for (auto x : g[i]) {
      cout << ' ' << mp_name[x];
    }
    cout << '\n';
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;

  if (s == "ENCODE") {
    encode();
  }
  else {
    decode();
  }

  return 0;
}