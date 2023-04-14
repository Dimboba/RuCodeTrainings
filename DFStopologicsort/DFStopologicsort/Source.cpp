#include<iostream>
#include<vector>
#include<set>
#include<stack>
#include<list>

std::stack<int> ans;

bool dfs(int fst, std::vector<std::list<int>>& table, std::vector<int>& used)
{
  // used == 0 - белая, -1 серая, 1 черная
  std::vector<int> last(used.size());
  std::list<int>::iterator it;
  std::stack<int> st;
  st.push(fst);
  int curr = fst;
  //used[fst] = 1;
  while (st.empty() == false)
  {
    curr = st.top();
    if (used[curr] == -1) // вернулись в серую вершину - сток
    {
      ans.push(curr);
    }
    if (used[curr] == -1 || used[curr] == 1) st.pop();
    if (used[curr] == -1) used[curr] = 1;
    if (used[curr] == 1) continue;
    used[curr] = -1;
    for (it = table[curr].begin(); it != table[curr].end(); it++)
    {
      if (used[*it] == 0)
      {
        st.push(*it);
        last[*it] = curr;
      }
      //      else if (used[*it] == -1 && *it != last[curr]) //для неориентированных
      else if (used[*it] == -1)
      {
        last[*it] = curr; // для цикла включающий корень
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
  std::vector<int> used(n + 1, 0);
  std::vector<std::list<int>> lst(n + 1);
  for (int i = 0; i < m; i++)
  {
    std::cin >> a >> b;
    lst[a].push_back(b);
    /*
    if (a == b)
    {
      std::cout << "YES" << std::endl << 1 << std::endl << a;
      return 0;
    }
    */
    //lst[b].push_back(a);// - для неориентированных
  }
  for (int i = 1; i <= n; i++)
  {
    //if (used[i] != 0) continue;
    if (dfs(i, lst, used))
    {
      std::cout << "NO";
      return 0;
    }
  }
  std::cout << "YES" << std::endl;
  while(ans.empty() == false)
  {
    std::cout << ans.top() << ' ';
    ans.pop();
  }

}