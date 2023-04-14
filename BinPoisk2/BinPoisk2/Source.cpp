#include<iostream>
#include<fstream>
#include<algorithm>

class fun
{
public:
  int* coef;
  int power;
  fun(int n, int* coef1)
  {
    power = n;
    coef = new int[n+1];
    coef = coef1;
  }
  long double value(long double x)
  {
    long double ans = 0.0;
    for (int i = 0; i < power + 1; i++)
    {
      ans += coef[i] * pow(x, power - i);
    }
    return ans;
  }
};

bool check(long double mid, fun f)
{
  if (f.value(mid) < 0) // если бы первое число могло быть отрицательным пришлось бы здесь поебаться
    return true;
  return false;
}

long double binsearch(long double left, long double right, long double eps, fun f)
{
  while (right - left > eps)
  {
    long double mid = (left + right) / 2;
    if (check(mid, f))
    {
      left = mid;
    }
    else
    {
      right = mid;
    }
  }
  return (left + right) / 2;
}

int main()
{
  std::cout.precision(16);
  int n;
  std::cin >> n;
  int* coef = new int[n + 1];
  for (int i = 0; i < n + 1; i++)
    std::cin >> coef[i];
  fun f(n, coef);
  std::cout<<binsearch(-1000, 1000, 1e-9, f);
}