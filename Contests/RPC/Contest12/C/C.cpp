#include <bits/stdc++.h>
using namespace std;
// Pura gente del Coach Moy

using ll = long long;

#define SZ(x) ((int)x.size())

const int MX = 5e3;
inline int add(int a, int b, const int &mod) { return a + b >= mod ? a + b - mod : a + b; }
inline int sbt(int a, int b, const int &mod) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b, const int &mod) { return 1ll * a * b % mod; }

const int X[] = {257, 359};
const int MOD[] = {(int)1e9 + 7, (int)1e9 + 9};
vector<int> xpow[2];

struct hashing
{
  vector<int> h[2];

  hashing(string &s)
  {
    int n = SZ(s);
    for (int j = 0; j < 2; j++)
    {
      h[j].resize(n + 1);
      for (int i = 1; i <= n; i++)
      {
        h[j][i] = add(mul(h[j][i - 1], X[j], MOD[j]), s[i - 1], MOD[j]);
      }
    }
  }

  ll value(int l, int r)
  {
    int a = sbt(h[0][r], mul(h[0][l], xpow[0][r - l], MOD[0]), MOD[0]);
    int b = sbt(h[1][r], mul(h[1][l], xpow[1][r - l], MOD[1]), MOD[1]);
    return (ll(a) << 32) + b;
  }
};

void calc_xpow(int mxlen = MX)
{
  for (int j = 0; j < 2; j++)
  {
    xpow[j].resize(mxlen + 1, 1);
    for (int i = 1; i <= mxlen; i++)
    {
      xpow[j][i] = mul(xpow[j][i - 1], X[j], MOD[j]);
    }
  }
}

signed main()
{
  cin.tie(0)->sync_with_stdio(0);

  calc_xpow();

  int n;
  cin >> n;
  string s = "";
  vector<pair<int, char>> var;
  set<int> pos;
  vector<int> ini(n),fin(n);
  for (int i = 0; i < n; i++)
  {
    string ss;
    cin >> ss;
    ini[i] = SZ(s);

    if (ss.size() == 1 && (islower(ss[0]) or isupper(ss[0])))
    {
      pos.insert(SZ(s));
    }
    s += ss;
    fin[i] = SZ(s);
    if (i != n - 1)
    {
      s += " ";
    }
  }
  // s = "for a in range(10) do print b a end"
  set<ll> st;

  for (int i = 0; i < n; i++)
  {
    int in = ini[i];
    string sh = "";
    unordered_map<char, char> mp;
    char curr = 'a' - 1;
    for (int j = in; j < SZ(s); j++)
    {
      if (pos.count(j))
      {
        if (!mp.count(s[j]))
        {
          if (curr == 'z')
            curr = 'A';
          else
            curr++;
          mp[s[j]] = curr;
        }
        sh += mp[s[j]];
        continue;
      }
      sh += s[j];
    }
    hashing h(sh);
    //cout << sh << '\n';
    for(int j=i;j<n;j++) {
      //cout << sh.substr(0,fin[j]-in) << '\n'; 
      st.insert(h.value(0, fin[j]-in));
    }
  }

  int q;
  cin >> q;
  //cout << "------" << '\n';
  while (q--)
  {
    int m;
    cin >> m;

    set<int> pos;
    string t="";
    for (int i = 0; i < m; i++)
    {
      string ss;
      cin >> ss;

      if (ss.size() == 1 && (islower(ss[0]) or isupper(ss[0])))
      {
        pos.insert(SZ(t));
      }
      t += ss;
      if (i != m - 1)
      {
        t += " ";
      }
    }

    string sh = "";
    unordered_map<char, char> mp;
    char curr = 'a' - 1;
    for (int j = 0; j < SZ(t); j++)
    {
      if (pos.count(j))
      {
        if (!mp.count(t[j]))
        {
          if (curr == 'z')
            curr = 'A';
          else
            curr++;
          mp[t[j]] = curr;
        }
        sh += mp[t[j]];
        continue;
      }
      sh += t[j];
    }
    //cout << sh << "-"<< "\n";
    hashing h(sh);
    ll val = h.value(0,SZ(sh));

    if(st.count(val)){
      cout << "yes\n";
    }else{
      cout << "no\n";
    }
  }
}