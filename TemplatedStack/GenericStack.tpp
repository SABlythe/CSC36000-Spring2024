#include "GenericStack.hpp"

#include <iostream>
#include <string>

using namespace std;

// implement the methods from Stack class here !!!
template <class T>
void
Stack<T>::push (const T &str)
{
  push_front(str);
}

template <class T>
T
Stack<T>::pop()
{
  if (!isEmpty())
    {
      T firstVal = front();
      pop_front();
      return firstVal;
    }

  // if we get here, stack is empty!
  cerr << "Attempt to pop an empty stack!" << endl;
  return ">>>>ERROR - EMPTY STACK POP<<<<";
}

template <class T>
bool
Stack<T>::isEmpty() const
{
  return empty();
}
