#include<fstream>
#include<iostream>

bool check(int mid, int* mass, int val)
{
  if (mass[mid] <= val) return true;
  return false;
}

int lbinsearch(int left, int right, int* mass, int val)
{
  while (left < right)
  {
    int mid = (left + right) / 2;
    if (check(mid, mass, val))
    {
      right = mid;
    }
    else
    {
      left = mid + 1;
    }
  }
  return left+1;
}
int rbinsearch(int left, int right, int* mass, int val)
{
  while (left < right)
  {
    int mid = (left + right + 1) / 2;
    if (check(mid, mass, val))
    {
      left = mid;
    }
    else
    {
      right = mid - 1;
    }
  }
  return left+1;
}
int main()
{
 // std::ifstream fin("input.txt", std::ios::in);
  int n, m, in;
  std::cin >> n >> m;
  int* mass = new int[n];
  for (int i = 0; i < n; i++)
  {
    std::cin >> mass[i];
  }
  for (int i = 0; i < m; i++)
  {
    std::cin >> in;
    if (in < mass[n-1]) { std::cout << "NO SOLUTION" << '\n'; continue; }
    std::cout << lbinsearch(0, n - 1, mass, in) << std::endl;/*
    if (in == lbinsearch(0, n - 1, mass, in))
      std::cout << "YES";
    else
      std::cout << "NO";
    std::cout << std::endl; */
  }
}