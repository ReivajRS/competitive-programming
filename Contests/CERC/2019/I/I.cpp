#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  map<char,int> mp;
  mp['A'] = 0;
  mp['C'] = 1;
  mp['G'] = 2;
  mp['T'] = 3;

  string s,t;
  cin >> s >> t;
  vector<vi> cnt(4,vi(4,0));
  FOR(i,0,SZ(s)){
    cnt[mp[s[i]]][mp[t[i]]]++;
  }
  long long ans = 0;
  FOR(a,0,4){
    FOR(b,0,4){
      if(a == b) continue;
      int x = min(cnt[a][b],cnt[b][a]);
      ans +=x;
      cnt[a][b]-=x,cnt[b][a]-=x;
    }
  }

  FOR(a,0,4){
    FOR(b,0,4){
      FOR(c,0,4){
        set<int> st;
        st.insert(a),st.insert(b),st.insert(c);
        if(SZ(st) != 3) continue;
        int x = min({cnt[a][b],cnt[b][c],cnt[c][a]});
        ans += x*2;
        cnt[a][b]-=x,cnt[b][c]-=x,cnt[c][a]-=x;
      }
    }
  }

  FOR(a,0,4){
    FOR(b,0,4){
      FOR(c,0,4){
        FOR(d,0,4){
          set<int> st;
          st.insert(a),st.insert(b),st.insert(c),st.insert(d);
          if(SZ(st) != 4) continue;
          int x = min({cnt[a][b],cnt[b][c],cnt[c][d],cnt[d][a]});
          ans += x*3;
          cnt[a][b]-=x,cnt[b][c]-=x,cnt[c][d]-=x,cnt[d][a]-=x;
        }
      }
    }
  }
  cout << ans << ENDL;

  return 0;
}