// первое решение, с bfs-ами от уточек
/*
#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>

inline int to_coord(int i, int j, int m)
{
  return i * ((2 * m + 1) + 1) + j;
}

int deikstr(int fst, int aim, std::vector<std::list<int>>& table, std::vector<int>& dist)
{
  std::list<int>::iterator it;
  std::queue<int> q;
  q.push(fst);
  dist[fst] = 0;
  if (fst == aim) return 0;
  while (!q.empty())
  {
    int curr = q.front();
    q.pop();
    //if (dist[curr] > 0) continue;
    //std::cout << curr << ' ';
    for (it = table[curr].begin(); it != table[curr].end(); it++)
    {
      if (dist[*it] < 0)
      {
        q.push(*it);
        dist[*it] = dist[curr] + 1;
        if (*it == aim) return dist[*it];
      }
    }
  }
  return -1;
}

int main()
{
  int n, m, stock;
  std::cin >> n >> m;
  std::vector<std::list<int>> lst((2 * n + 2) * (2 * m + 2) + 1);
  std::vector<int> used((2 * n + 2) * (2 * m + 2) + 1, -1);
  std::vector<char> line(2 * m + 2);
  std::vector<std::vector<char>> matrix(2 * n + 2, line);
  std::list<int> ducks, ans;
  //std::cin.get();
  for (int i = 1; i <= 2 * n + 1; i++)
  {
    std::cin.get();
    for (int j = 1; j <= 2 * m + 1; j++)
    {
      matrix[i][j] = std::cin.get();
      if (matrix[i][j] == 'D')
        ducks.push_back(to_coord(i, j, m));
      else if (matrix[i][j] == 'S')
        stock = to_coord(i, j, m);
    }
  }
  std::list<int> curr;
  for (int i = 2; i <= 2 * n; i += 2)
  {
    for (int j = 2; j <= 2 * m; j += 2)
    {
      curr.push_back(to_coord(i, j, m));
      if (matrix[i][j + 1] != ' ')
      {
        while (!curr.empty())
        {
          lst[curr.front()].push_back(to_coord(i, j, m));
          curr.pop_front();
        }
      }
    }
    for (int j = 2 * m; j >= 2; j -= 2)
    {
      curr.push_back(to_coord(i, j, m));
      if (matrix[i][j - 1] != ' ')
      {
        while (!curr.empty())
        {
          lst[curr.front()].push_back(to_coord(i, j, m));
          curr.pop_front();
        }
      }
    }
  }
  for (int j = 2; j <= 2 * n; j += 2)
  {
    for (int i = 2; i <= 2 * m; i += 2)
    {
      curr.push_back(to_coord(i, j, m));
      if (matrix[i + 1][j] != ' ')
      {
        while (!curr.empty())
        {
          lst[curr.front()].push_back(to_coord(i, j, m));
          curr.pop_front();
        }
      }
    }
    for (int i = 2 * m; i >= 2; i -= 2)
    {
      curr.push_back(to_coord(i, j, m));
      if (matrix[i - 1][j] != ' ')
      {
        while (!curr.empty())
        {
          lst[curr.front()].push_back(to_coord(i, j, m));
          curr.pop_front();
        }
      }
    }
  }
  while (!ducks.empty())
  {
    if (deikstr(ducks.front(), stock, lst, used) == -1)
    {
      int j = ducks.front() % ((2 * m + 1) + 1);
      int i = (ducks.front() - j) / ((2 * m + 1) + 1);
      matrix[i][j] = ' ';
    }
    used.resize(0);
    used.resize((2 * n + 2) * (2 * m + 2) + 1, -1);
    ducks.pop_front();
  }
  for (int i = 1; i <= 2 * n + 1; i++)
  {
    for (int j = 1; j <= 2 * m + 1; j++)
    {
      std::cout << matrix[i][j];
    }
    std::cout << std::endl;
  }
}
*/
// первое решение, с bfs-ами от уточек


// второе решение, c bfs-ом по реверснутым ребрам от стока
#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>

std::set<int> ducks; 
std::vector<int> ans;

inline int to_coord(int i, int j, int m)
{
  i /= 2;
  j /= 2;
  return (i - 1) * (m + 1) + j;
}

int deikstr(int fst, int aim, std::vector<std::list<int>>& table, std::vector<int>& dist)
{
  std::list<int>::iterator it;
  std::queue<int> q;
  q.push(fst);
  dist[fst] = 0;
  if (fst == aim) return 0;
  while (!q.empty())
  {
    int curr = q.front();
    q.pop();
    //if (dist[curr] > 0) continue;
    //std::cout << curr << ' ';
    for (it = table[curr].begin(); it != table[curr].end(); it++)
    {
      if (dist[*it] < 0)
      {
        q.push(*it);
        dist[*it] = dist[curr] + 1;
        //if (*it == aim) return dist[*it];
        if (ducks.find(*it) != ducks.end()) ans.push_back(*it);
      }
    }
  }
  return -1;
}

int main()
{
  int n, m, stock;
  std::cin >> n >> m;
  std::vector<std::list<int>> rev((n + 1) * (m + 1) + 1);
  //std::vector<std::list<int>> rev;
  std::vector<int> used((n + 1) * (m + 1) + 1, -1);
  std::vector<char> line(2 * m + 2);
  std::vector<std::vector<char>> matrix(2 * n + 2, line);
  //std::cin.get();
  for (int i = 1; i <= 2 * n + 1; i++)
  {
    std::cin.get();
    for (int j = 1; j <= 2 * m + 1; j++)
    {
      matrix[i][j] = std::cin.get();
      if (matrix[i][j] == 'D')
      {
        ducks.insert(to_coord(i, j, m));
        matrix[i][j] = ' ';
      }
      else if (matrix[i][j] == 'S')
        stock = to_coord(i, j, m);
    }
  }
  std::list<int> curr;
  for (int i = 2; i <= 2 * n; i += 2)
  {
    for (int j = 2; j <= 2 * m; j += 2)
    {
      curr.push_back(to_coord(i, j, m));
      if (matrix[i][j + 1] != ' ') 
      {
        while (!curr.empty())
        {
          //lst[curr.front()].push_back(to_coord(i, j, m));
          rev[to_coord(i, j, m)].push_back(curr.front());
          curr.pop_front();
        }
      }
    }
    for (int j = 2 * m; j >= 2; j -= 2)
    {
      curr.push_back(to_coord(i, j, m));
      if (matrix[i][j - 1] != ' ')
      {
        while (!curr.empty())
        {
          //lst[curr.front()].push_back(to_coord(i, j, m));
          rev[to_coord(i, j, m)].push_back(curr.front());
          curr.pop_front();
        }
      }
    }
  }
  for (int j = 2; j <= 2 * n; j += 2)
  {
    for (int i = 2; i <= 2 * m; i += 2)
    {
      curr.push_back(to_coord(i, j, m));
      if (matrix[i + 1][j] != ' ')
      {
        while (!curr.empty())
        {
         // lst[curr.front()].push_back(to_coord(i, j, m));
          rev[to_coord(i, j, m)].push_back(curr.front());
          curr.pop_front();
        }
      }
    }
    for (int i = 2 * m; i >= 2; i -= 2)
    {
      curr.push_back(to_coord(i, j, m));
      if (matrix[i - 1][j] != ' ')
      {
        while (!curr.empty())
        {
          //lst[curr.front()].push_back(to_coord(i, j, m));
          rev[to_coord(i, j, m)].push_back(curr.front());
          curr.pop_front();
        }
      }
    }
  }
  deikstr(stock, -1, rev, used);
  for (int it = 0; it < ans.size(); it++)
  {
    int j = ans[it] % (m + 1);
    int i = (ans[it] - j) / (m + 1) + 1;
    j *= 2;
    i *= 2;
    matrix[i][j] = 'D';
  }
  for (int i = 1; i <= 2 * n + 1; i++)
  {
    for (int j = 1; j <= 2 * m + 1; j++)
    {
      std::cout << matrix[i][j];
    }
    std::cout << std::endl;
  }
}