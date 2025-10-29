#include <bits/stdc++.h>
using namespace std;

int n = 0;
vector<vector<int>> input;

void read_input() {
  string s;
  while (getline(cin, s)) {
    n++;
    input.push_back(vector<int>());
    stringstream ss(s);
    string w;
    while (ss >> w) {
      input.back().push_back(stoi(w));
    }
  }
}

bool check_safety(vector<int> &v) {
  bool flag = 1;
  for (int i = 0; i < (int)v.size() - 1; i++) {
    int dif = abs(v[i] - v[i + 1]);
    if (dif < 1 || dif > 3) {
      flag = 0;
      break;
    }
  }
  if (!flag) return false;
  vector<int> vr = v;
  reverse(vr.begin(), vr.end());
  return is_sorted(v.begin(), v.end()) || is_sorted(vr.begin(), vr.end());
}

bool check_removing_one(vector<int> &v) {
  for (int i = 0; i < (int)v.size(); i++) {
    vector<int> vc;
    for (int j = 0; j < (int)v.size(); j++) {
      if (i == j) continue;
      vc.push_back(v[j]);
    }
    if (check_safety(vc)) return true;
  }
  return false;
}

int part1() {
  int ans = 0;
  for (vector<int> &v : input) {
    ans += check_safety(v);  
  }
  return ans;
}

int part2() {
  int ans = 0;
  for (vector<int> &v : input) {
    ans += check_safety(v) || check_removing_one(v);
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