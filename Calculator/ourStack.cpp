#ifndef OURSTACK_H
#define OURSTACK_H

#include "LinkedList.cpp"

template <class T>
class ourStack
{
  public:
    //default cosntuctor to construct stack
    ourStack();
    
    //constuctor with an initial data
    ourStack(T data);
    
    //copy constructor
    ourStack(const ourStack& stackObject);
    
    //deconstuctor
    ~ourStack();
    
    //adds to the to of stack
    void push(T data);
    
    //removes from top of stack
    T pop();
    
    //view the top of the stack
    T peek();
    
    //clear whole stack
    void clear();
    
    //gets the getSize() of the stack
    int getSize();
  private:
    list<T> stackList;
};

template<class T>
ourStack<T>::ourStack()
{
  //don't need to do anything
}

template<class T>
ourStack<T>::ourStack(T data)
{
  stackList.insert(data);
}


template<class T>
ourStack<T>::ourStack(const ourStack& stackObject)
{ 
  stackList = stackObject.stackList;
}

template<class T>
ourStack<T>::~ourStack()
{
  //nothing needs to be done, no dynamic variables in here
}

template<class T>
void ourStack<T>::push(T data)
{
  stackList.insert(data);
}

template<class T>
T ourStack<T>::pop()
{
  T temp = stackList[stackList.getSize() -1];
  stackList.remove(stackList.getSize()-1);
  return temp;
}

template<class T>
T ourStack<T>::peek()
{
  return stackList[stackList.getSize()-1];
}

template<class T>
void ourStack<T>::clear()
{
  while(stackList.getSize()!=0)
  {
    stackList.remove(stackList.getSize()-1);
  }
}

template<class T>
int ourStack<T>::getSize()
{
  return stackList.getSize();
}


#endif