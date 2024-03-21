#include <iostream>

using namespace std;

#define MAXVAL 10000
long int M[MAXVAL];

long int fibo(unsigned int n)
{
  // havent solved this subproblem yet ....
  if (M[n] == 0)
    { 
      if (n<=1)
	M[n] =  1;
      
      else
	M[n] =  fibo(n-1) + fibo(n-2);
    }

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
