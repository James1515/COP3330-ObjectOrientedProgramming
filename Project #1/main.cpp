/*
    main.start
    1/02/18
    
    Chris Lacher 
    Partially complete driver program for stringsort project

*/

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cstringsort.h> //Changed from "cstringsort.h"

//Function PrintStrings:
//Returns a void value
//Purpose: Prints the strings in main   
void PrintStrings(char* array[], size_t count)
{
  for (size_t i = 0; i < count; ++i)
    std::cout << "  " << array[i] << '\n';
}

// copies a string in buffer and returns a pointer to the copy in memory
char* CopyString (const char* buffer)
{
  size_t size = strlen(buffer);
  char* cptr = new char [1 + size];
  strcpy(cptr,buffer);
  cptr [size] = '\0';
  return cptr;
}

//main
int main(int argc, char* argv[])
{
  //Condition if the number of arguments is less than 2:
  if (argc < 2)
  {
    std::cout << " ** Arguments required:\n"
              << "    1: A or D [A for ascii order, D for dictionary order]\n"
              << "    2: max number of strings [default = 1000]\n"
              << "    3: max string length     [default = 200]\n"
              << " ** Try again\n";
    return EXIT_FAILURE;
  }
  
  size_t buffsize = 201;
  if (argc > 3)
  {
    buffsize = 1 + atoi(argv[3]);
  }

  size_t arraysize = 1000;
  if (argc > 2)
  {
    arraysize = atoi(argv[2]);
  }
  bool ascii = 1;
  if (argv[1][0] != 'a' && argv[1][0] != 'A')
    ascii = 0;

  char** array = new char* [arraysize];

  // init array elements to nullptr
  for (size_t i = 0; i < arraysize; ++i) array[i] = nullptr;

  size_t count = 0;
  char* buffer = new char [buffsize];
  //Reads in input from the buffer
  while (std::cin >> std::setw(buffsize) >> buffer)
  {
    array[count] = CopyString(buffer);
    ++count;
    if(count == arraysize)
    {
      //Displays message if the counter reaches the value of the amount of 
      //elements of the array 
      std::cout << " ** maximum of " << count << " strings reached - terminating read loop " << std::endl;
      //breaks out of the while loop:
      break;
    }
      
  }

  //Displays the amount of strings as they are read:
  std::cout << '\n' << count << " strings as read:\n";
  PrintStrings(array, count);
  if (ascii)
    LexStringSort(array, array + count);
  else
    DictionaryStringSort(array, array + count);
  //Displays the strings after the insertion sort
 
  std::cout << '\n' << count << " strings after sort:\n";
  PrintStrings(array, count);
	
  delete [] buffer;
  
  for (size_t i = 0; i < count; ++i)
  {
    delete [] array[i];
  }
  delete [] array;
  
  return (EXIT_SUCCESS);
} //end main

