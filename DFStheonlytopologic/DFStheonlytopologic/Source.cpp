#include<iostream>
#include<vector>
#include<stack>
#include<list>
#include<set>

int main()
{
  int n, m, a, b, num_stocks;
  std::cin >> n >> m;
  num_stocks = n;
 // std::vector<int> in_this(n + 1, 0);
  std::list<int>::iterator it;
  std::vector<std::list<int>> lst(n + 1), rev(n + 1);
  for (int i = 0; i < m; i++)
  {
    std::cin >> a >> b;
    if (rev[b].empty() == true)
      num_stocks--;
    lst[a].push_back(b);
    rev[b].push_back(a);
  }
  int new_stock = -1;
  int stock;
  for (int j = 1; j <= n; j++)
  {
    if (lst[j].empty())
      new_stock = j;
  }
  for (int i = 0; i < n; i++)
  {
    stock = new_stock;
    if (num_stocks != 1)
    {
      std::cout << "NO";
      return 0;
    }
    lst[stock].push_back(stock); // аналог удаления стока
    num_stocks--;
    for (it = rev[stock].begin(); it != rev[stock].end(); it++)
    {
      lst[*it].remove(stock);
      if (lst[*it].size() == 0)
      {
        num_stocks++;
        new_stock = *it;
      }
    }
  }
  std::cout << "YES";

  
}