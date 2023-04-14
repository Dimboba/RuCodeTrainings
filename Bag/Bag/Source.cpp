#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

int main()
{
  int n, s;
  std::cin >> s >> n;
  std::vector<std::pair<int, int>> weight(n + 1);
  std::stack<int>* st = new std::stack<int>[s+1];
  for (int i = 1; i < n + 1; i++)
  {
    std::cin >> weight[i].first;
    weight[i].second = i;
  }
  //std::sort(weight.begin(), weight.end());
  std::vector<bool> line(s + 1, 0);
  std::vector <std::vector <bool>> dp(n + 1, line);
  //for (int i = 1; i <= n; i++) dp[0][i] = 0;
  dp[0][0] = 1;
  for(int i = 1; i <= n; i++)
    for (int j = s; j >= 0; j--)
    {
      if (weight[i].first <= j)
      {
        dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - weight[i].first]);
        if (dp[i - 1][j - weight[i].first] == true) 
        {
          st[j] = st[j - weight[i].first];
          st[j].push(weight[i].second);
          //std::cout << i << ' ' << j << ' ' << weight[i].second << std::endl;
        }
      }
      else
      {
        dp[i][j] = dp[i - 1][j];
      }
    }
  //std::vector<int> buff;
  for(int i = s; i >= 0; i--)
    if (dp[n][i] == 1) 
    { 
      std::cout << i << ' ' << st[i].size() << std::endl;
      while (st[i].empty() == false)
      {
        //buff.push_back(st[i].top());
        std::cout << st[i].top() << ' ';
        st[i].pop();
      }
      return 0; 
    }
 // sort(buff.begin(), buff.end());
  //for (int i = 0; i < buff.size(); i++)
   // std::cout << buff[i] << ' ';
  //std::cout<<std::endl;
}