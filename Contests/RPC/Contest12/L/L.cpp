#include <bits/stdc++.h>
using namespace std;
// Pura gente del Coach Moy

using ll = long long;

#define SZ(x) ((ll)x.size())

void quita(ll &a, ll &b) {
  ll mn = min(a, b);
  a -= mn;
  b -= mn;
}

ll caso8(ll k,ll A,ll B,ll C,ll AB,ll BC,ll AC,ll ABC){
  //8 -> AB=B,BC=C,AC=C
  ll ans = 0;
  ans+=(A+k-1)/k;
  ll sobA = A%k;
  if(A%k) sobA = k-(A%k);
  quita(ABC, sobA);

  ans+=(B+k-1)/k;
  ll sobB = B%k;
  if(B%k) sobB = k-(B%k);
  quita(AB, sobB);
  quita(ABC, sobB);

  ans+=(C+k-1)/k;
  ll sobC = C%k;
  if(C%k) sobC = k-(C%k);
  quita(BC,sobC);
  quita(AC,sobC);
  quita(ABC,sobC);

  ll ABBC = AB+BC;
  ans+=(ABBC+k-1)/k;
  ll sobABBC = ABBC%k;
  if(ABBC%k) sobABBC = k-(ABBC%k);
  quita(AC,sobABBC);
  quita(ABC,sobABBC);
  ans+=(AC+k-1)/k;
  ll sobraAC = AC%k;
  if(AC%k) sobraAC = k-(AC%k);
  quita(ABC,sobraAC);
  ans+=(ABC+k-1)/k;
  return ans;
}

ll caso7(ll k,ll A,ll B,ll C,ll AB,ll BC,ll AC,ll ABC){
  //7 -> AB=B,BC=B,AC=C
  ll ans = 0;
  ans+=(A+k-1)/k;
  ll sobA = A%k;
  if(A%k) sobA = k-(A%k);
  quita(ABC, sobA);

  ans+=(B+k-1)/k;
  ll sobB = B%k;
  if(B%k) sobB = k-(B%k);
  quita(AB,sobB);
  quita(BC, sobB);
  quita(ABC, sobB);

  ans+=(C+k-1)/k;
  ll sobC = C%k;
  if(C%k) sobC = k-(C%k);
  quita(AC,sobC);
  quita(ABC,sobC);

  ll ABBC = AB+BC;
  ans+=(ABBC+k-1)/k;
  ll sobABBC = ABBC%k;
  if(ABBC%k) sobABBC = k-(ABBC%k);
  quita(AC,sobABBC);
  quita(ABC,sobABBC);
  ans+=(AC+k-1)/k;
  ll sobraAC = AC%k;
  if(AC%k) sobraAC = k-(AC%k);
  quita(ABC,sobraAC);
  ans+=(ABC+k-1)/k;
  return ans;
}

ll caso6(ll k,ll A,ll B,ll C,ll AB,ll BC,ll AC,ll ABC){
  //6 -> AB=B,BC=C,AC=A
  ll ans = 0;
  ans+=(A+k-1)/k;
  ll sobA = A%k;
  if(A%k) sobA = k-(A%k);
  quita(AC, sobA);
  quita(ABC, sobA);

  ans+=(B+k-1)/k;
  ll sobB = B%k;
  if(B%k) sobB = k-(B%k);
  quita(AB, sobB);
  quita(ABC, sobB);

  ans+=(C+k-1)/k;
  ll sobC = C%k;
  if(C%k) sobC = k-(C%k);
  quita(BC,sobC);
  quita(ABC,sobC);

  ll ABBC = AB+BC;
  ans+=(ABBC+k-1)/k;
  ll sobABBC = ABBC%k;
  if(ABBC%k) sobABBC = k-(ABBC%k);
  quita(AC,sobABBC);
  quita(ABC,sobABBC);
  ans+=(AC+k-1)/k;
  ll sobraAC = AC%k;
  if(AC%k) sobraAC = k-(AC%k);
  quita(ABC,sobraAC);
  ans+=(ABC+k-1)/k;
  return ans;
}

ll caso5(ll k,ll A,ll B,ll C,ll AB,ll BC,ll AC,ll ABC){
  //5 -> AB=A,BC=B,AC=C
  ll ans = 0;
  ans+=(A+k-1)/k;
  ll sobA = A%k;
  if(A%k) sobA = k-(A%k);
  quita(AB, sobA);
  quita(ABC, sobA);

  //1135
  // ans = 243243, AB -> 956270762

  ans+=(B+k-1)/k;
  ll sobB = B%k;
  if(B%k) sobB = k-(B%k);
  quita(BC, sobB);
  quita(ABC, sobB);

  // ans = 356970, BC -> 344991562

  ans+=(C+k-1)/k;
  ll sobC = C%k;
  if(C%k) sobC = k-(C%k);
  quita(AC,sobC);
  quita(ABC,sobC);
  
  // ans = 429078, AC -> 31401465

  

  ll ABBC = AB+BC;
  ans+=(ABBC+k-1)/k;
  ll sobABBC = ABBC%k;
  if(ABBC%k) sobABBC = k-(ABBC%k);
  quita(AC,sobABBC);
  quita(ABC,sobABBC);
  ans+=(AC+k-1)/k;
  ll sobraAC = AC%k;
  if(AC%k) sobraAC = k-(AC%k);
  quita(ABC,sobraAC);
  ans+=(ABC+k-1)/k;
  return ans;
}

ll caso1(ll k,ll A,ll B,ll C,ll AB,ll BC,ll AC,ll ABC){
  //1 -> AB=A,BC=B,AC=A
  ll ans = 0;
  ans+=(A+k-1)/k;
  ll sobA = A%k;
  if(A%k) sobA = k-(A%k);
  quita(AB, sobA);
  quita(AC, sobA);
  quita(ABC, sobA);

  ans+=(B+k-1)/k;
  ll sobB = B%k;
  if(B%k) sobB = k-(B%k);
  quita(BC, sobB);
  quita(ABC, sobB);

  ans+=(C+k-1)/k;
  ll sobC = C%k;
  if(C%k) sobC = k-(C%k);
  quita(ABC,sobC);

  ll ABBC = AB+BC;
  ans+=(ABBC+k-1)/k;
  ll sobABBC = ABBC%k;
  if(ABBC%k) sobABBC = k-(ABBC%k);
  quita(AC,sobABBC);
  quita(ABC,sobABBC);
  ans+=(AC+k-1)/k;
  ll sobraAC = AC%k;
  if(AC%k) sobraAC = k-(AC%k);
  quita(ABC,sobraAC);
  ans+=(ABC+k-1)/k;
  return ans;
}

ll caso2(ll k,ll A,ll B,ll C,ll AB,ll BC,ll AC,ll ABC){
  //2 -> AB=B,BC=B,AC=A
  ll ans = 0;
  ans+=(A+k-1)/k;
  ll sobA = A%k;
  if(A%k) sobA = k-(A%k);
  quita(AC, sobA);
  quita(ABC, sobA);

  ans+=(B+k-1)/k;
  ll sobB = B%k;
  if(B%k) sobB = k-(B%k);
  quita(AB,sobB);
  quita(BC, sobB);
  quita(ABC, sobB);

  ans+=(C+k-1)/k;
  ll sobC = C%k;
  if(C&& C <= k) sobC = k-C;
  quita(ABC,sobC);

  ll ABBC = AB+BC;
  ans+=(ABBC+k-1)/k;
  ll sobABBC = ABBC%k;
  if(ABBC%k) sobABBC = k-(ABBC%k);
  quita(AC,sobABBC);
  quita(ABC,sobABBC);
  ans+=(AC+k-1)/k;
  ll sobraAC = AC%k;
  if(AC%k) sobraAC = k-(AC%k);
  quita(ABC,sobraAC);
  ans+=(ABC+k-1)/k;
  return ans;
}

ll caso3(ll k,ll A,ll B,ll C,ll AB,ll BC,ll AC,ll ABC){
  //3 -> AB=A,BC=C,AC=A
  ll ans = 0;
  ans+=(A+k-1)/k;
  ll sobA = A%k;
  if(A%k) sobA = k-(A%k);
  quita(AB,sobA);
  quita(AC, sobA);
  quita(ABC, sobA);

  ans+=(B+k-1)/k;
  ll sobB = B%k;
  if(B%k) sobB = k-(B%k);
  quita(ABC, sobB);

  ans+=(C+k-1)/k;
  ll sobC = C%k;
  if(C%k) sobC = k-(C%k);
  quita(BC,sobC);
  quita(ABC,sobC);

  ll ABBC = AB+BC;
  ans+=(ABBC+k-1)/k;
  ll sobABBC = ABBC%k;
  if(ABBC%k) sobABBC = k-(ABBC%k);
  quita(AC,sobABBC);
  quita(ABC,sobABBC);
  ans+=(AC+k-1)/k;
  ll sobraAC = AC%k;
  if(AC%k) sobraAC = k-(AC%k);
  quita(ABC,sobraAC);
  ans+=(ABC+k-1)/k;
  return ans;
}

ll caso4(ll k,ll A,ll B,ll C,ll AB,ll BC,ll AC,ll ABC){
  //4 -> AB=A,BC=C,AC=C
  ll ans = 0;
  ans+=(A+k-1)/k;
  ll sobA = A%k;
  if(A%k) sobA = k-(A%k);
  quita(AB,sobA);
  quita(ABC, sobA);

  //AB -> 0, ans = 2

  ans+=(B+k-1)/k;
  ll sobB = B%k;
  if(B%k) sobB = k-(B%k);
  quita(ABC, sobB);

  //ABC -> 0, ans = 4

  ans+=(C+k-1)/k;
  ll sobC = C%k;
  if(C%k) sobC = k-(C%k);
  quita(BC,sobC);
  quita(AC,sobC);
  quita(ABC,sobC);

  ll ABBC = AB+BC;
  ans+=(ABBC+k-1)/k;
  ll sobABBC = ABBC%k;
  if(ABBC%k) sobABBC = k-(ABBC%k);
  quita(AC,sobABBC);
  quita(ABC,sobABBC);
  ans+=(AC+k-1)/k;
  ll sobraAC = AC%k;
  if(AC%k) sobraAC = k-(AC%k);
  quita(ABC,sobraAC);
  ans+=(ABC+k-1)/k;
  return ans;
}

void solve(){
  ll k;
  cin >> k;
  ll A,B,C,AB,BC,AC,ABC;
  cin >> A >> B >> C >> AB >> BC >> AC >> ABC;


  
  ll ans = min({
    caso1(k,A,B,C,AB,BC,AC,ABC),
    caso2(k,A,B,C,AB,BC,AC,ABC),
    caso3(k,A,B,C,AB,BC,AC,ABC),
    caso4(k,A,B,C,AB,BC,AC,ABC),
    caso5(k,A,B,C,AB,BC,AC,ABC),
    caso6(k,A,B,C,AB,BC,AC,ABC),
    caso7(k,A,B,C,AB,BC,AC,ABC),
    caso8(k,A,B,C,AB,BC,AC,ABC),
  });
  cout << ans << '\n';
}

signed main()
{
  cin.tie(0)->sync_with_stdio(0);

  ll t;
  cin >> t;
  while(t--) solve();

}