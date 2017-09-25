#ifndef OURSTACK_H
#define OURSTACK_H

#include "LinkedList.cpp"

template <class T>
class ourQueue
{
  public:
    //default cosntuctor to construct stack
    ourQueue();
    
    //copy constructor
    ourQueue(const ourQueue& stackObject);
    
    //deconstuctor
    ~ourQueue();
    
    //adds to the to of stack
    void enqueue(T data);
    
    //removes from top of stack
    T dequeue();

    T front();
    
    //clear whole stack
    void clear();
    
    //gets the getSize() of the stack
    int size();
  private:
    list<T> stackList;
};

template<class T>
ourQueue<T>::ourQueue()
{
  //don't need to do anything
}

template<class T>
ourQueue<T>::ourQueue(T data)
{
  stackList.insert(data);
}


template<class T>
ourQueue<T>::ourQueue(const ourQueue& stackObject)
{ 
  stackList = stackObject.stackList;
}

template<class T>
ourQueue<T>::~ourQueue()
{
  //nothing needs to be done, no dynamic variables in here
}

template<class T>
void ourQueue<T>::enqueue(T data)
{
  stackList.insert(data);
}

template<class T>
T ourQueue<T>::dequeue()
{
  T temp = stackList[0];
  stackList.remove(0);
  return temp;
}

template<class T>
T ourQueue<T>::front()
{
  return stackList[0];
}

template<class T>
void ourQueue<T>::clear()
{
  while(stackList.getSize()!=0)
  {
    stackList.remove(stackList.getSize()-1);
  }
}

template<class T>
int ourQueue<T>::size()
{
  return stackList.getSize();
}


#endif