#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  auto print = [&](vector<int> &a) -> void {
      for(auto x:a){
        cout << x;
      }
      cout << '\n';
    };
  cin.tie(0)->sync_with_stdio(0);

  string s1, s2;
  cin >> s1 >> s2;
  vector<int> n1(SZ(s1)), n2(SZ(s2));
  for (int i = 0; i < SZ(n1); i++) {
    n1[i] = s1[i] - '0';
  }
  for (int i = 0; i < SZ(n2); i++) {
    n2[i] = s2[i] - '0';
  }

  if (SZ(n1) > SZ(n2)) {
    swap(n1, n2);
  }

  reverse(n1.begin(), n1.end());
  n1.resize(SZ(n2), 0);
  reverse(n1.begin(), n1.end());

  auto f = [&](vector<int> n1, vector<int> n2) -> vector<int> {
    int idx = -1;
    vector<int> num = n1;
    for (int i = 0; i < SZ(n1); i++) {
      if (n1[i] + n2[i] >= 10) {
        idx = i;
        break;
      }
    }
    if (idx == -1) {
      return {0};
    }
    for (int i = idx; i < SZ(n1); i++) {
      num[i] = 0;
    }
    idx -= 1;
    bool carry = 1;
    
    for (int i = idx; i >= 0; i--) {
      int sum = n1[i] + n2[i];
      if (carry) {
        if (sum == 9) {
          num[i] = 0;
        }
        else {
          num[i] = n1[i] + 1;
          carry = 0;
        }
      }
      else {
        break;
      }
    }
    if (carry) {
      num.insert(num.begin(), 1);
      n1.insert(n1.begin(), 0);
    }
    
    reverse(num.begin(),num.end());
    reverse(n1.begin(),n1.end());

    vector<int> resta;
    int prestado = 0;
    for(int i=0;i<SZ(num);i++){
      int re = num[i]-n1[i]-prestado;
      if(re<0){
        re+=10;
        prestado=1;
      }else{
        prestado=0;
      }
      resta.push_back(re);
    }
    while(SZ(resta) && resta.back() == 0) resta.pop_back();
    reverse(resta.begin(),resta.end());
    return resta;
  };
  
  vector<int> r1,r2;
  r1 = f(n1,n2),r2 = f(n2,n1);
  if(SZ(r1) == SZ(r2)){
    for(int i=0;i<SZ(r1);i++){
      if(r1[i]<r2[i]){
        print(r1);
        exit(0);
      }else if(r2[i]<r1[i]){
        print(r2);
        exit(0);
      }
    }
    print(r1);
    exit(0);
  }else if(SZ(r1)<SZ(r2)){
    print(r1);
  }else{
    print(r2);
  }
  
  return 0;
}