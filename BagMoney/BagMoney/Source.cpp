#include<stack>
#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
  int W, n, inf = 1e6;
  std::cin >> W >> n;
  std::vector<int> weight(n + 1), price(n + 1), line(W + 1, inf * (-1));
  for (int i = 1; i <= n; i++)
    std::cin >> weight[i];
  for (int i = 1; i <= n; i++)
    std::cin >> price[i];
  std::vector<std::vector<int>> dp(n + 1, line);
  dp[0][0] = 0;
  for (int i = 1; i < n + 1; i++)
  {
    for (int w = 0; w <= W; w++)
    {
      if (weight[i] <= w)
      {
        dp[i][w] = std::max(dp[i - 1][w], (dp[i - 1][w - weight[i]] + price[i]));
      }
      else 
        dp[i][w] = dp[i - 1][w];
      //std::cout << dp[i][w] << ' ';
    }
    //std::cout << std::endl;
  }
  int max = 0;
  std::stack<int> st;
  std::pair<int, int> curr;
  curr.first = n;
  for (int i = 0; i <= W; i++)
  {
    if (max < dp[n][i])
    {
      max = dp[n][i];
      curr.second = i;
    }
  }
  int i, w;
  while (true)
  {
    //st.push(curr);
    i = curr.first;
    w = curr.second;
    if (i == 0) break;
    //std::cout << '!' << i << ' ' << w << ' ' << weight[i] << std::endl;
    if ((w - weight[i] >= 0) && dp[i - 1][w - weight[i]] + price[i] == dp[i][w])
    {
      curr.first = i - 1;
      curr.second = w - weight[i];
      st.push(i);
    }
    else //можно было входить в этот else через if: dp[i][w] == dp[i-1][w] было бы проще, но тут чисто тестил
    {
      curr.first = i - 1;
      curr.second = w;
    }
  }
  std::cout << max << ' ' << st.size() << std::endl;
  while (st.empty() == false)
  {
    std::cout << st.top() << ' ';
    st.pop();
  }
}