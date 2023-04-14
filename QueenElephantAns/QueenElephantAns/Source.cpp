#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

int main()
{
  long long n, m, a;
  long long const inf = 1e9;
  std::cin >> n >> m;
  std::vector<long long> line(m + 1, 1e18);
  std::vector<std::pair<long long, long long>> linepair(m + 1, std::pair<long long, long long>(0, 0));
  std::vector<std::vector<long long>> table(n + 1, line);
  std::vector<std::vector<std::pair<long long, long long>>> last(n + 1, linepair);

  std::vector<long long> minJind(m + 1, 1e18);
  std::vector<long long> minIind(n + 1, 1e18);
  std::vector<long long> minDind(n + m + 1, 1e18);

  std::vector<long long> minJ(m + 1, 1e18);
  std::vector<long long> minI(n + 1, 1e18);
  std::vector<long long> minD(m + n + 2, 1e18);

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      std::cin >> table[i][j];
    }
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (i != 1 || j != 1)
      {
        long long mn = std::min(std::min(minI[i], minJ[j]), minD[i-j+m]);
        table[i][j] += mn;
        if (mn == minI[i])
        {
          last[i][j].first = i;
          last[i][j].second = minIind[i];
        }
        else if(mn == minJ[j])
        {
          last[i][j].first = minJind[j];
          last[i][j].second = j;
        }
        else
        {
          last[i][j].first = minDind[i - j + m];
          last[i][j].second =minDind[i - j + m] - i + j;
        }
      }
      if (table[i][j] < minI[i])
      {
        minI[i] = table[i][j];
        minIind[i] = j;
      }
      if (table[i][j] < minJ[j])
      {
        minJ[j] = table[i][j];
        minJind[j] = i;
      }
      if (table[i][j] < minD[i - j + m])
      {
        minD[i - j + m] = table[i][j];
        minDind[i - j + m] = i;
      }
    }
  }
  /*
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      std::cout << table[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  */
  // тут ниче не вышло с запоминанием откуда пришли через last(( upd все было норм, обосрался с логическими И ИЛИ
  
  long long I = n, J = m, q = 0;
  std::pair<long long, long long> curr;
  std::stack<long long> stI, stJ;
  while (true)
  {
    q++;
    stI.push(I); stJ.push(J);
    if (I == 1 && J == 1) break;
    curr = last[I][J];
    I = curr.first;
    J = curr.second;
    
  }
  std::cout << table[n][m] << ' ' << q <<std::endl;
  while (stI.empty() == false)
  {
    std::cout << stI.top() << ' ' << stJ.top() << std::endl;
    stI.pop(); stJ.pop();
  }
  
  /*
  long long I = n, J = m, q = 0, mn = 1e18;
  std::stack<long long> stI, stJ;
  while (true)
  {
    long long nextI = 0, nextJ = 0, nextK = std::min(I, J);
    mn = 1e18;
    q++;
    stI.push(I); stJ.push(J);
    if (I == 1 && J == 1) break;
    for (int i = 1; i < I; i++)
    {
      if (table[i][J] < mn)
      {
        mn = table[i][J];
        nextI = i;
      }
    }
    mn = 1e18;
    for (int j = 1; j < J; j++)
    {
      if (table[I][j] < mn)
      {
        mn = table[I][j];
        nextJ = j;
      }
    }
    mn = 1e18;
    long long k = 1;
    while (I - k > 0 && J - k > 0)
    {
      if (table[I - k][J - k] < mn)
      {
        mn = table[I - k][J - k];
        nextK = k;
      }
      k++;
    }
    mn = std::min(std::min(table[I][nextJ], table[nextI][J]), table[I - nextK][J - nextK]);
    if (mn == table[I][nextJ])
    {
      J = nextJ;
    }
    else if(mn == table[nextI][J])
    {
      I = nextI;
    }
    else
    {
      I -= nextK;
      J -= nextK;
    }
    //q++;
  }
  std::cout << table[n][m] << ' ' << q << std::endl;
  while (stI.empty() == false)
  {
    std::cout << stI.top() << ' ' << stJ.top() << std::endl;
    stI.pop(); stJ.pop();
  }
  */
}