#include<bits/stdc++.h>
using namespace std;
#pragma once
vector<int> PI(const string& s) {
  vector<int> p((int)s.size());
  for (int i = 1; i < (int)s.size(); i++) {
    int g = p[i - 1];
    while (g && s[i] != s[g]) g = p[g - 1];
    p[i] = g + (s[i] == s[g]);
  }
  return p;
}

// Concatena s + \0 + pat para encontrar las ocurrencias
vector<int> KMP(const string& s, const string& pat) {
  vector<int> phi = PI(pat + '\0' + s), res;
  for (int i = (int)phi.size() - (int)s.size(); i < (int)phi.size(); i++)
    if (phi[i] == (int)pat.size()) 
      res.push_back(i - 2 * (int)pat.size());
  return res;
}

vector<string> split(string s, string pat) {
  s += pat;
  vector<int> occurences = KMP(s, pat);
  vector<string> parts;
  int x = 0;
  for (auto i : occurences) {
    int aux = x;
    i -= aux;
    x += i + (int)pat.size();
    if (i == 0) {
      s = s.substr((int)pat.size());
      continue;
    }
    parts.push_back(s.substr(0, i));
    s = s.substr(i + (int)pat.size());
  }
  return parts;
}
