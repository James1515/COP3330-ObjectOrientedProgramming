



#include <cstringsort.h> //Allows for the implementation of the
                          //prototype functions. 
#include <cstdlib> //General Utilities Library
#include <cctype> //Allows the usage of the "tolower()"
                  //function.

//-----------------------------------------------------
// Program: cstringsort.cpp
// Description: Function implementations for program 1.
// Author: James Anthony Ortiz
//-----------------------------------------------------



//----------------------------------------------------
//Function LexDiff
//Returns an int value
//Returns "0" if strings are identical 
//A negative value if s1, comes before s2 in lex order
//A positive value if s1 come after s2 in lex order
//-----------------------------------------------------
int LexDiff (const char* s1, const char* s2)
{
  int diff_value = 0;
  while (*s1 !='\0' && *s2 != '\0')
  {
    char s1_ascii_value;
    char s2_ascii_value;
    if (*s1 == *s2)
    {
      s1++, s2++;
    }
    else
    {
      s1_ascii_value = int (*s1);
      s2_ascii_value = int (*s2);
      diff_value = s1_ascii_value - s2_ascii_value;
      break;
    }
    if (*s1 =='\0' && *s2 == '\0')
    {
      diff_value=0;
      break;
    }
    else
    {
      if (*s1 =='\0')
      {
        diff_value = -99;
        break;
      }
      if (*s2 =='\0')
      {
        diff_value = 99;
        break;
      }

    }
  }
  return diff_value;
}

//----------------------------------------------------
//Function DictionaryDiff:
//Return type: int
//Returns 0 if strings are the same (ignoring case)
//Returns -1 if s1 comes before s2 in dictionary order
//Returns 1 if s1 comes after s2 in dictionary order
//-----------------------------------------------------
int DictionaryDiff(const char* s1, const char* s2) 
{
  int diff_value = 0;
  while (*s1 !='\0' && *s2 != '\0')
  {
    char s1_dict_value;
    char s2_dict_value;
    if (*s1 == *s2)
    {
      s1++, s2++;
    }
    else 
    {
      s1_dict_value = int (*s1);
      s2_dict_value = int (*s2);
      if (s1_dict_value <=90)
      {
        s1_dict_value=s1_dict_value+32;
      }
      if (s2_dict_value <=90)
      {
        s2_dict_value=s2_dict_value+32;
      }
      diff_value = s1_dict_value - s2_dict_value;
      break;
    }
    if (*s1 =='\0' && *s2 == '\0')
    {
      diff_value= 0;
      break;
    }
    else 
    {
      if (*s1 =='\0')
      {
        diff_value = -99; 
        break;
      }
      if (*s2 =='\0')
      {
        diff_value = 99;
        break;
      }

    }
  }
  
  if (diff_value<0) 
  {

    diff_value=-1;
  }
  if (diff_value>0) 
  {

    diff_value=1;
  }
  return diff_value;
}
  
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
  char *t; // value holder
  for (i = 0; i < size; ++i)
  {
    t = beg[i];
    for (k = i, j = k--; j > 0 && LexComp(t, beg[k]); --j, --k)
      beg[j] = beg[k];
    
    beg[j] = t;
  }
}

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
}

