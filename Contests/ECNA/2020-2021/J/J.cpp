#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main()
{ __
  vector<vi> mat(9, vi(9, 0));
  vector<vi> msks(9, vi(9, 0));

  FOR(i, 0, 9)
  {
    FOR(j, 0, 9)
    {
      cin >> mat[i][j];
      int x = mat[i][j];
      x--;
      if (x == -1)
        continue;
      FOR(k, 0, 9)
      {
        msks[k][j] |= (1 << x);
        msks[i][k] |= (1 << x);
      }
    }
  }

  FOR(i, 0, 9)
  {
    FOR(j, 0, 9)
    {
      int cuadV = i / 3;
      int cuadH = j / 3;
      int x = mat[i][j];
      x--;
      if (x == -1)
        continue;
      FOR(ii, 0, 3)
      {
        FOR(jj, 0, 3)
        {
          msks[cuadV*3+ii][cuadH*3+jj] |= (1 << x);
        }
      }
    }
  }

  auto estaInCuadrante = [&](int cuadI, int cuadJ, int x) -> bool
  {
    FOR(i, 0, 3)
    {
      FOR(j, 0, 3)
      {
        if (mat[cuadI*3+i][cuadJ*3+j] == x)
          return true;
      }
    }
    return false;
  };

  auto estaInFila = [&](int fila, int x) -> bool
  {
    FOR(i, 0, 9)
    {
      if (mat[fila][i] == x)
        return true;
    }
    return false;
  };

  auto estaInColum = [&](int colum, int x) -> bool
  {
    FOR(i, 0, 9)
    {
      if (mat[i][colum] == x)
        return true;
    }
    return false;
  };

  bool continua = true;
  while (continua)
  {
    continua = false;
    FOR(i, 0, 9)
    {
      FOR(j, 0, 9)
      {
        int unos = __builtin_popcount(msks[i][j]);
        if (mat[i][j] != 0)
          continue;
        if (unos == 8)
        {
          FOR(k, 0, 9)
          {
            if (!(msks[i][j] & (1 << k)))
            {
              mat[i][j] = k + 1;
              FOR(kk, 0, 9)
              {
                msks[kk][j] |= (1 << k);
                msks[i][kk] |= (1 << k);
              }

              int cuadV = i / 3;
              int cuadH = j / 3;
              FOR(ii, 0, 3)
              {
                FOR(jj, 0, 3)
                {
                  msks[cuadV * 3 + ii][cuadH * 3 + jj] |= (1 << k);
                }
              }
              break;
            }
          }
          continua = true;
        }
      }
    }

    FOR(i,0,9){
      FOR(k,0,9){
        if(estaInFila(i,k+1)) continue;
        int mask = 0;
        FOR(j,0,9){
          if(mat[i][j]!=0){
            mask|=(1<<j);
            continue;
          }
          if(estaInCuadrante(i/3,j/3,k+1)){
            mask|=(1<<j);
            continue;
          }
          if(estaInColum(j,k+1)){
            mask|=(1<<j);
            continue;
          }
        }
        int unos = __builtin_popcount(mask);
        if (unos == 8)
        {
          FOR(j, 0, 9)
          {
            if (!(mask & (1 << j)))
            {
              mat[i][j] = k + 1;
              FOR(kk, 0, 9)
              {
                msks[kk][j] |= (1 << k);
                msks[i][kk] |= (1 << k);
              }

              int cuadV = i / 3;
              int cuadH = j / 3;
              FOR(ii, 0, 3)
              {
                FOR(jj, 0, 3)
                {
                  msks[cuadV * 3 + ii][cuadH * 3 + jj] |= (1 << k);
                }
              }
              break;
            }
          }
          continua = true;
        }
      }
    }

    FOR(j,0,9){
      FOR(k,0,9){
        if(estaInColum(j,k+1)) continue;
        int mask = 0;
        FOR(i,0,9){
          if(mat[i][j]!=0){
            mask|=(1<<i);
            continue;
          }
          if(estaInCuadrante(i/3,j/3,k+1)){
            mask|=(1<<i);
            continue;
          }
          if(estaInFila(i,k+1)){
            mask|=(1<<i);
            continue;
          }
        }
        int unos = __builtin_popcount(mask);
        if (unos == 8)
        {
          FOR(i, 0, 9)
          {
            if (!(mask & (1 << i)))
            {
              mat[i][j] = k + 1;
              FOR(kk, 0, 9)
              {
                msks[kk][j] |= (1 << k);
                msks[i][kk] |= (1 << k);
              }

              int cuadV = i / 3;
              int cuadH = j / 3;
              FOR(ii, 0, 3)
              {
                FOR(jj, 0, 3)
                {
                  msks[cuadV * 3 + ii][cuadH * 3 + jj] |= (1 << k);
                }
              }
              break;
            }
          }
          continua = true;
        }
      }
    }
    
    if (continua)
      continue;

    FOR(i, 0, 3)
    {
      FOR(j, 0, 3)
      {
        FOR(k, 0, 9)
        {
          int mask = 0;
          if (estaInCuadrante(i, j, k + 1))
            continue;
          FOR(ii, 0, 3)
          {
            FOR(jj, 0, 3)
            {
              int encode = ii * 3 + jj;
              if (mat[i * 3 + ii][j * 3 + jj] != 0 || estaInFila(i * 3 + ii, k + 1) || estaInColum(j * 3 + jj, k + 1))
              {
                mask |= (1 << encode);
              }
            }
          }
          int unos = __builtin_popcount(mask);
          if (unos == 8)
          {
            FOR(kk, 0, 9)
            {
              if (!(mask & (1 << kk)))
              {
                int ii = (i * 3) + kk / 3, jj = (j * 3) + kk % 3;
                mat[ii][jj] = k + 1;
                FOR(kkk, 0, 9)
                {
                  msks[kkk][jj] |= (1 << k);
                  msks[ii][kkk] |= (1 << k);
                }

                int cuadV = ii/ 3;
                int cuadH = jj / 3;
                FOR(iii, 0, 3)
                {
                  FOR(jjj, 0, 3)
                  {
                    msks[cuadV * 3 + iii][cuadH * 3 + jjj] |= (1 << k);
                  }
                }
                break;
              }
            }
            continua = true;
          }
        }
      }
    }
  
    
  }

  bool valiomadres = false;
  FOR(i, 0, 9)
  {
    FOR(j, 0, 9)
    {
      if (mat[i][j] == 0)
        valiomadres = true;
    }
  }
  if (valiomadres)
  {
    cout << "Not easy" << ENDL;
  }
  else
  {
    cout << "Easy" << ENDL;
  }

  FOR(i, 0, 9)
  {
    FOR(j, 0, 9)
    {
      if (mat[i][j] == 0)
        cout << ". ";
      else
        cout << mat[i][j] << ' ';
    }
    cout << ENDL;
  }

  return 0;
}