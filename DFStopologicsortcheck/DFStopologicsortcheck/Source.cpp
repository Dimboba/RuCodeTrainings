#include<iostream>
#include<vector>
#include<set>
#include<stack>
#include<list>


bool dfs_check_cycle(int fst, std::vector<std::list<int>> table, std::vector<int> used)
{
  int curr = fst;
  std::stack<int> st;
  std::list<int>::iterator it;
  std::vector<int> last(used.size());
  st.push(curr);
  while (st.empty() == false)
  {
    curr = st.top();
    if (used[curr] == 1) used[curr] = 2;
    if (used[curr] != 0) 
    {
      st.pop(); continue;
    }
    used[curr] = 1;
    for (it = table[curr].begin(); it != table[curr].end(); it++)
    {
      if (used[*it] == 0)
      {
        st.push(*it);
        last[*it] = curr;
      }
      else if (used[*it] == 1)
      {
        last[*it] = curr;
        return true;
      }
    }
  }
  return false;
}

int main()
{
  int n, m, a, b;
  std::cin >> n >> m;
  std::set<int> curr;
  std::vector<int> used(n + 1, 0);
  std::vector<int> topologic(n + 1, 0);
  std::list<int>::iterator it;
  std::vector<std::list<int>> lst(n + 1);
  for (int i = 0; i < m; i++)
  {
    std::cin >> a >> b;
    lst[a].push_back(b);
    if (a == b) // проверяет "одиночные" петли, остальные петли и так проверятся
    {
      std::cout << "NO";
      return 0;
    }
  }
  for (int i = 1; i <= n; i++)
  {
    //if (dfs_check_cycle(i, lst, used)) { std::cout << "NO"; return 0; } // вылетело по времени, но верно по идее
    std::cin >> topologic[i];
  }
  for (int i = n; i > 0; i--)
  {
    int nw = topologic[i];
    curr.insert(nw);
    for (it = lst[nw].begin(); it != lst[nw].end(); it++)
    {
      if (curr.find(*it) == curr.end())
      {
        std::cout << "NO";
        return 0;
      }
    }
  }
  std::cout << "YES";
}