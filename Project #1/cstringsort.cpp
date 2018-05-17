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
	

  /*Checks the sizes of the c-strings
    For the first string:*/
  
  unsigned int length1 = 0;
  /*For the second string:*/
  unsigned int length2 = 0;
  
  //Checks the size of the first string
  while (*(s1 + length1))
  {
    length1++;
  }
  
  //Checks the size of the second string
  while (*(s2 + length2)) 
  {
    length2++;
  }
  
  unsigned int length = 0;
  if(length1 < length2)
  {
    length = length1;
  }
  else
  {
    length = length2;
  }
  //If the element in s1 is less than the element
  //in s2 return -1, otherwise return 1.   
  unsigned int i = 0;
  for(i = 0; i < length; i++)
  {
    if(s1[i] < s2[i])
      return -1;
    else if (s1[i] > s2[i])
      return 1;
  }

  //Checks if length1 is less than
  //length2 if it is, it returns 
  //-1, otherwise, it returns 1.  
  if (length1 < length2)
  {
    return -1;
  }
  else if (length1 > length2)
  {
    return 1;
  }
  else
  {
    return 0;
  }
  
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

  unsigned int length1 = 0;
  /*For the second string:*/
  unsigned int length2 = 0;
  //Counts the lengths of the first string and the second 
  //string. 

  while (*(s1 + length1))
  {
    ++length1;
 
  }
  
  while (*(s2 + length2))
  {
    ++length2;
  }
  
  //Compares lengths for assignment
  unsigned int length = 0;
  if(length1 < length2)
    length = length1;
  else
    length = length2;
  
  unsigned int i = 0;
  for(i = 0; i < length; i++)
  {
    if(tolower(s1[i]) < tolower(s2[i]) ) //Uses the tolower function
    {
      return -1;
    }
    else if (tolower(s1[i]) > tolower(s2[i]) )
    {
      return 1;
    }
  }
  
  if (length1 < length2)
  {
    return -1;
  }
  else if (length1 > length2)
  {
    return 1;
  }
  else
  {
    return 0;
  }

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

