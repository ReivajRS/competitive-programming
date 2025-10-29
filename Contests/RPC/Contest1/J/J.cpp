#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = a - 1; i >= b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

void solve(map<int,set<int>> &g, string s){
  stack<int> pila;
  string num = "";
  FOR(i,0,SZ(s)){
    if(s[i] != '(' && s[i] != ')'){
      num+=s[i];
      continue;
    }
    int n=0;
    if(SZ(num)){
      n = stoi(num);
      num = "";
      if(SZ(pila)){
        g[pila.top()].insert(n);
      }
      pila.push(n);
    }
    
    if(s[i] == ')'){
      pila.pop();
    }
  }
}

signed main() { __
  
  string input1,input2;
  getline(cin,input1);
  getline(cin,input2);
  string s1 = "",s2 = "";
  FOR(i,0,SZ(input1)){
    if(input1[i] != ' ') s1+=input1[i];
  }
  FOR(i,0,SZ(input2)){
    if(input2[i] != ' ') s2+=input2[i];
  }

  map<int,set<int>> g1;
  map<int,set<int>> g2;
  
  solve(g1,s1);
  solve(g2,s2);

  if(SZ(g1) != SZ(g2)){
    cout << "No" << ENDL;
    return 0;
  }

  if(!SZ(g1)){
    if(s1 == s2){
      cout << "Yes" << ENDL;
    }else{
      cout << "No" << ENDL;
    }
    return 0;
  }

  for(auto &[nodo,hijos]:g1){
    if (!g2.count(nodo)) {
      cout << "No" << ENDL;
      return 0;      
    }
    if(SZ(g1[nodo]) != SZ(g2[nodo])){
      cout << "No" << ENDL;
      return 0;
    }
    for(auto h:hijos){
      if(!g2[nodo].count(h)){
        cout << "No" << ENDL;
        return 0;
      }
    }
  }

  for(auto &[nodo,hijos]:g2){
    if (!g1.count(nodo)) {
      cout << "No" << ENDL;
      return 0;      
    }
    if(SZ(g1[nodo]) != SZ(g2[nodo])){
      cout << "No" << ENDL;
      return 0;
    }
    for(auto h:hijos){
      if(!g1[nodo].count(h)){
        cout << "No" << ENDL;
        return 0;
      }
    }
  }


  cout << "Yes" << ENDL;

  return 0;
}