#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

char s[N];

int main()
{
  int tt;
  scanf("%d", &tt);
  while (tt--)
  {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    vector<vector<int>> lcp(n + 2, vector<int>(n + 2));
    for (int i = n; i >= 1; i--)
      for (int j = n; j >= i; j--)
        if (s[i] == s[j])
          lcp[i][j] = lcp[i + 1][j + 1] + 1;
    long long ans = 0;
    vector<vector<int>> sum(n + 1, vector<int>(n + 2));
    for (int i = 1; i < n; i++)
      for (int j = i + 1; j <= n; j++)
        if (lcp[i][j] >= j - i)
          sum[j][j - i]++;
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
        sum[i][j] += sum[i][j - 1];
      for (int j = 1; j <= n; j++)
        sum[i][j] += sum[i][j - 1];
    }
    for (int i = 1; i < sum.size(); i++) {
      for (int j = 1; j < sum[0].size(); j++) {
        cout << sum[i][j] << ' ';
      }
      cout << '\n';
    }
    for (int j = 1; j < n; j++)
    {
      for (int k = j + 1; k <= n; k++)
      {
        int len = min(lcp[j][k], k - j - 1) - 1;
        if (len >= 0)
          ans += sum[j][len];
      }
    }
    printf("%lld\n", ans);
  }
}