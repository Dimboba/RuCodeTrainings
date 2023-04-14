#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

bool to1_1 = false;

long long horse(int i, int j, int n, int m, std::vector<std::vector<long long>> &table, std::vector<std::vector<bool>> &check)
{
  if (i < 1 || j < 1 || i > n || j > m) return 1e18;
  if (i == 1 && j == 1) to1_1 = true;
  if (check[i][j] == true) return table[i][j];
  check[i][j] = true;
  int delta[4][2] = { {-2, 1}, {-2, -1}, {-1, -2}, {1, -2} };
  long long mn = 1e18, nw;
  for (int idx = 0; idx < 4; idx++)
  {
    nw = horse(i + delta[idx][0], j + delta[idx][1], n, m, table, check);
    if (mn > nw)
      mn = nw;
  }
  return table[i][j] = table[i][j] + mn;
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  std::vector<long long> line(m + 1, 0);
  std::vector<bool> line_bool (m + 1, 0);
  std::vector<std::vector<long long>> table(n + 1, line);
  std::vector<std::vector<bool>> check(n + 1, line_bool);
  check[1][1] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      std::cin >> table[i][j];
  long long ans, I = n, J = m;
  ans = horse(n, m, n, m, table, check);
  std::stack<int> stI, stJ;
  if (to1_1 == false)
  {
    std::cout << "NO";
    return 0;
  }
  while (true)
  {
    stI.push(I);
    stJ.push(J);
    if (I == 1 && J == 1)
      break;
    int delta[4][2] = { {-2, 1}, {-2, -1}, {-1, -2}, {1, -2} };
    long long mn = 1e18, nw, t;
    for (int idx = 0; idx < 4; idx++)
    {
      nw = horse(I + delta[idx][0], J + delta[idx][1], n, m, table, check);
      if (mn > nw)
      {
        mn = nw;
        t = idx;
      }
    }
    I += delta[t][0];
    J += delta[t][1];
  }
  std::cout << "YES" << std::endl << ans << ' ' << stI.size() << std::endl;
  while (stI.empty() == false)
  {
    std::cout << stI.top() << ' ' << stJ.top() << std::endl;
    stI.pop(); stJ.pop();
  }
}