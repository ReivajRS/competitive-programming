#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

signed main() {
  vi a(3);
  cin >> a[0] >> a[1] >> a[2];
  sort(a.begin(),a.end());
  if(a[0]+a[1] >a[2]){
    cout << "N" << "\n";
  }else{
    cout << "S" << "\n";
  }
}