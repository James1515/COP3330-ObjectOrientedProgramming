//===========================================
// Author: James Anthony Ortiz
// File: fqueue.cpp 
// Purpose: Test Harness for project #8.
//===========================================

#include "tqueue.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <istream>
#include <stdlib.h>
#include <string.h>
//Testing examples:

//choose one from group A

// A1: makes queue of char
// typedef char ElementType;
//  ElementType fill = '*';
//  const size_t maxSize = 15;
//    const char* eT = "char";
//    char ofc = '\0'; //changed from "const char"
// end A1 

//  A2: makes queue of String
//#include <xstring.cpp>
//typedef fsu::String ElementType;
//ElementType fill = "*";
//const size_t maxSize = 100;
//const char* eT = "String";
//char ofc = ' ';
// end A2 

//  A3: makes queue of int
typedef int ElementType;
//ElementType fill = 0;
//const size_t maxSize = 100;
const char* eT = "int";
char ofc = ' ';
 

//Creates arbitrary Queue
typedef fsu::Queue <ElementType> QueueType;

//Dipslays Menu for User:
void DisplayMenu();

//Copy test to display results of copy/copied object
template < class Queue >
void CopyTest(Queue &q)
{
  std::cout << "CopyTest:\n";
  std::cout << "Copied object       size: " << q.Size() << '\n'
            << "                contents: ";
  q.Display(std::cout);
  std::cout << '\n';
}

//Assignment Test Used to Show Objects assigned 
//to tesch other
template < class Queue >
void AssignTest(const Queue& q)
{
  Queue q1;
  q1 = q;
  std::cout << "AssignTest:\n";
  std::cout << "Original object     size: " << q.Size() << '\n'
            << "                contents: ";
  q.Display(std::cout);
  std::cout << '\n';
  std::cout << "Assignee object     size: " << q1.Size() << '\n'
            << "                contents: ";
  q1.Display(std::cout);
  std::cout << '\n';
}

template < class Queue >
void ConstTest (const Queue& q)
{
  if (q.Size() != 0)
  {
    //std::cout << "ConstTest: inactive on empty queue\n";
    std::cout << "ConstTest: OK" << "\n";
    
  }
  else
  {
    std::cout << "ConstTest: inanctive on empty queue\n";
  }
  //Queue s1;
  //q1.Push(q.Top());      // OK:    q1 is not const
  // s.Push(s1.Top());     // Error: q is const
  //q1.Top() = q.Top();    // OK:    non-const = const
  // q.Top() = q1.Top(); // Error: const = non-const
  //std::cout << "ConstTest: OK\n"; 
}


//Main
int main( int argc, char* argv[] )
{
  bool BATCH = 0;
  if (argc > 1)
  {
    if (argv[1][0] != '\0')
      BATCH = 1;
  }

  std::cout << "This is a Queue < " << eT << " > test program\n";
  DisplayMenu();
  QueueType q(ofc);
  ElementType Tval;
  char option;
  do
  {
    std::cout << "Enter [command][argument] ('M' for menu, 'Q' to quit): ";
    std::cin >> option;
    if (BATCH) std::cout << option;
    switch (option) //Switch Statement for control
    {
      case '=':   // CC and =
        if (BATCH) std::cout << '\n';
        CopyTest(q);
        AssignTest(q);
        ConstTest(q);
        break;

      case '+': case '1':   // void Push(T)
        std::cin >> Tval;
        if (BATCH) std::cout << Tval << '\n';
        q.Push(Tval);
        break;

      case '-': case '2':  // void Pop()
        if (BATCH) std::cout << '\n';
        if (!q.Empty())
        {
          q.Pop();
        }
        else
        {
          std::cout << "Queue is empty\n";
        }
        break;

      case 'c': case 'C':  // void Clear()
        if (BATCH) std::cout << '\n';
        q.Clear();
        break;


      case 'e': case 'E':  // int Empty()
	  if(q.Empty())
	  {
		std::cout << "Queue is empty\n";
	  }
	  else
	  {
            std::cout << "Queue is not empty\n";
	  }
      break;
	  
	  case 'f': case 'F': //Front()
	  if (q.Empty())
	  {
		std::cout<< "Front of Queue: " << q.Front() << "\n";
	  }
	  else
	  {
		std::cout << "Front of Queue: " << q.Front() << "\n";
	  }
	  break;

      case 's': case 'S':  // size_t Size()
        if (BATCH) std::cout << '\n';
        std::cout << "Queue size     = "
                  << q.Size()
                  << '\n';
        break;

      case 'd': case 'D':  // display contents of Queue
        if (BATCH) std::cout << '\n';
        std::cout << "Queue contents:   ";
        q.Display(std::cout);
        std::cout << '\n';
        break;

      case 'o': case 'O':
        std::cin >> ofc;
        if(ofc == '0')
        {
          ofc = '\0';
        }
        else if (ofc == 'b' || ofc == 'B')
        { 
          ofc = ' ';
        }
        else if (ofc == 't' || ofc == 'T')
        {
          ofc = '\t';
        }
        else if (ofc == 'n' || ofc == 'N')
        {
          ofc = '\n';
        }
        else
        {
          std::cout << " ** bad ofc: only 0, b|B, t|T, n|N accepted\n";
          break;
        }
        q.SetOFC(ofc);
        break;

      case 'u': case 'U':  // display Dump()
        if (BATCH) std::cout << '\n';
        std::cout << "Queue Dump():\n";
        q.Dump(std::cout);
        std::cout << '\n';
        break;

      case 'm': case 'M': // display Menu
        if (BATCH) std::cout << '\n';
        DisplayMenu(); break;

      case 'q': case 'Q': case 'x': case 'X':
        if (BATCH) std::cout << '\n';
        option = 'q';
        break;
            
      default:
        if (BATCH) std::cout << '\n';
        std::cout << "** Unrecognized command -- please try again.\n";
		break;
    }
  }
  while (option != 'q');
  std::cout << "\nHave a nice day." << std::endl;
  return EXIT_FAILURE; //Used for Error Handling
}//End Main:

//Displays menu for the User:
void DisplayMenu()
{
  std::cout << "Push(Tval)  .............  + tval or 1 tval\n"
            << "Pop()  ..................  - or 2\n"
            << "Clear()  ................  C\n"
            << "Front()  ................  F\n"
            << "Empty()  ................  E\n"
            << "Size()  .................  S\n"
            << "Copy tests  .............  =\n"
            << "Display()  ..............  D\n"
            << "SetOFC(ofc)  ............  O 0|b|t|n\n"
            << "Dump() ..................  U\n"
            << "Display this menu  ......  M\n";
}
