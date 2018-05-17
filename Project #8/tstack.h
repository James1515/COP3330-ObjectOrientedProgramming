//==========================================
// Author: James Anthony Ortiz
// File: tstack.h
// Purpose: Template for Stack API in 
// project #7.
//==========================================

#ifndef _TSTACK_H
#define _TSTACK_H

//Preprocessor Directives
#include <iostream>
#include <cstdlib>

namespace fsu
{
  template < typename T , size_t N = 100>
  class Stack
  {
    // Stack < T , N > API
  public:
    void     Push     (const T& t); // push t onto stack; error if full
    T        Pop      ();           // pop stack and return removed element;
                                    // error if stack is empty.
    T&       Top      ();           // return top element of stack; 
	                                // error if stack is empty
    const T& Top      () const;     // const version
    size_t   Size     () const;     // return number of elements in stack
    size_t   Capacity () const;     // return storage capacity [maximum size] of
                                    // stack
    bool     Empty    () const;     // return 1 "true" if stack is empty, 0 "false" if not empty
    void     Clear    ();           // make the stack empty

  public:
    Stack             ();             // default constructor
    Stack             (char ofc, int dir); // sets ofc_ and dir_
    Stack             (const Stack&); // copy constructor
    ~Stack            ();             // destructor
    Stack& operator = (const Stack&); // assignment operator

  private:
    const size_t capacity_;  // = N = size of array   - fixed during life of stack
	
    T *           data_;     // Dynamically declared array of T objects    -
                             // where T objects are stored
							 
    size_t        size_;     // current size of stack - dynamic during life ofstack

  public:
    void     Display    (std::ostream& os) const; // output stack contents through os - depends on ofc_ and
                                                  // dir_
    void     SetOFC     (char ofc);
    void     SetDIR     (int dir);
    void     Dump       (std::ostream& os) const; // output all private data
                                                  // (for
                                                  // development use only)
  private:
    char    ofc_;
    int     dir_;
  };//End 

  
  //============Overloaded Operator <<============//
  //Purpose: To display contents to the screen.
  //==============================================//
  template < typename T , size_t N >
  std::ostream& operator << (std::ostream& os, const Stack<T,N>& s)
  {
    s.Display (os);
    return os;
  }//End Operator "<<"
};


using namespace fsu;

//=============Function Push=============//
//Purpose: To place an element onto the 
//stack. Calls error if the stack is full.
//========================================//
template < typename T , size_t N >
void Stack<T,N>::Push(const T& t)
{
  if (size_ == capacity_)
  {
    std::cerr << "** Stack error: Push(x) called on full stack";
    std::cout << '\n';
  }
  else
  {
    data_[size_] = t;
    size_ += 1;
  }
} //End Push function

//==============Pop Function================//
//Purpose:"Pop" off an element of the stack
//displays error is stack is initially empty.
//==========================================//
template < typename T , size_t N >
T Stack<T,N>::Pop()
{
  /*
  //Omitted Code
  T o;
  if (size_ == 0)
  {
    std::cerr << "** Stack error: Pop() called on Empty Stack";
    std::cout << '\n';
  }
  else
  {
    o = Top();
    size_ -= 1;
  }
  return o;
  */

  //Checks if object is not empty
  if(!this->Empty())
  {
    return data_[size_--];
  }
  //If the stack is empty, display an error.
  std::cerr << "** Stack error: Pop() called on Empty stack\n";
  return data_[0];

} // pop stack and return removed element; error if stack is empty

//===============Function Top (non-const)==================//
//Purpose: Return the Top element in the stack.
//=========================================================//
template < typename T , size_t N >
T& Stack<T,N>::Top()
{
  if (size_ == 0)
  {
    std::cerr << "** Stack error: Top() called on Empty Stack";
    std::cout << '\n';
    return data_[0];
  }
  else
  {
    return data_[size_ - 1];
  }
}// return top element of stack; error if stack is empty


//==================Function Top======================//
//Purpose: Return the value of the Top element in the
//stack.
//===================================================//
template < typename T , size_t N >
const T& Stack<T,N>::Top() const
{
  if (size_ == 0)
  {
    std::cerr << "** Stack error: Top() called on Empty Stack";
    return data_[0];
  }
  else
  {
    return data_[size_ - 1];
  }
}     // const version

//====================Function Size==================//
//Purpose: Returns the number of elements in the 
//stack.
//===================================================//
template < typename T , size_t N >
size_t Stack<T,N>::Size()const
{
  return size_;
}    // return number of elements in stack

//=================Function Capacity=============//
//Returns the array capcity of data_.
//===============================================//
template < typename T , size_t N >
size_t Stack<T,N>::Capacity() const
{
  return capacity_;
}// return storage capacity [maximum size] of stack


//===============Function Empty==================//
//Purpose: Determines if the stack is empty or 
//not, returns a bool value of true, if the stack
//is occupied, and a bool value of false otherwise.
//===============================================//
template < typename T , size_t N >
bool Stack<T,N>::Empty() const
{
  if (size_ == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}    // return 1/true if stack is empty, 0/false if not empty


//=================Clear Function===================//
//Purpose: makes stack empty:
//Returns a void value.
//==================================================//
template < typename T , size_t N >
void Stack<T,N>::Clear()
{
  size_ = 0;
} //makes the stack empty


//================Default Constructor=================//
//Purpose: Default Constructor for Class "Stack":
//Creates a stack object of size "N".
//====================================================//
template < typename T , size_t N >
Stack<T,N>::Stack():capacity_(N),size_(0),ofc_('\0'),dir_(0)
{
  //Create a new array of T objects
  data_ = new T[capacity_];
  
  if (capacity_ < 1)
  {
    std::cerr << "Error";
  }
}//default constructor

//================Secondary Constructor=================//
//Purpose: Secondary Constructor with two arguments,
//"ofc" and "dir".
//=======================================================//
template < typename T , size_t N >
Stack<T,N>::Stack(char ofc, int dir): capacity_(N),size_(0), ofc_(ofc),dir_(dir)
{
  //Create a new array of T objects:
  data_ = new T[capacity_];
  
  //Check if capacity is < 1:
  //If true, display error.
  if (capacity_ < 1)
  {
    std::cerr << "Error";
  }

  //Set ofc_ and set dir_:
  Stack<T,N>::SetOFC(ofc_);
  Stack<T,N>::SetDIR(dir_);
} //End Secondary Constructor

//==============Copy Constructor================//
//Purpose: Copy Construcotor for class "Stack"
//==============================================//
template < typename T , size_t N >
Stack<T,N>::Stack(const Stack& s): capacity_(N),size_(s.size_),ofc_(s.ofc_),dir_(s.dir_)
{

  //Omitted Code:
  //for (size_t i = 0; i < size_; ++i)
  //{
  //  data_[i] = s.data_[i];
  //}

  //Refromed Code
  data_ = new T[capacity_];
  for(size_t i= 0; i < size_; ++i)
  {
    data_[i] = s.data_[i];
  } 

} // copy constructor


//================Stack Destructor===============//
//Purpose: Destructor for class "Stack".
//===============================================//
template < typename T , size_t N >
Stack<T,N>::~Stack()
{
  //Do termination housekeeping on data_ if true:
  if(data_ != nullptr)
  {
    delete data_;
  }
} //end destructor

//==============Assignment Operator================//
//Purpose: Assignment Operator "=" for class Stack.
//=================================================//
template < typename T , size_t N >
Stack<T,N>& Stack<T,N>::operator= (const Stack& s)
{
  //Omitted Code:
  //size_ = s.size_;
  //dir_= s.dir_;
  //ofc_= s.ofc_;
  //data_ = new T [size_];
  //for (size_t i = 0; i < size_; ++i)
  //{
  //  data_[i] = s.data_[i];
  //}

  //Refactored code
  if(this != &s)
  {
    delete data_;
    size_t size = s.size_;
    data_ = new T[size];
    dir_ = s.dir_;
    ofc_ = s.ofc_;
    for(size_t i = 0; i < size; ++i)
    {
      data_[i] = s.data_[i];
    }
  }
  return *this;
}//End assignment operator

//=================Display Function================//
// Purpose: Dsiplays the values of the stack to the 
// console.
//=================================================//
template < typename T , size_t N >
void Stack<T,N>::Display(std::ostream& os)const
{
  if (dir_ >= 0)
  {
    for (size_t i = 0; i < size_; ++i)
    {
      if (ofc_ == '\0')
      {
        os << data_[i];
      }
      else
      {
        os << ofc_ << data_[i];
      }
    }
  }
  else
  {
    for (size_t i = size_ ; i > 0; --i)
    {
      if (ofc_ == '\0')
      {
        os << data_[i - 1];
      }
      else
      {
        os << ofc_ << data_[i - 1];
      }
    }
  }
} // End Display: output stack contents through os - depends on ofc_ and dir_

//=================SetOFC Function===================//
//Purpose: To set the private variable ofc_.
//===================================================//
template < typename T , size_t N >
void Stack<T,N>::SetOFC(char ofc)
{
  ofc_ = ofc;
}//End SetOFC

//=================SetDIR Function===================//
//Purpose: To set the private variable dir_.
//===================================================//
template < typename T , size_t N >
void Stack<T,N>::SetDIR(int dir)
{
  dir_ = dir;
}//End SetDIR 


//================Dump Function======================//
//Purpose: Dump for information about the stack.
//===================================================//
template < typename T , size_t N >
void Stack<T,N>::Dump(std::ostream& os) const
{
  os << "Capacity: " << capacity_ << "\n";
  os << "Size:     " << size_  << "\n";
  os << "Array:    [";
  for (size_t i = 0; i < capacity_ -1; ++i)
  {
    if (i < size_ )
    {
      os << data_[i];
    }
    else
    {
      os << "*";
    }
    if (i < capacity_ - 2)
    {
      os << ",";
    }
  }
  os << "]\n";

  os << "Stack:    [";
  if (size_ > 0)
  {
    for (size_t i = 0; i < size_ ; ++i)
    {
      os << data_[i];
      if (i < size_ - 1)
      {
        os << ",";
      }
    }
  }
  os << "]\n";
} //End Dump 
#endif
