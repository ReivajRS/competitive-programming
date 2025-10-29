#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<int> num(n), p(n);
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    num[i]--;
    p[num[i]] = i;
  }

  int ans = 1;
  for (int i = 1; i < n; i++) {
    if (p[i] < p[i - 1]) {
      ans++;
    }
  }

  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;

    int x = num[a], y = num[b];

    if (abs(x - y) == 1) {
      if (x < y) {
        if (p[x] < p[y]) {
          ans++;
        }
        else {
          ans--;
        }

        if (x > 0) {
          if (p[x - 1] < p[x] && p[y] < p[x - 1]) {
            ans++;
          }
          else if (p[x - 1] > p[x] && p[y] > p[x - 1]) {
            ans--;
          }
        }

        if (y + 1 < n) {
          if (p[y] < p[y + 1] && p[x] > p[y + 1]) {
            ans++;
          }
          else if (p[y] > p[y + 1] && p[x] < p[y + 1]) {
            ans--;
          }
        }
      }
      else {
        if (p[y] < p[x]) {
          ans++;
        }
        else {
          ans--;
        }

        if (y > 0) {
          if (p[y - 1] < p[y] && p[x] < p[y - 1]) {
            ans++;
          }
          else if (p[y - 1] > p[y] && p[x] > p[y - 1]) {
            ans--;
          }
        }

        if (x + 1 < n) {
          if (p[x] < p[x + 1] && p[y] > p[x + 1]) {
            ans++;
          }
          else if (p[x] > p[x + 1] && p[y] < p[x + 1]) {
            ans--;
          }
        }
      }

      swap(p[x], p[y]);
      swap(num[a], num[b]);

      cout << ans << '\n';

      continue;
    }

    if (x > 0) {
      if (p[x - 1] < p[x] && p[y] < p[x - 1]) {
        ans++;
      }
      else if (p[x - 1] > p[x] && p[y] > p[x - 1]) {
        ans--;
      }
    }
    if (x + 1 < n) {
      if (p[x] < p[x + 1] && p[y] > p[x + 1]) {
        ans++;
      }
      else if (p[x] > p[x + 1] && p[y] < p[x + 1]) {
        ans--;
      }
    }

    if (y > 0) {
      if (p[y - 1] < p[y] && p[x] < p[y - 1]) {
        ans++;
      }
      else if (p[y - 1] > p[y] && p[x] > p[y - 1]) {
        ans--;
      }
    }
    if (y + 1 < n) {
      if (p[y] < p[y + 1] && p[x] > p[y + 1]) {
        ans++;
      }
      else if (p[y] > p[y + 1] && p[x] < p[y + 1]) {
        ans--;
      }
    }

    swap(p[x], p[y]);
    swap(num[a], num[b]);

    cout << ans << '\n';
  }
}