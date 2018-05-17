//-----------------------------------------------------
// Program: cstringdiff.cpp
// Description: Function implementations for program 1
// and edited for custom use in program #6.
// Author: James Anthony Ortiz
//-----------------------------------------------------
#include <cstringdiff.h> //Allows for the implementation of the
                         //prototype functions.

#include <cstdlib>       //General Utilities Library

#include <cctype>        //Allows the usage of the "tolower()"
                         //function.



//----------------------------------------------------
//Function LexDiff
//Returns an int value
//Returns "0" if strings are identical 
//A negative value if s1, comes before s2 in lex order
//A positive value if s1 come after s2 in lex order
//-----------------------------------------------------
int  LexDiff (const char* s1, const char* s2)
{
  std::size_t index = 0;
  char letterOne = *s1;
  char letterTwo = *s2;
  while (letterOne != '\0' && letterTwo != '\0')
  {
    int diff  = (int) (letterOne - letterTwo);
    if (diff != 0) return diff;
    ++index;
    letterOne = * (s1 + index);
    letterTwo = * (s2 + index);
  }
  return (int) (letterOne - letterTwo);
}//End LexDiff
//----------------------------------------------------
//Function DictionaryDiff:
//Return type: int
//Returns 0 if strings are the same (ignoring case)
//Returns -1 if s1 comes before s2 in dictionary order
//Returns 1 if s1 comes after s2 in dictionary order
//-----------------------------------------------------
int  DictionaryDiff  (const char* s1, const char* s2)
{
  std::size_t index = 0;
  char letterOne = *s1;
  char letterTwo = *s2;
  while (letterOne != '\0' && letterTwo != '\0')
  {
    int diff  = (int) (tolower(letterOne) - tolower(letterTwo));
    if (diff != 0)
    {
      if (diff < 0) return -1;
      if (diff > 0) return 1;
    }
    ++index;
    letterOne = * (s1 + index);
    letterTwo = * (s2 + index);
  }
  int diff  = (int) (tolower(letterOne) - tolower(letterTwo));
  if (diff < 0) return -1;
  if (diff > 0) return  1;
  return 0;
}//DictionaryDiff

//-----------------------------------------------------------------
//Function LexComp
//Returns a boolean value 
//Returns true if the s1 is before s2 in lex order otherwise false
//calls LexDiff.
//-----------------------------------------------------------------
 
bool LexComp(const char* s1, const char* s2)
{
  //If LexDiff < 0 return true,
  //otherwise return false.
  if (LexDiff(s1, s2) < 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//------------------------------------------------------------------
//Function DictionaryComp
//Returns a boolean value
//Returns true if the s1 is before s2 in dcitionary order otherwise false
//calls DictionayDiff.
//-----------------------------------------------------------------------

bool DictionaryComp(const char* s1, const char* s2)
{
  //If DictionaryDiff < 0 return true,
  //otherwise return false.
  if (DictionaryDiff(s1, s2) < 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}


//-----------------------------------------------
//Function LexStringSort
//Returns a void value
//Uses inertion sort and the function
//LexComp to determine how to sort.
//-----------------------------------------------
void LexStringSort (char* *beg, char* *end)
{
  //Implementation of insertion sort for LexStringSort:
  size_t size = end - beg;
  if (size < 2) return;
  size_t i; // outer loop control
  size_t j; // inner loop control
  size_t k; // k is always j - 1
  char *t;  // value holder
  for (i = 0; i < size; ++i)
  {
    t = beg[i];
    for (k = i, j = k--; j > 0 && LexComp(t, beg[k]); --j, --k)
      beg[j] = beg[k];
    
    beg[j] = t;
  }
}//End LexStringSort

//--------------------------------------------------
//Function DictionaryStringSort
//Returns a void value
//Uses insertion sort and the function
//DictionaryComp to determine how to sort.
//--------------------------------------------------
void DictionaryStringSort (char* *beg, char* *end)
{
  //Implementation of insertion sort for the 
  //DisctionaryStringSort:
  size_t size = end - beg;
  if (size < 2) return;
  size_t i; // outer loop control
  size_t j; // inner loop control
  size_t k; // k is always j - 1
  char *t; // value holder
  for (i = 0; i < size; ++i)
  {
    t = beg[i];
    for (k = i, j = k--; j > 0 && DictionaryComp(t, beg[k]); --j, --k)
      beg[j] = beg[k];
    
    beg[j] = t;
  }
} //end DictionaryStringSort

