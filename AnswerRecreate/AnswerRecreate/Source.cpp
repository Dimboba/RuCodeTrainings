#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

void mymin(long long& i, long long& j, std::vector<std::vector<long long>> table)
{
  long long min = std::min(std::min(table[i][j - 1], table[i - 1][j]), table[i - 1][j - 1]);
  if (table[i - 1][j] == min) { --i; return; }
  if (table[i - 1][j - 1] == min) { --i; --j; return; }
  --j;
  return;
}

int main() 
{
  std::cin.tie(NULL);
  long long n, m, inf = 1e18;
  std::cin >> n >> m;
  std::vector<long long> line(m + 1);
  std::vector<std::vector<long long>> table(n + 1, line);
  std::vector<std::vector<long long>> times(n + 1, line);
  for (long long i = 1; i < n + 1; i++)
    for (long long j = 1; j < m + 1; j++)
      std::cin >> table[i][j];
  for (long long i = 0; i < m + 1; i++) table[0][i] = inf; 
  for (long long i = 0; i < n + 1; i++) table[i][0] = inf;
  table[0][0] = 0;
  times[0][0] = 0;
  for (long long i = 1; i < n + 1; i++)
    for (long long j = 1; j < m + 1; j++)
    {
      long long J = j, I = i;
      //mymin(I, J, table);
      //table[i][j] = table[I][J] + table[i][j];
      //times[i][j] = times[I][J];
      //times[i][j]++;
      table[i][j] = std::min(std::min(table[i][j - 1], table[i - 1][j]), table[i - 1][j - 1]) + table[i][j];
    }
  std::cout << table[n][m] << ' ';
  long long I = n, J = m;
  int ans = 0;
  std::stack<std::pair<long long, long long>> st;
  while (true)
  {
    st.push(std::pair<long long, long long>(I, J));
    ans++;
    if (I == 1 && J == 1) break;
    mymin(I, J, table);
  }
  std::cout << ans << std::endl;
  while (st.empty() == false)
  {
    std::cout << st.top().first << ' ' << st.top().second << '\n';
    st.pop();
  }
}