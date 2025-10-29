#include <bits/stdc++.h>
using namespace std;

using ll = long long;


signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;
  vector<char> nxt = {'T','A','P'};
  int curr = 0;
  for(char c:s){
    if(nxt[curr] == c){
      curr++;
      if(curr == 3){
        cout << 'S' << '\n';
        return 0;
      }
    }
  }
  cout << 'N' << '\n';
        return 0;
}