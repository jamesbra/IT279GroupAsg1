#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <exception>

template<class T>
class list
{
  public:
    //default constuctor
    list();
    //construction with initial data node
    list(T newData);
    
    //copy constuctor
    list(const list& listObject);
    
    //Deconstructor
    ~list();
    
    //returns current size of list
    int getSize();
    
    //insert at specific location
    void insert(T newData,int location=-1);
    
    //search for a given value in the array and returns the location, returns -1 if does not exist
    int search(T newData);
    
    //operator overload to get to the element
    T& operator[](int index) const;
    
    void output();
    
    //deletes the data at a specified locations
    void remove(int location);
    
    //changes the data at the current location from its current value to provided value
    void change(int location, T newData);
    
    list<T>& operator=(const list& rtSide);
    
    //internal node structure to be used in this class
    struct node
    {
      T data;
      node* next;
    };
    
  private:
    //size of array
    int size;
    //node at the beginning
    node* head;
    //node at the end
    node* tail;
    
    
};

template<class T>
list<T>::list()
{
  size=0;
}

template<class T>
list<T>::list(T newData)
{
  head = new node;
  tail = head;
  head->data = newData;
  size=1;
}

template<class T>
int list<T>::getSize()
{
  return size;
}

template<class T>
void list<T>::insert(T newData,int location)
{
  //if there is nothing in the list and does not specifiy location
  if(location==-1 && size==0)
  {
    head=new node;
    tail=head;
    head->data=newData;
    size++;
  }
  //add to end of node if locations is given to add to end of node or if location is not given
  else if((location==-1 && size!=0)||location==size)
  {
    /*
    node* temp=head;
    node* newNode = new node;
    newNode->data = newData;
    //loop give us location a temp pointer to node location
    for(int i=0;i<size-1;i++)
    {
      temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    size++;
    */
    node* newNode = new node;
    newNode->data = newData;
    tail->next = newNode;
    tail=tail->next;
    size++;
  }
  //replaces head if location is zero
  else if(location==0)
  {
    node* newNode = new node;
    newNode->data=newData;
    newNode->next=head;
    head=newNode;
    size++;
  }
  //all other cases, size is not zero and location is given
  else
  {
    node* temp=head;
    node* newNode = new node;
    newNode->data = newData;
    //loop give us location a temp pointer to node location
    for(int i=0;i<location-1;i++)
    {
      temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    size++; 
  }
}

template<class T>
int list<T>::search(T data)
{
  //temp node pointer to traverse when searching
  node* temp=head;
  for(int i=0;i<size;i++)
  {
    if(temp->data==data)
    {
      return i;
    }
    temp=temp->next;
  }
  return -1;
}

template<class T>
T& list<T>::operator[](int index) const
{
  //temp pointer node to locate the index
  node* temp=head;
  for(int i=0;i<index;i++)
  {
    temp=temp->next;
  }
  
  return temp->data;
}

template<class T>
void list<T>::output()
{
  node* temp=head;
  for(int i=0;i<size;i++)
  {
    std::cout<<temp->data<<" ";
    temp=temp->next;
  }
}

template<class T>
void list<T>::remove(int location)
{
  
  node* temp;
  //creates a major error when negative
  if(location<0)
  {
    head=temp;
  }
  else if(location==0)
  {
    temp=head;
    head=head->next;
    delete temp;
  }
  else if(location==size-1)
  {
    temp=head;
    for(int i=0;i<size-2;i++)
    {
      temp=temp->next;
    }
    delete temp->next;
    tail = temp;
  }
  
  else
  {
    temp=head;
    for(int i=0;i<location-1;i++)
    {
      temp=temp->next;
    }
    node* temp2 = temp->next;
    temp->next=temp->next->next;
    delete temp2;
  }
  
  
  size--;
}

template<class T>
list<T>::~list()
{
  node* temp = head;
  //loop to go through and delete all of the different nodes so that it does not 
  //take up dynamic memory
  for(int i=0;i<size;i++)
  {
    head=head->next;
    delete temp;
    temp=head;
  }
}

template<class T>
list<T>::list(const list& listObject)
{
  size = listObject.size;
  head = new node;
  node* temp=head;
  
  for(int i=0;i<size;i++)
  {
    temp->data = listObject[i];
    //catch to make sure it does not add extra node on next loop through
    if(i!=size-1)
    {
      temp->next=new node;
      temp=temp->next;
    }
  }
  tail=temp;
  
}

template<class T>
void list<T>::change(int location,T newData)
{
  node* temp=head;
  for(int i=0;i<location;i++)
  {
    temp=temp->next;
  }
  
  temp->data = newData;
}

template<class T>
list<T>& list<T>::operator=(const list& rtSide)
{
  if(this == &rtSide)
  {
    return *this;
  }
  else
  {
      
      node* temp = head;
    //loop to go through and delete all of the different nodes so that it does not 
    //take up dynamic memory
      
      for(int i=0;i<size;i++)
      {
	head=head->next;
	delete temp;
	temp=head;
      }
    
      size =rtSide.size;
      //loop to go through and make a new linked list
      head = new node;
      temp = head;
      for(int i = 0;i<size;i++)
      {
	temp->data = rtSide[i];
	//catch to make sure it does not add extra node on last loop through
	if(!(i==size-1))
	{
	  temp->next = new node;
	  temp = temp->next;
	}
	  
      }
      tail = temp;
      
      return *this;
  }
}

#endif