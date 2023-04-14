#include<iostream>
#include<vector>
#include<set>

int main()
{
  // 1 - матрица в список смежности
  /*
  int n;
  char ch;
  std::cin >> n;
  std::vector<std::vector<int>> matrix(n + 1, std::vector<int>(n + 1, 0));
  for(int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
      std::cin >> ch;
      if (ch == '1') matrix[i][j] = 1;
    }
  for (int i = 1; i <= n; i++)
  {
    std::list<int> lst;
    for (int j = 1; j <= n; j++)
    {
      if (matrix[i][j] == 1)
        lst.push_back(j);
    }
    std::cout << lst.size() << ' ';
    while (lst.empty() == false)
    {
      std::cout << lst.front() << ' ';
      lst.pop_front();
    }
    std::cout << std::endl;
  }
  */
  // 2 - список ребер в список смжности
  /*
  int n, m, a, b;
  std::cin >> n >> m;
  std::set<int>* lst = new std::set<int>[n + 1]; //сет а не список, ибо требуется сортировать (а лень)
  for (int i = 0; i < m; i++)
  {
    std::cin >> a >> b;
    lst[a].insert(b);
    lst[b].insert(a);
  }
  for (int i = 1; i <= n; i++)
  {
    std::cout << lst[i].size() << ' ';
    while(lst[i].empty() == false)
    {
      std::cout << *lst[i].begin() << ' ';
      lst[i].erase(*lst[i].begin());
    }
    std::cout << std::endl;
  }
  */
  // 3 - список ребер в матрицу смежности
  /*
  int n, m, a, b; 
  std::cin >> n >> m;
  std::vector<std::vector<int>> matrix(n + 1, std::vector<int>(n + 1, 0));
  for (int i = 1; i <= m; i++)
  {
    std::cin >> a >> b;
    matrix[a][b] = 1;
    matrix[b][a] = 1;
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      std::cout << matrix[i][j];
    }
    std::cout << std::endl;
  }
  */
  // 4 - список смежности в матрицу смежности
  /*
  int n, m, a;
  std::cin >> n;
  std::vector<std::vector<int>> matrix(n + 1, std::vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++)
  {
    std::cin >> m;
    for (int j = 1; j <= m; j++)
    {
      std::cin >> a;
      matrix[i][a] = 1;
    }
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      std::cout << matrix[i][j];
    }
    std::cout << std::endl;
  }
  */
  // 5 - матрица смежности в список ребер
  int n, m = 0;
  char ch;
  std::cin >> n;
  std::vector<std::vector<int>> matrix(n + 1, std::vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
      std::cin>>ch;
      if (ch == '1')
      {
        m++;
        matrix[i][j] = 1;
      }
    }
  std::cout << m / 2 << std::endl;
  for (int i = 1; i <= n; i++)
  {
    for (int j = i; j <= n; j++)
    {
      if(matrix[i][j] == 1)
        std::cout << i << ' ' << j << std::endl;
    }
  }
}