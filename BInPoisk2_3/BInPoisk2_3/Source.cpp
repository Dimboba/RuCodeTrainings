#include<iostream>
#include<fstream>
#include<cmath>

int check(int* st, int ans, int n, int k)
{
  int last = - ans - 1;
  for (int i = 0; i < n; i++)
  {
    if (st[i] - last >= ans)
    {
      k--;
      last = st[i];
    }
  }
  if (k <= 0)
    return true;
  else
    return false;
}

bool check2(int* ropes, int ans, int n, int k)
{
  for (int i = 0; i < n; i++)
  {
    k -= ropes[i] / ans;
  }
  if (k <= 0)
    return true;
  return false;
}

int rbinsearch(int left, int right, int* stoils, int n, int k)
{
  while (right > left)
  {
    int mid = (right + left + 1) / 2;
    if (check2(stoils, mid, n, k))
    {
      left = mid;
    }
    else
    {
      right = mid - 1;
    }
  }
  return left;
}

int main()
{
  std::cout.precision(16);
  int ans, n, k, mx = -1;
  int* ropes;
  std::cin >> n >> k;
  ropes = new int[n];
  for (int i = 0; i < n; i++)
  {
    std::cin >> ropes[i];
    if (mx < ropes[i]) mx = ropes[i];
  }
  std::cout << rbinsearch(0, mx, ropes, n, k);;
}