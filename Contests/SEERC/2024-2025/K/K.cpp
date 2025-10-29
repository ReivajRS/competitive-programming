#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  string s;
  cin >> n >> q >> s;

  string letras = "" + s[0];
  vector<ll> ind(1);
  for (int i = 1; i < n; ++i) {
    if (s[i] != s[i - 1]) {
      letras += s[i];
      ind.push_back(1);
    } else {
      ind.back()++;
    }
  }

  constexpr int BLOCK_SIZE = 450;

  for (int i = 0; i < BLOCK_SIZE; ++i) {
    ind.push_back(0);
  }

  vector<ll> suma(BLOCK_SIZE + 5), lazy(BLOCK_SIZE + 5);
  for (int i = 0; i < (int)ind.size(); ++i) {
    suma[i / BLOCK_SIZE] += ind[i];
  }

  auto upd = [&](int b) -> void {
            int right = b * (BLOCK_SIZE + 1);
            for (int i = b * BLOCK_SIZE; i < right; ++i) {
              ind[i] *= 1ll << lazy[b];
            }
            lazy[b] = 0;
  };

  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      ll l, r;
      cin >> l >> r;
      --l, --r;
      for (int b = 0; b < (int)suma.size(); ++b) {
        if (l > suma[b]) {
          l -= suma[b];
          r -= suma[b];
          continue;
        }
        if (l <= suma[b]) {
          // cola izquierda
          // [ xxx]  [    ] [    ]
          upd(b);
          ll sobra = suma[b] - l;
          for (int i = b * (BLOCK_SIZE + 1) - 1; sobra; --i) {
            ll add = min(sobra, ind[i]);
            ind[i] += add;
            sobra -= add;
          }
          l = 0;
          r -= sobra;
          continue;
        }
        if (l == 0 && r > suma[b]) {
          // en medio
          lazy[b]++;
          suma[b] <<= 1;
          r -= suma[b];
          continue;
        }
        if (l == 0 && r <= suma[b]) {
          // cola derecha
          upd(b);
          ll sobra = suma[b] - l;
          for (int i = b * BLOCK_SIZE; sobra; ++i) {
            ll add = min(sobra, ind[i]);
            ind[i] += add;
            sobra -= add;
          }
          break;
        }
      }
      continue;
    }
    ll x;
    cin >> x;
    --x;
    int b = 0;
    while (suma[b] < x) {
      suma[b] -= x;
      ++b;
    }
    upd(b);
    int i = b * BLOCK_SIZE;
    while (ind[i] < x) {
      x -= ind[i];
      ++i;
    }
    cout << letras[i] << '\n';
  }

  return 0;
}