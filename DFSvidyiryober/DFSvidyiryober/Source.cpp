#include<iostream>
#include<vector>
#include<stack>

std::vector<int> ans;
std::vector<int> par;

void dfs(int fst, std::vector<std::vector<int>> &table, std::vector<int> &used)
{
  std::stack<int> st;
  st.push(fst);
  int curr = -1, last = -1;
  //used[fst] = 1;
  while (st.empty() == false)
  {
    curr = st.top();
    st.pop();
    if (used[curr] > 0) continue;
    used[curr] = 1;
    if (curr != fst)
      ans.push_back(table[curr][par[curr]]);
    for (int i = 1; i < table[curr].size(); i++)
    {
      if (used[i] == 0 && table[curr][i] > 0)
      {
        st.push(i);
        par[i] = curr;
        //ans.push_back(table[curr][i]);
      }
    }
  }
}

int main()
{
  int n, m, a, b;
  std::cin >> n >> m;
  std::vector<int> line(n + 1, 0);
  std::vector<int> used(n + 1, 0);
  std::vector<std::vector<int>> table(n + 1, line);
  par.resize(n + 1);
  for (int i = 1; i <= m; i++)
  {
    std::cin >> a >> b;
    table[a][b] = i; 
    table[b][a] = i;
  }
  dfs(1, table, used);
  std::cout << ans.size() << std::endl;
  for (int i = 0; i < ans.size(); i++)
  {
    std::cout << ans[i] << ' ';
  }
}