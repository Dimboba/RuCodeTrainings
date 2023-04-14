#include<iostream>
#include<vector>
#include<stack>
#include<set>

std::set<int> allowed;

bool dfs(int fst, std::vector<std::vector<int>>& table, std::vector<int>& used)
{
  std::set<int> new_allowed = allowed;
  // used == 0 - белая, -1 серая, 1 черная 
  std::stack<int> st;
  st.push(fst);
  int curr = fst, last = -1;
  //used[fst] = 1;
  while (st.empty() == false)
  {
    curr = st.top();
    if (used[curr] == -1 || used[curr] == 1) st.pop();
    if (used[curr] == -1) used[curr] = 1;
    if (used[curr] == 1) continue;
    used[curr] = -1;
    for (int i = 1; i < table[curr].size(); i++)
    {
      if (used[i] == 0 && new_allowed.find(table[curr][i]) != new_allowed.end())
      {
        st.push(i);
        //new_allowed.erase(new_allowed.find(table[curr][i]));
        //ans.push_back(table[curr][i]);
      }
      else if (used[i] == 1 && table[curr][i] > 0)
        return false;
    }
  }
  //if (new_allowed.empty() == false) return false;
  return true;
}
int main()
{
  int n, m, a, b, q;
  std::cin >> n >> m;
  std::vector<int> line(n + 1, 0);
  std::vector<int> used(n + 1, 0);
  std::vector<std::vector<int>> table(n + 1, line);
  for (int i = 1; i <= m; i++)
  {
    std::cin >> a >> b;
    table[a][b] = i;
    table[b][a] = i;
  }
  std::cin >> q;
  if (q != n - 1)
  {
    std::cout << "NO";
    return 0;
  }
  for (int i = 1; i <= q; i++)
  {
    std::cin >> a;
    allowed.insert(a);
  }
  bool allused = true;
  for (int i = 1; i <= n; i++)
  {
    allused = true;
    used.resize(0);
    used.resize(n + 1, 0);
    if (dfs(i, table, used))
    {
      for (int j = 1; j <= n; j++)
        if (used[j] != 1) allused = false;
      if (allused == false) continue;
      std::cout << "YES";
      //std::cout << i;
      return 0;
    }
    //else std::cout << "NO";
  }
  std::cout << "NO";
}