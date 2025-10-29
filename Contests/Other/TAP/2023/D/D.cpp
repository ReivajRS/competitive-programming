#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)b - 1; i >= (int)a; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  int n;
  cin >> n;
  vi a(n), b(n), alc(n);
  for (auto &x : a)
    cin >> x;
  for (auto &x : b)
    cin >> x;
  
  FOR (i, 0, n)
    alc[i] = b[i] / a[i];

  // FOR (i, 0, n)
  //   cout << alc[i] << ENDL;

  int mn = 2e9;

  FOR (i, 0, n) {
    alc[i] = min(mn, alc[i]);
    int sobrante = b[i] - alc[i] * a[i];
    b[i] = alc[i] * a[i];

    if (i + 1 >= n)
      break;
    
    b[i + 1] += sobrante;
    int j = i + 1, sumA = a[i], sumB = b[i];
    while (j < n && alc[j] < alc[i]) {
      sumA += a[j];
      sumB += b[j];
      j++;
    }

    alc[i] = sumB / sumA;
    b[i] = alc[i] * a[i];
    mn = min(mn, alc[i]);

    int sumAlc = 0;
    FOR (k, i, j) {
      alc[k] = alc[i];
      b[k] = alc[i] * a[k];
      sumAlc += b[k];
    }
    
    if (j + 1 >= n)
      break;
    
    b[j + 1] += sumB - sumAlc;
    i = j;
  }

  FOR (i, 0, n)
    cout << alc[i] << ENDL;

  cout << alc[n - 1] << ENDL;

  return 0;
}