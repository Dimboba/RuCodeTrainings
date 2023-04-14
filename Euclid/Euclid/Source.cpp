#include<iostream>
#include<cmath>
int times = 0;

long long euclid(long long a, long long b)
{
  if (a < b) return euclid(b, a);
  if (b == 0) return a;
  times++;
  return (euclid(a % b, b));
}

int main() 
{
  /* 1 и 2 задачи-------------------------------------------
  int a, b, c, cmd;
  std::cin >> a >> b >> c;
  cmd = euclid(abs(a), abs(b));
  if (c % cmd == 0) { std::cout << 1;  return 0; }
  std::cout << 0;
  //std::cout << times;
  */
  /* 3 задача--------------------------------------
  int n, nw, ans;
  std::cin >> n;
  std::cin >> ans;
  for (int i = 1; i < n; i++)
  {
    std::cin >> nw;
    ans = euclid(ans, nw);
  }
  std::cout << ans;
  */
  long long a, b, cmd, a1, b1;
  unsigned long long res; // можно без unsigned long long тогда в качестве проверки лучше использовать:
  std::cin >> a >> b; // a > (1e18)/b1 (чтобы избежать переполнения переходим в плав. арифметику)
  cmd = euclid(a, b);
  a1 = a / cmd;
  b1 = b / cmd;
  res = a1 * b1 * cmd;
  if (res > 1e18) { std::cout << -1; return 0; }
  std::cout << res;
}