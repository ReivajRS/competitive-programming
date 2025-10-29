#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  const int block = int(sqrt(n) + 1);
  const int size = (n + block - 1) / block;

  vector<vector<int>> sq(block, vector<int>(size, -1));
  vector<int> cnt(block, 0);
  
  int num = 1;
  for (int i = 0; i < block && num <= n; i++) {
    for (int j = 0; j < size && num <= n; j++) {
      sq[i][j] = num++;
      cnt[i]++;
    }
  }
  
  int alive = n;
  int i = 0, j = 0;

  auto normalize = [&]() -> void {
    if (j == size) {
      j = 0, i++;
    }
    if (i == block) {
      i = 0;
    }
  };

  auto go = [&](int steps) -> void {
    while (steps > 0 && j < size) {
      if (sq[i][j] != -1) {
        steps--;
      }
      if (steps == 0 || j == size) {
        return;
      }
      j++;
    }

    normalize();

    while (steps > cnt[i]) {
      steps -= cnt[i];
      i++;
      normalize();
    }

    while (steps > 0) {
      if (sq[i][j] != -1) {
        steps--;
      }
      if (steps == 0) {
        return;
      }
      j++;
    }

    normalize();
  };

  while (alive > 0) {
    int len = k % alive + 1;
    go(len);

    cout << sq[i][j] << ' ';
    sq[i][j] = -1;
    cnt[i]--;
    alive--;
    
    if (alive > 0) {
      go(1);
    }
  }

  cout << '\n';
}