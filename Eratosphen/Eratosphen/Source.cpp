#include<iostream>

int main()
{
  int n;
  std::cin >> n;
  int* mass = new int[n + 1];
  for (int i = 0; i < n + 1; i++) mass[i] = 0;
  for (int i = 2; i < n + 1; i++)
  {
    if (mass[i] == 0)
      for (int j = i; (long long) j * i < n + 1; j += 1) // ��������� ������� ������� � �������� ��� ��������� �� ���� ������� � ��� ��������
      {
        if(mass[j * i] == 0) // ����� ������ �� ���������� ���� ������� �������� (���������� ������� �� ���������)
          mass[j * i] = i;
      }
  }
  long long ans = 0;
  for (int i = 2; i < n + 1; i++)
  {
    //std::cout << mass[i] << ' ';
    ans += mass[i];
  }
  std::cout << ans;
}