#include<iostream>
#include<vector>
#include<stack>
#include<list>
#include<iterator>

int l = 0;

void dfs(int fst, std::vector < std::list<int>> &lst, std::vector<int>& used)
{
  std::stack<int> st;
  std::list<int>::iterator it;
  st.push(fst);
  if (used[fst] == 0) l++;
  while (st.empty() == false)
  {
    int curr = st.top();
    st.pop();
    if (used[curr] > 0) continue;
    used[curr] = l;
    for (it = lst[curr].begin(); it != lst[curr].end(); it++)
    {
      if (used[*it] == 0)
      {
        st.push(*it);
        //std::cout << curr << ' ';
      }
    }
  }
}

void dfs_rec(int curr, std::vector<std::list<int>>& lst, std::vector<int> &used)
{
  std::list<int>::iterator it;
  used[curr] = l;
 //std::cout << curr << ' ';
 // ans.push(curr);
  for (it = lst[curr].begin(); it != lst[curr].end(); it++)
  {
    if (used[*it] == 0)
    {
      dfs_rec(*it, lst, used);
   //   ans.push(curr);
    }
  }
}

int main()
{
  int n, m, a, b;
  std::cin >> n >> m;
  std::vector<std::list<int>> lst(n + 1);
  std::vector<int> used(lst.size(), 0);
  for (int i = 1; i <= m; i++)
  {
    std::cin >> a >> b;
    lst[a].push_back(b);
    lst[b].push_back(a);
  }
  for (int i = 1; i <= n; i++)
  {
    dfs(i, lst, used);
  }
  std::cout << l << std::endl;
  for (int i = 1; i <= n; i++)
  {
    std::cout << used[i] << ' ';
  }
}