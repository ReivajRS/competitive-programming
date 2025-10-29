#include <bits/stdc++.h>
using namespace std;

string input;
string target_st = "mul(";
string target_do = "do()", target_dont = "don't()";
vector<int> pos_mul, pos_col, pos_clp;
vector<pair<int, bool>> pos_ena;

void read_input() {
  getline(cin, input);
  int i = 0;
  while (1) {
    i = input.find(target_st, i);
    if (i == -1) break;
    pos_mul.push_back(i);
    i++;
  }
  pos_ena.push_back({0, true});
  i = 0;
  while (1) {
    i = input.find(target_do, i);
    if (i == -1) break;
    pos_ena.push_back({i, true});
    i++;
  }
  i = 0;
  while (1) {
    i = input.find(target_dont, i);
    if (i == -1) break;
    pos_ena.push_back({i, false});
    i++;
  }
  pos_ena.push_back({(int)input.size(), true});
  sort(pos_ena.begin(), pos_ena.end());
  for (auto [x, y] : pos_ena) {
    cout << x << ' ' << y << '\n';
  }
  for (int j = 0; j < (int)input.length(); j++) {
    if (input[j] == ',') pos_col.push_back(j);
    if (input[j] == ')') pos_clp.push_back(j);
  }
}

bool is_number(string &s) {
  for (char &c : s) if (!isdigit(c)) return false;
  return true;
}

int part1() {
  int ans = 0;
  
  for (int i : pos_mul) {
    int end_mul = i + 3;
    int next_col = *lower_bound(pos_col.begin(), pos_col.end(), end_mul);
    if (next_col == (int)input.length()) break;
    int next_clp = *lower_bound(pos_clp.begin(), pos_clp.end(), end_mul);
    if (next_clp == (int)input.length()) break;

    if (next_col - end_mul < 2 || next_clp - next_col < 2) continue;
    string string_n1 = input.substr(end_mul + 1, next_col - end_mul - 1);
    string string_n2 = input.substr(next_col + 1, next_clp - next_col - 1);
    
    if (!is_number(string_n1) || !is_number(string_n2)) continue;
    int n1 = stoi(string_n1);
    int n2 = stoi(string_n2);
    ans += n1 * n2;
  }

  return ans;
}

int part2() {
  int ans = 0;
  
  for (int i : pos_mul) {
    auto [next_change, enabled] = *prev(lower_bound(pos_ena.begin(), pos_ena.end(), make_pair(i, false)));
    if (i >= next_change && !enabled) continue;

    int end_mul = i + 3;
    int next_col = *lower_bound(pos_col.begin(), pos_col.end(), end_mul);
    if (next_col == (int)input.length()) break;
    int next_clp = *lower_bound(pos_clp.begin(), pos_clp.end(), end_mul);
    if (next_clp == (int)input.length()) break;

    if (next_col - end_mul < 2 || next_clp - next_col < 2) continue;
    string string_n1 = input.substr(end_mul + 1, next_col - end_mul - 1);
    string string_n2 = input.substr(next_col + 1, next_clp - next_col - 1);

    cout << string_n1 << ' ' << string_n2 << '\n';
    
    if (!is_number(string_n1) || !is_number(string_n2)) continue;
    int n1 = stoi(string_n1);
    int n2 = stoi(string_n2);
    ans += n1 * n2;
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