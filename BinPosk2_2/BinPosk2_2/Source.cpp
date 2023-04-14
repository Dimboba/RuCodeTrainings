#include<iostream>
#include<fstream>
#include<cmath>

class fun 
{
public:
  int Cx, Cy, Cd;
  int n;
  int* coef;
  fun(int Cx, int Cy, int Cd, int n, int* coef):Cx(Cx), Cy(Cy), Cd(Cd), n(n), coef(coef) {}
  double val(double x)
  {
    double ans = 0;
    int sigh = 1;
    for (int i = 0; i < n + 1; i++)
    {
      ans += pow(x, n - i) * coef[i];
    }
    if (ans == Cy) return 0.0;
    double dy = sqrt((Cd * Cd) - (x - Cx) * (x - Cx));
    if (ans < Cy + dy && ans > Cy - dy) return -1;
    return 1;
  }
  
};

double binsearch(double left, double right, double eps, fun f)
{
  while (right - left > eps)
  {
    double mid = (right + left) / 2;
    if (f.val(mid) > 0)
    {
      right = mid;
    }
    else
    {
      left = mid;
    }
  }
  return (right + left) / 2;
}

int main()
{
  std::cout.precision(16);
  int Cx, Cy, Cd;
  int n, x;
  int* coef;
  std::cin >> Cx >> Cy >> Cd;
  std::cin >> n;
  coef = new int[n + 1];
  for (int i = 0; i < n + 1; i++)
    std::cin >> coef[i];
  std::cin >> x;
  fun f(Cx, Cy, Cd, n, coef);
  std::cout << binsearch(x, (int)Cx + Cd, 1e-12, f);
}