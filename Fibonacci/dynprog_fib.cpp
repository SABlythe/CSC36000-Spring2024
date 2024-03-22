#include <iostream>

using namespace std;

#define MAXVAL 10000
long unsigned int M[MAXVAL];

long unsigned int fibo(unsigned int n)
{
  M[0] = 1;
  M[1] = 1;

  for (unsigned int index=2; index <= n; index++)
    M[index] = M[index-1] + M[index-2];

  return M[n];
}

int main(int argc, char *argv[])
{
  for (int index=0; index<MAXVAL; index++)
    M[index]=0;
  
  int num;
  cout << "What is n? ";
  cin >> num;
  cout << fibo(num) << endl;

  return 0;
}
