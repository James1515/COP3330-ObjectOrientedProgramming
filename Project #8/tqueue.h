//============================================
// Author:  James Anthony Ortiz
// File:    tqueue.h
// Purpose: Queue API for Project #8
//=============================================

//Ifndef..define..endif process for tqueue.h
#ifndef TQUEUE_H
#define TQUEUE_H

//Preprocessor Directive:
#include <iostream>

//namespace fsu used in Queue
namespace fsu
{

  //=============Class Queue=============//
  template <typename T>
  class Queue //As Ringbuffer
  {
  public:
    // Queue API
    void     Push     (const T& t);
    T        Pop      ();
    T&       Front    ();
    const T& Front    () const;
    size_t   Size     () const;
    bool     Empty    () const;
    void     Clear    ();

    // extra goodies
    void     Append   (const Queue& q);           // append entire contents of q 
    size_t   Capacity () const;                   // how many items can be
                                                  // stored using existing
                                                  // allocation
    void     Release  ();                         // de-allocate all links

    // proper type
    Queue   ();
    explicit Queue   (char ofc); // sets output formatting character
    Queue   (const Queue&);
    ~Queue  ();
    Queue& operator = (const Queue&);

  public:
    void     Display    (std::ostream& os) const; // output queue contents
                                                  // through os - depends on
                                                  // ofc_
    void     SetOFC     (char ofc);
    void     Dump       (std::ostream& os) const; // output all private data
                                                  // (for development use only)
  
  private:
    char    ofc_;

  private:
    //Class link used for ring buffer for Queue:
    class Link
    {
      Link (const T& t) : element_(t), next_(nullptr){}
      T      element_;
      Link * next_;
      friend class Queue;
    };

    Link * firstUsed_; // head of queue
    Link * firstFree_; // one past last item in queue  

  
  };

  //===========================================
  // Function operator<<
  // Used to display the contents of Queue
  //===========================================
  template < typename T >
  std::ostream& operator << (std::ostream& os, const Queue<T>& q)
  {
    q.Display(os);
    return os;
  }

  //=========================================
  // Function Queue()
  // Purpose: Empty constructor for Queue API
  //=========================================
  template<typename T>
  Queue<T>::Queue() : firstUsed_(0), firstFree_(0) 
  {

  }

  //=========================================
  // Function Queue(char ofc)
  // Purpose: Secondary constructor for 
  // Queue API
  //=========================================
  template<typename T>
  Queue<T>::Queue(char ofc) : ofc_(ofc)
  {
    
  }

  //=========================================
  // Function Copy Constructor for Queue
  // Purpose: Copy constructor for Queue API
  //=========================================
  template<typename T>
  Queue<T>::Queue(const Queue &queue) : firstUsed_(0), firstFree_(0)
  {
    //If empty is not true Append queue
    if (!queue.Empty())
    {
      Append(queue);
    } else
    {
      return;
    }
  }

  //=========================================
  // Function Destructor (~Queue())
  // Purpose: Destructor for Queue API
  //=========================================
  template<typename T>
  Queue<T>::~Queue() 
  {
    //Release content, also deleteing 
    //any dynamic allocation
    Release(); 
  }

  //====================================
  // Function operator=
  // Operator overloader for Queue API
  //====================================

  template<typename T>
  Queue<T>& Queue<T>::operator=(const Queue & queue)
  {
    if (&queue != this) 
    {
      if (!queue.Empty())
      {
        Append(queue);
      }
    }
    return *this;
  }

  //===================================
  // Function Push
  // Pushes element in queue
  //====================================
  template<typename T>
  void Queue<T>::Push(const T& t)
  {
    Queue<T>::Link* tVal_ = new Link(t);

    if (!Empty()) 
    {
      firstFree_->next_ = tVal_;
      firstFree_ = tVal_;
    }
    else
    {
      firstFree_ = tVal_;
      firstUsed_ = tVal_;
    }
  }


  //===================================
  // Function Display
  // Displays the values of the Queue in
  // order.
  //===================================
  template<typename T>
  void Queue<T>::Display(std::ostream& os) const
  {
    Queue<T>::Link* link = firstUsed_;

    if (!Empty())
    {    
      if (ofc_ == '\0') 
      {
        while (link != 0) 
        {
          os << link->element_;
          link = link->next_;
        }
        os << "\n";
        return;
      } else
      {
        while (link != 0)
        {
          os << link->element_ << ofc_;
          link = link->next_;
        }
      }
    }
    else
    {
      return;
    }
  }


  //===================================
  // Function SetOFC
  // Sets the value of ofc_
  //====================================
  template<typename T>
  void Queue<T>::SetOFC(char ofc)
  {
    ofc_ = ofc;
  }

  template<typename T>
  void Queue<T>::Dump(std::ostream & os) const
  {
    Display(os);
  }

  template <typename T>
  T Queue<T>::Pop()
  {
    // Queue<T>::Link* linkTemp = firstUsed_;
    
    //if (!Empty()) {

    //  if(firstUsed_ == firstFree_)
    //  {
    //    firstUsed_ = 0;
    //    firstFree_ = 0;
    //  }
    //  else 
    //  {
    //    firstUsed_ = firstUsed_->next_;
    //  }
    //  T qe_ = linkTemp->element_;
    //  delete linkTemp;
    //  return qe_;
    // }
    // else
    //{
    //  std::cerr << "** Queue error: 'Pop()' called on empty queue" << "\n";
    //  return T;      
    // }

    //==============Refactored Code====================//
    if (Empty())
    {
      std::cerr << "** Queue error: 'Pop()' called on Empty Queue" << std::endl;
      exit(EXIT_FAILURE);
    }
    else
    {
      Queue<T>::Link* tempLink = firstUsed_;

      if (firstUsed_ == firstFree_)
        firstUsed_ = firstFree_ = 0;
      else
        firstUsed_ = firstUsed_->next_;
      T data = tempLink->element_;
      delete tempLink;
      return data;
    }
  }

  //======================================
  // Function Front()
  // Displays the first element of the 
  // queue.
  //======================================
  template<typename T>
  T & Queue<T>::Front()
  {
    Queue<T>::Link* current = firstUsed_;

    if (!Empty())
    {
      return current->element_;
    } 
    else 
    {
      std::cerr << "** Queue error: Front called on empty queue\n";
    }

    return current->element_;
    
  }

  //=========================================
  // Function Front()
  // Displays the first value of the Queue.
  //=========================================
  template<typename T>
  const T & Queue<T>::Front() const
  {
    Queue<T>::Link* current = firstUsed_;

    if (!Empty())
    {
      return current->element_;
    } 
    else 
    {
      std::cerr << "** Queue error: Front called on empty queue\n";
      //exit(EXIT_FAILURE);
    }

    return current->element_;

  }

  //====================================
  //Function Clear()
  //Clears current queue by checking 
  //the size.
  //====================================
  template<typename T>
  void Queue<T>::Clear()
  {
    // T qe_ = firstLink_->element_;
    /*
    if (Size() == 0)
    {
    std::cerr << "Clear called on an empty Queue";
    } 
    else {
      while (!Empty())
      {
        firstUsed_ = firstUsed_->next_;
      }
    }
    */

    Release();
  }

  //=======================================
  // Function Capacity()
  // Returns the Size() of the Queue.
  //=======================================
  template<typename T>
  size_t Queue<T>::Capacity() const
  {
    return Size();
  }

  //==================================
  //Function Append()
  //Appends the link to next_ 
  //===================================
  template<typename T>
  void Queue<T>::Append(const Queue & queue)
  {
    Queue<T>::Link* link = queue.firstUsed_;

    T element = link->element_;

    Queue<T>::Link* newlink_ = new Link(element);

    firstFree_ = newlink_;
    firstUsed_ = newlink_;
    link = link->next_;

    while (link != 0)
    {
      T element = link->element_;
      Queue<T>::Link* newLink_ = new Link(element);
      firstFree_->next_ = newLink_;
      firstFree_ = newLink_;
      link = link->next_;
    }
  }

  //=================================
  // Function Release()
  // Releases the values on the Queue
  //=================================
  template<typename T>
  void Queue<T>::Release()
  {
    if (!Empty())
    {
      while (firstUsed_ != 0)
      {
        firstUsed_ = firstUsed_->next_;
      }
    }

    firstUsed_ = 0;
    firstFree_ = 0;
  }

  //=====================================
  // Function Empty()
  // Returns a boolean value, determines
  // if the Queue is currently empty.
  //======================================

  template <typename T>
  bool Queue<T>::Empty() const
  {
    if (firstUsed_ == 0)
    {
      return true;
    }
    else
    {
      return false;
    }

  }

  //====================================
  // Function Size() const 
  // Returns the size of the Queue
  //=====================================
  template<typename T>
  size_t Queue<T>::Size() const
  {
    size_t size = 0;
    if (!Empty())
    {
      Queue<T>::Link* temp = firstUsed_;
      
      while (temp != 0) 
      {
        temp = temp->next_;
        ++size;
      }
      return size;
    }
    else
    {
      return size;
    }
    return size;
  }

}
#endif
