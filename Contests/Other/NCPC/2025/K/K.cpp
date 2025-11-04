#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int N;
  cin >> N;

  int mx = 0, x = 0;
  while (N--) {
    string s;
    cin >> s;

    if (s == "/") {
      x = mx + 1;
      while (x % 10) {
        ++x;
      }
    } else {
      x = stoi(s);
      mx = max(mx, x);  
    }
    cout << x << '\n';
  }
}
