#include <bits/stdc++.h>
#include </home/javier/Escritorio/CompetitiveProgramming/AOC/AOC2024/utility.h>
using namespace std;

vector<string> input;
vector<bool> state;
unordered_map<int, vector<int>> mp;
unordered_map<int, unordered_set<int>> mp2;

void bubblesort(vector<int> &a) {
  int n = (int)a.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (mp2[a[j]].count(a[i])) {
        swap(a[i], a[j]);
      }
    }
  }
}

int check(string &s) {
  vector<string> v = split(s, ",");
  unordered_set<int> st;
  for (int i = 0; i < (int)v.size(); i++) {
    int x = stoi(v[i]);
    for (int y : mp[x]) {
      if (st.count(y)) {
        return 0;
      }
    }
    st.insert(x);
  }
  return stoi(v[(int)v.size() / 2]);
}

int check2(string &s) {
  vector<string> v = split(s, ",");
  vector<int> a((int)v.size());
  for (int i = 0; i < (int)v.size(); i++) {
    a[i] = stoi(v[i]);
  }
  bubblesort(a);
  return a[(int)a.size() / 2];
}

void read_input() {
  string s;
  while (getline(cin, s)) {
    if (s.length() == 0) break;
    vector<string> v = split(s, "|");
    int x = stoi(v[0]);
    int y = stoi(v[1]);
    mp[x].push_back(y);
    mp2[x].insert(y);
  }
  while (cin >> s) {
    input.push_back(s);
  }
  state.assign((int)input.size(), false);
}

int part1() {
  int ans = 0;
  
  for (int i = 0; i < (int)input.size(); i++) {
    int middle = check(input[i]);
    ans += middle;
    if (middle != 0) {
      state[i] = true;
    }
  }

  return ans;
}

int part2() {
  int ans = 0;

  for (int i = 0; i < (int)input.size(); i++) {
    if (state[i]) {
      continue;
    }
    ans += check2(input[i]);
  }
  
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  read_input();
  cout << "Part 1: " << part1() << '\n';
  cout << "Part 2: " << part2() << '\n';

  return 0;
}