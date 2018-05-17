// ----------------------------------------------
//  Author: James Anthony Ortiz
//  File: prime.cpp
//  Purpose: Implementation for class Prime.
// ----------------------------------------------
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ostream>

#include "prime.h"

// Constructor:
Prime::Prime(size_t b) : bv_(b + 1)
{
  // invoke Sieve() in body, requires n+1 bits
  Sieve();
} // end constructor:

// Copy Constructor:
Prime::Prime(const Prime &a) : bv_(a.bv_)
{
} // End Copy Constructor:

// Destructor:
Prime::~Prime()
{
} // End Destructor:

// Assignment Operator:
Prime &Prime::operator=(const Prime &a)
{
  if (this != &a)
  {
    bv_.Unset();
    for (size_t i = 0; i < bv_.Size(); ++i)
    {
      if (a.bv_.Test(i)) // If 1 is in bv, set the value:
      {
        bv_.Set(i);
      }
    }
  }
  return *this;
}

void Prime::Sieve()
{
  bv_.Set();
  bv_.Unset(0);
  bv_.Unset(1);

  size_t n = bv_.Size();
  for (size_t i = 2; i * i < n; i++)
  {
    if (bv_.Test(i) != 0)
    {
      for (size_t j = i * i; j < n; j += i)
      {
        bv_.Unset(j);
      }
    }
  }
}

// ---------------------------------------------

// Function Largest:
// Largest(n): returns the largest prime that is bounded above by n. (If n
// excedes the number of bits, it is replaced by the number of bits.)
size_t Prime::Largest(size_t ub) const
{
  // Replace ub with the max number of bits if it exceeds it:
  if (ub > UpperBound())
  {
    ub = UpperBound();
  }

  // Use a for loop to go through bitvector array
  // If value is 1 at the index, return the index:
  for (size_t i = ub; i > 0; --i)
  {
    if (bv_.Test(i) != 0)
      return i;
  }

  return 0;
}

// Function All #1:
// All(n os): sends all primes less than or equal to n to the stream os (again
// replacing n with the max number of bits if it excedes that number).
void Prime::All(size_t ub, std::ostream &os) const
{
  //  Replace ub with the max number of bits if it exceeds it:
  if (ub > UpperBound())
  {
    ub = UpperBound();
  }

  // For loop, to display all primes
  // If the value is 1 its index is displayed:
  for (size_t i = 0; i <= ub; i++)
  {
    if (bv_.Test(i) != 0)
      os << i << ' ';
  }

} // End All#1:

// Function All #2:
// All(os): sends all primes less than or equal to p.UpperBound() to the stream
// os.
void Prime::All(std::ostream &os) const
{
  return All(UpperBound(), os);
} //  End All#2:

// Function: UpperBound()
// UpperBound(): returns the largest bit index value stored.
size_t Prime::UpperBound() const
{
  return bv_.Size() - 1;
} // End UpperBound()

// Function: ResetUpperBound(n)
// ResetUpperBound(n): sets the upper bound to n if necessary. Calls
// BitVector::Expand.
void Prime::ResetUpperBound(size_t n)
{
  n = UpperBound();
  bv_.Expand(n);
  Sieve();
}

// Function: Dump(os)
// Dump(os): is intended for use by the development and testing teams.
// It should display the current state of the underlying BitVector object.
void Prime::Dump(std::ostream &os) const
{
  bv_.Dump(os);
} // End Dump(os)

