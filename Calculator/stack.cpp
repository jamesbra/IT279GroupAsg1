#ifndef STACK_H
#define STACK_H

#include "LinkedList.cpp"

template <class T>
class stack
{
  public:
    //default cosntuctor to construct stack
    stack();
    
    //constuctor with an initial data
    stack(T data);
    
    //copy constructor
    stack(const stack& stackObject);
    
    //deconstuctor
    ~stack();
    
    //adds to the to of stack
    void push(T data);
    
    //removes from top of stack
    T pop();
    
    //view the top of the stack
    T peek();
    
    //clear whole stack
    void clear();
    
    //gets the size of the stack
    int getSize();
  private:
    list<T> stackList;
};

template<class T>
stack<T>::stack()
{
  //don't need to do anything
}

template<class T>
stack<T>::stack(T data)
{
  stackList.insert(data);
}


template<class T>
stack<T>::stack(const stack& stackObject)
{ 
  stackList = stackObject.stackList;
}

template<class T>
stack<T>::~stack()
{
  //nothing needs to be done, no dynamic variables in here
}

template<class T>
void stack<T>::push(T data)
{
  stackList.insert(data);
}

template<class T>
T stack<T>::pop()
{
  T temp = stackList[stackList.size -1];
  stackList.remove(stackList.size-1);
  return temp;
}

template<class T>
T stack<T>::peek()
{
  return stackList[stackList.size-1];
}

template<class T>
void stack<T>::clear()
{
  while(stackList.size!=0)
  {
    stackList.remove(stackList.size-1);
  }
}

template<class T>
int stack<T>::getSize()
{
  return stackList.size();
}


#endif