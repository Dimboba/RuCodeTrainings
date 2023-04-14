#include<iostream>
#include<vector>
#include<queue>
#include<list>

void bfs(int fst, std::vector<std::list<int>>& table, std::vector<int>& dist)
{
  std::list<int>::iterator it;
  std::queue<int> q;
  q.push(fst);
  dist[fst] = 0;
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
      }
    }
  }
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  std::vector<int> used(n + 1, -1);
  std::vector<std::list<int>> lst(n + 1);
  for (int i = 1; i <= m; i++)
  {
    int a, b;
    std::cin >> a >> b;
    lst[a].push_back(b);
    lst[b].push_back(a);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    used.resize(0);
    used.resize(n + 1, -1);
    bfs(i, lst, used);
    for (int j = 1; j <= n; j++)
      ans += used[j];
  }
  std::cout << ans / 2; // так как каждое ребро посчитано дважды
}