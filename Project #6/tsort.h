//================================================
// Author: James Anthony Ortiz
// File: tsort.h
// Purpose: Definition for function templates
// Display and InsertionSort
//================================================

#ifndef _TSORT_H
#define _TSORT_H

//Template used to display information to the console:
template < typename T >
void Display (const T* beg, const T* end, char ofc = '\0')
{
  while (beg < end)
  {
    if(ofc == '\0')
    {
      for(const T* i = beg; i != end; ++i)
      {
        T temp = *beg;
        std::cout << temp;
        beg++;
      }
    }
    else
    {
      for (const T* i = beg; i != end; ++i)
      {
        T temp = *beg;
        std::cout << ofc << temp;
        beg++;
      }
    }
    beg++;
  }
}

//Template InsertionSort:
//Implements the insertionsort algorithm for an
//aribitrary type T.
template < typename T >
void InsertionSort (T* beg, T* end)
{
  if(end - beg < 2) 
  {
    return;
  }
  
  T * i; //outer loop control
  T * j; //inner loop control
  T * k; //k is always j - 1 
  T t; //Value holder of arb. type T
  for(i = beg; i != end; ++i)
  {
    t = *i;
    for(k = i, j = k--; j != beg && t < *k; --j, --k)
      *j = *k;
    *j = t;
  }
  
}


#endif
