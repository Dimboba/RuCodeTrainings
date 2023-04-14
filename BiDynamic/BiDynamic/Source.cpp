#include<iostream>
#include<algorithm>

int horse(int i, int j, int n, int m, long long** table, long long mod = 1e9 + 123)
{
  if (i > n || j > m || i < 1 || j < 1) return 0;
  if (table[i][j] != -1) return table[i][j];
  int delta[4][2] = { {-2, 1}, {-2, -1}, {-1, -2}, {1, -2} };
  table[i][j] = 0;
  for (int idx = 0; idx < 4; idx++)
    table[i][j] = (horse(i + delta[idx][0], j + delta[idx][1], n, m, table) + table[i][j]) % mod;
  /*
  table[i][j] = (table[i][j] + horse(i - 2, j + 1, n, m, table)) % mod;
  table[i][j] = (table[i][j] + horse(i - 2, j - 1, n, m, table)) % mod;
  table[i][j] = (table[i][j] + horse(i - 1, j - 2, n, m, table)) % mod;
  table[i][j] = (table[i][j] + horse(i + 1, j - 2, n, m, table)) % mod;
  */
  return table[i][j];
}

int main()
{
  long long n, m, a;
  long long const inf = 1e9, mod = 1e9 + 7;
  std::cin >> n >> m;
  long long** table = new long long* [n + 1];
  for (long long i = 0; i < n + 1; i++) table[i] = new long long[m + 1];
  // 1 задача--------------------------------------------
  /*
  for (long long i = 1; i < n + 1; i++)
    for (long long j = 1; j < m + 1; j++)
      std::cin >> table[i][j];
  for (long long i = 0; i < m + 1; i++) table[0][i] = inf;
  for (long long i = 0; i < n + 1; i++) table[i][0] = inf;
  table[0][0] = 0;
  for (long long i = 1; i < n + 1; i++)
    for (long long j = 1; j < m + 1; j++)
    {
      table[i][j] = std::min(std::min(table[i][j - 1], table[i - 1][j]), table[i-1][j-1]) + table[i][j];
    }
  std::cout << table[n][m];
  */ 
  // 2 задача--------------------------------------------
  /*
  table[0][0] = 1;
  for (long long i = 1; i < m + 1; i++) table[0][i] = 0;
  for (long long i = 1; i < n + 1; i++) table[i][0] = 0;
  for(long long i = 1; i < n + 1; i++)
    for (long long j = 1; j < m + 1; j++)
    {
      std::cin >> a;
      if (a == 1) { table[i][j] = 0; continue; }
      table[i][j] = (table[i - 1][j] + table[i][j - 1] + table[i - 1][j - 1]) % mod;
    }
  std::cout << table[n][m];
  */
  //3 задача---------------------------------------------
  /*
  for (long long i = 1; i < n + 1; i++)
    for (long long j = 1; j < m + 1; j++)
      table[i][j] = -1;
  table[1][1] = 1;
  std::cout << horse(n, m, n, m, table);
  */
  // 4 задача---------------------------------------------
  /*
  long long** prefI = new long long* [n + 1];
  for (long long i = 0; i < n + 1; i++) prefI[i] = new long long[m + 1];
  long long** prefJ = new long long* [n + 1];
  for (long long i = 0; i < n + 1; i++) prefJ[i] = new long long[m + 1];

  for (long long i = 0; i < m + 1; i++) { table[0][i] = 0; prefI[0][i] = 0; }
  for (long long i = 0; i < n + 1; i++) { table[i][0] = 0; prefJ[i][0] = 0; }
  table[0][0] = 1; prefI[0][0] = 0; prefJ[0][0] = 0;
  
  for(int i = 1; i < n + 1; i++)
    for (int j = 1; j < m + 1; j++)
    {
      table[i][j] = (prefI[i - 1][j] + prefJ[i][j - 1]) % mod;
      if (i == 1 && j == 1) table[i][j] = 1;
      prefI[i][j] = (prefI[i - 1][j] + table[i][j]) % mod;
      prefJ[i][j] = (prefJ[i][j - 1] + table[i][j]) % mod;
    }
  std::cout << table[n][m];
  */
  // 5 задача--------------------------------------------
  /*
  long long** prefI = new long long* [n + 1];
  for (long long i = 0; i < n + 1; i++) prefI[i] = new long long[m + 1];
  long long** prefJ = new long long* [n + 1];
  for (long long i = 0; i < n + 1; i++) prefJ[i] = new long long[m + 1];
  long long** prefD = new long long* [n + 1];
  for (long long i = 0; i < n + 1; i++) prefD[i] = new long long[m + 1];

  for (long long i = 0; i < m + 1; i++) { table[0][i] = 0; prefI[0][i] = 0; prefD[0][i] = 0; }
  for (long long i = 0; i < n + 1; i++) { table[i][0] = 0; prefJ[i][0] = 0; prefD[i][0] = 0; }
  table[0][0] = 1; 
  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < m + 1; j++)
    {
      table[i][j] = (prefI[i - 1][j] + prefJ[i][j - 1] + prefD[i-1][j-1]) % mod;
      if (i == 1 && j == 1) table[i][j] = 1;
      prefI[i][j] = (prefI[i - 1][j] + table[i][j]) % mod;
      prefJ[i][j] = (prefJ[i][j - 1] + table[i][j]) % mod;
      prefD[i][j] = (prefD[i - 1][j - 1] + table[i][j]) % mod;
    }
  std::cout << table[n][m];
  */

}