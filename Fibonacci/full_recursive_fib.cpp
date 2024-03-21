#include <iostream>

using namespace std;

long unsigned int fibo(unsigned int n)
{
  long unsigned int answer;
  if (n<=1) 
    answer = 1;
  else
    answer = fibo(n-1) + fibo(n-2);

  return answer;
}

int main(int argc, char *argv[])
{
  int num;
  cout << "What is n? ";
  cin >> num;
  cout << fibo(num) << endl;

  return 0;
}
