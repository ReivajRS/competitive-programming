#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

string get_until_end(stringstream& ss) {
  string ret = "";
  char c;
  while (ss.good() && ss >> c) {
    if (c == ',' || c == ')') {
      return ret;
    }
    ret += c;
  }
  return ret;
} 

tuple<char, string, string, string> parse_for_line(string line) {
  stringstream ss(line);
  string st_aux;
  char c_aux, letter;
  ss >> st_aux >> letter >> st_aux >> c_aux >> c_aux >> c_aux >> c_aux >> c_aux >> c_aux;
  string a = get_until_end(ss), b = get_until_end(ss), c = get_until_end(ss);
  if (c == ":") {
    c = "1";
  }
  return {letter, a, b, c};
}

using i64 = long long;

int get_literal(string s, int i) {
  if (s[0] >= 'a' && s[0] <= 'z') {
    return i;
  }
  return stoi(s);
}

i64 gauss(int n) {
  return (i64)n * (n + 1) / 2;
}

i64 solve(int a, int b, int c) {
  if ((c < 0 && a <= b) || (c > 0 && a >= b)) {
    return 0;
  }
  int k = (abs(a - b) + abs(c) - 1) / abs(c);
  return (i64)k * a + gauss(k - 1) * c;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string line;
  getline(cin, line);

  getline(cin, line);
  auto [l1, a1, b1, c1] = parse_for_line(line);

  getline(cin, line);
  auto [l2, a2, b2, c2] = parse_for_line(line);

  i64 ans = 0;
  int i_a = stoi(a1), i_b = stoi(b1), i_c = stoi(c1);
  bool increasing_i = i_c > 0;
  for (int i = i_a; increasing_i ? i < i_b : i > i_b; i += i_c) {
    int j_a = get_literal(a2, i), j_b = get_literal(b2, i), j_c = get_literal(c2, i);
    ans += solve(j_a, j_b, j_c);
  }
  cout << ans << '\n';

  return 0;
}