#include "GenericStack.hpp"

#include <iostream>
#include <string>

using namespace std;

// implement the methods from Stack class here !!!
template <class T>
void
Stack<T>::push (const T &str)
{
  list<T>::push_front(str);
}

template <class T>
T
Stack<T>::pop()
{
  //  if (!isEmpty())
  //    {
      T firstVal = list<T>::front();
      list<T>::pop_front();
      return firstVal;
  //    }
 

  // if we get here, stack is empty!
  //cerr << "Attempt to pop an empty stack!" << endl;
 
  //T dummyVal;
  //return dummyVal;
}

template <class T>
bool
Stack<T>::isEmpty() const
{
  return list<T>::empty();
}
