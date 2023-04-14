#include<iostream>

class modArithm
{
private:
  long long mod;
  long long val;
  // x1 и y1 соотвественно станут минимальными решениями для уравнения вида ax + by = НОД(a, b)
  // сам код выведет НОД
  static long long exteuclid(long long r1, long long r2, long long& x1, 
    long long& y1, long long& x2, long long& y2, bool first)
  {
    if (r1 < r2) exteuclid(r2, r1, y1, x1, y2, x2, first);
    if (first == true)
    {
      x1 = 1;
      y1 = 0;
      x2 = 0;
      y2 = 1;
    }
    if (r2 == 0) return r1;
    long long d = r1 / r2;
    long long x = x1 - d * x2;
    long long y = y1 - d * y2;
    y1 = y2; x1 = x2; y2 = y; x2 = x;
    return exteuclid(r2, r1 % r2, x1, y1, x2, y2, false);
  }
public:
  modArithm(long long val1, long long mod1):mod(mod1)
  {
    val = ((val1 % mod) + mod) % mod;
    if (mod == -1)
      val = -1;
  }
  modArithm() :mod(1), val(0) {}
  friend modArithm operator+(modArithm& left, modArithm& right)
  {
    if (left.mod != right.mod)
      return modArithm(-1, -1);
    return modArithm(left.val + right.val, left.mod);
  }
  friend modArithm operator-(modArithm& left, modArithm& right)
  {
    if (left.mod != right.mod)
      return modArithm(-1, -1);
    return modArithm(left.val - right.val, left.mod);
  }
  friend modArithm operator*(modArithm& left, modArithm& right)
  {
    if (left.mod != right.mod)
      return modArithm(-1, -1);
    return modArithm(left.val * right.val, left.mod);
  }
 
  static modArithm pow(modArithm& a, int b)
  {
    if (b == 0) return modArithm(1, a.mod);
    if (b % 2 == 0)
    {
      modArithm c = pow(a, b / 2);
      return c * c;
    }
    else 
    { 
      modArithm c = pow(a, b - 1);
      return c * a;
    }
  }
  friend modArithm operator/(modArithm& num, modArithm& den)
  {
    if (num.mod != den.mod)
      return modArithm(-1, -1);
    long long x1, y1, x2, y2;
    long long cmd = exteuclid(den.val, den.mod, x1, y1, x2, y2, true);
    if (num.val % cmd != 0) return modArithm(-1, -1);
    modArithm den1(num.val / cmd, num.mod);
    modArithm x(x1, num.mod);
    return den1 * x;
  }
  inline long long getval() { return val; }
};

int main()
{
  //  1 задача-------------------------------------
  /* 
  int n, mod = 1e6 + 3;
  std::cin >> n;
  modArithm* fib =  new modArithm[n + 1];
  fib[0] = modArithm(1, mod);
  fib[1] = modArithm(1, mod);
  for (int i = 2; i < n + 1; i++)
  {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  std::cout << fib[n].getval();
  */
  // 2 задача-------------------------------------
  /*
  int a, b, mod = 1e6 + 7;
  std::cin >> a >> b;
  modArithm a1(a, mod);
  modArithm b1(b, mod);
  modArithm A1 = a1 * a1;
  modArithm B1 = b1 * b1;
  std::cout << (A1 - B1).getval();
  */
  // 3 задача------------------------------------
  /*
  int n, mod = 1e6 + 3;
  std::cin >> n;
  modArithm ans(1, mod);
  if (n >= mod) { std::cout << 0; return 0; }
  for (int i = 1; i < n + 1; i++)
  {
    modArithm I(i, mod);
    ans = ans * I;
  }
  std::cout << ans.getval();
  */
  // 4 задача------------------------------------
  /*
  int n, mod, a;
  std::cin >> n >> mod;
  modArithm* coef = new modArithm[n + 1];
  for (int i = 0; i < n + 1; i++)
  {
    std::cin >> a;
    modArithm aboba(a, mod);
    coef[i] = aboba;
  }
  for (int i = 0; i < mod; i++)
  {
    modArithm I(i, mod);
    modArithm ans(0, mod);
    for (int j = 0; j < n + 1; j++)
    {
      modArithm K = modArithm::pow(I, n - j);
      modArithm ans2 = coef[j] * K;
      ans = ans + ans2;
    }
    if (ans.getval() == 0) { std::cout << i; return 0; }
  }
  std::cout << -1;
  */
  // 5 задача------------------------------------
  /*
  int n, m;
  std::cin >> n >> m;
  modArithm N(n, m);
  N = modArithm::pow(N, n);
  std::cout << N.getval();
  */
  // 6 задача------------------------------------
  /*
  long long a, b, c, d;
  long long mod = 1e9 + 7;
  std::cin >> a >> b >> c >> d;
  modArithm A(a, mod);
  modArithm B(b, mod);
  modArithm C(c, mod);
  modArithm D(d, mod);
  A = A * D;
  C = C * B;
  A = A + C;
  B = B * D;
  A = A / B;
  std::cout << A.getval();
  */
  // 7 задача------------------------------------
  /*
  long long a, n, mod;
  std::cin >> a >> n >> mod;
  modArithm A(a, mod);
  modArithm N(n, mod);
  modArithm Ans(0, mod), Aden;
  for (int i = 1; i <= n; i++)
  {
    modArithm I(i, mod);
    Aden = modArithm::pow(A, i);
    Aden = I / Aden;
    //if (Aden.getval() == -1) { std::cout << -1; return 0; }
    Ans = Aden + Ans;
  }
  std::cout << Ans.getval();
  */
  // 8 задача------------------------------------
  /*
  long long n, m, l, mod = 1e9 + 7;
  std::cin >> n >> m >> l;
  modArithm Ans(0, mod), C, den;
  modArithm* fac = new modArithm[n + 1];
  fac[0] = modArithm(1, mod);
  for (long long i = 1; i <= n; i++)
  {
    modArithm I(i, mod);
    fac[i] = fac[i - 1] * I;
  }

  for (long long k = 1; k <= l; k++)
  {
    if (n < m * k) continue;
    den = fac[n - m * k] * fac[m * k];
    C = fac[n] / den;
    Ans = Ans + C;
  }
  std::cout << Ans.getval();
  */
}