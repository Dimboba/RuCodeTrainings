#include <iostream>
#include <algorithm>
#include <string>

// код не мой, сам доделал только модули
// почему то обосрался с написанием префикса, хотя по идее как все было нормальным
// UPD не додумался до переменной хранящей в себе текущее значение префикса и индексируещго его
using namespace std;


const unsigned int M = 1000000007;
int dp[500001] = { 0 };
string s;
long long ans = 0;
int n, k;

int main()
{
  cin >> n >> k;
  cin >> s;
  if (s[n - 1] == '1')
  {
    cout << 0;
    return 0;
  }
  if (s[0] == '0')
  {
    dp[0] = 1;
  }
  for (int x = 0; x < k; x++)
  {
    if (x == 0)
    {
      ans = dp[x] % M;
      continue;
    }
    if (s[x] == '0')
    {
      dp[x] = ((ans + 1) % M + M) % M;
      ans = ((ans + dp[x]) % M + M) % M;
    }
  }
  for (int i = k; i < n; i++)
  {
    if (s[i] == '0')
    {
      dp[i] = ans;
      ans = ((ans - dp[i - k]) % M + M) % M;
      ans = ((ans + dp[i]) % M + M) % M;
      continue;
    }
    ans = ((ans - dp[i - k]) % M + M) % M;
  }
  cout << dp[n - 1];
}
//прикольный код, сохранил чтобы было
int dp[1000001];
int m = 1e9 + 7;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  dp[0] = 1;
  long long cur = 1;
  for (int i = 1; i <= n; i++) {
    if (i > k) cur -= dp[i - 1 - k];
    if (cur < 0) cur += m;
    if (s[i - 1] == '0') dp[i] = cur;
    cur += dp[i];
    cur %= m;
  }
  cout << dp[n] << endl;
  return 0;
}