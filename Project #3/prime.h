//--------------------------------------------------
// Author: James Anthony Ortiz
// File: prime.h
// Purpose: The API for class "Prime"
//--------------------------------------------------

#ifndef _PRIME_H
#define _PRIME_H


#include <iostream>  //For "ostream"
#include <cstring>   //To use size_t
#include <ostream>

#include "bitvect.h" //using Bitvect API

class Prime
{
public:
  //Constructor:
  Prime               (size_t b);
  //Destructor:
  ~Prime              ();       
  //copy constructor:
  Prime               (const Prime& a);
  //assignment operator:
  Prime& operator=    (const Prime& a);

  //-----------------------------------------------------------------
  //Other Function Methods:
  //-----------------------------------------------------------------
  size_t    Largest    (size_t ub) const;
  void      All        (size_t ub, std::ostream& os=std::cout) const;
  void      All        (std::ostream& os=std::cout) const;
  size_t    UpperBound () const;
  void      ResetUpperBound (size_t ub);
  void      Dump       (std::ostream& os=std::cout) const;
  // used in development & testing; displays underlying vector state.
private:
  //private variables:
  fsu::BitVector bv_;
  //private functions:
  void Sieve();
}; //Prime Class

#endif
