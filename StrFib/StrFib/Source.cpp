#include<iostream>

int main()
{
  /*  строка Фибоначчи-------------------------
  long long n;
  long long fib0[91], fib1[91];
  fib0[1] = 1;
  fib1[1] = 1;
  std::cin >> n;
  if (n == 0) { std::cout << 1; return 0; }
  for (long long i = 1; i < n; i++)
  {
    fib0[i + 1] = fib0[i] + fib1[i];
    fib1[i + 1] = fib0[i];
  }
  std::cout << fib0[n] + fib1[n];
  */
  // строка a b c
  long long n;
  long long oth[50], a[50];
  std::cin >> n;
  if (n == 0) { std::cout << 1; return 0; }
  oth[1] = 2;
  a[1] = 1;
  for (int i = 1; i < n; i++)
  {
    a[i + 1] = oth[i] + a[i];
    oth[i + 1] = oth[i] * 2 + a[i];
  }
  std::cout << a[n] + oth[n];
}