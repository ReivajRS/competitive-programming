#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

void encode() {

}

int to_int(string s) {
  reverse(s.begin(), s.end());
}

void decode() {
  vector<string> names;
  string code;
  string s;
  while (cin >> s) {
    if (isdigit(s[0])) {
      code = s;
      break;
    }
    names.push_back(s);
  }
  int n = SZ(names);
  int lg = ceil(log2(n));

  for (int i = 0; i < SZ(code); i += lg) {
    string p_code = code.substr(i, lg);

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