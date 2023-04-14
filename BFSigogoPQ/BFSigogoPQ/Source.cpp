#include<iostream>
#include<vector>
#include<queue>
#include<list>

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
  int n, m, p, q, x1, y1, x2, y2;
  std::cin >> m >> n >> p >> q >> x1 >> y1 >> x2 >> y2;
  std::vector<int> dist((n + 1) * (m + 1) + 1, -1);
  std::vector<std::list<int>> lst((n + 1) * (m + 1) + 1);
  int difX[8] = { p, p, -p, -p, q, q, -q, -q };
  int difY[8] = { q, -q, q, -q, p, -p, p, -p };
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      for (int k = 0; k < 8; k++)
      {
        int newX = i + difX[k];
        int newY = j + difY[k];
        if (newX > 0 && newX <= m && newY > 0 && newY <= n)
        {
          lst[i * (n + 1) + j].push_back(newX * (n + 1) + newY);
        }
      }
    }
  }
  int ans = 0;
  std::cout << deikstr(x1 * (n + 1) + y1, x2 * (n + 1) + y2, lst, dist);
}