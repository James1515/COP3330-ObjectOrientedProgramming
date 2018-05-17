//===========================================
// Author: James Anthony Ortiz
// File: fstack.cpp 
// Purpose: Test Harness for project #7.
//===========================================

#include "tstack.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <istream>

//Testing examples:

//choose one from group A

/*  A1: makes stacks of char
    typedef char ElementType;
    ElementType fill = '*';
    const size_t maxSize = 15;
    const char* eT = "char";
    char ofc = '\0'; //changed from "const char"
    const int  dir = +1;
    // end A1 */

/*  A2: makes stacks of String
#include <xstring.cpp>
typedef fsu::String ElementType;
ElementType fill = "*";
const size_t maxSize = 100;
const char* eT = "String";
char ofc = ' ';
const int  dir = +1;
// end A2 */

// /*  A3: makes stacks of int
typedef int ElementType;
ElementType fill = 0;
const size_t maxSize = 100;
const char* eT = "int";
char ofc = ' ';
const int  dir = +1;
// end A3 */

//Creates arbitrary StackType
typedef fsu::Stack <ElementType, maxSize> StackType;

//Dipslays Menu for User:
void DisplayMenu();

//Copy test to display results of copy/copied object
template < class Stack >
void CopyTest(Stack s)
{
  std::cout << "CopyTest:\n";
  std::cout << "Copied object       size: " << s.Size() << '\n'
            << "                contents: ";
  s.Display(std::cout);
  std::cout << '\n';
}

//Assignment Test Used to Show Objects assigned 
//to tesch other
template < class Stack >
void AssignTest(const Stack& s)
{
  Stack s1;
  s1 = s;
  std::cout << "AssignTest:\n";
  std::cout << "Original object     size: " << s.Size() << '\n'
            << "                contents: ";
  s.Display(std::cout);
  std::cout << '\n';
  std::cout << "Assignee object     size: " << s1.Size() << '\n'
            << "                contents: ";
  s1.Display(std::cout);
  std::cout << '\n';
}

template < class Stack >
void ConstTest (const Stack& s)
{
  if (s.Empty())
  {
    std::cout << "ConstTest: inactive on empty stack\n";
    return;
  }
  Stack s1;
  s1.Push(s.Top());      // OK:    s1 is not const
  // s.Push(s1.Top());   // Error: s is const
  s1.Top() = s.Top();    // OK:    non-const = const
  // s.Top() = s1.Top(); // Error: const = non-const
  std::cout << "ConstTest: OK\n"; 
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

  std::cout << "This is a Stack < " << eT << " > test program\n";
  DisplayMenu();
  StackType q(ofc, dir);
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
          std::cout << "Stack is empty\n";
        }
        break;

      case 'c': case 'C':  // void clear()
        if (BATCH) std::cout << '\n';
        q.Clear();
        break;

      case 't': case 'T':  // T Top()
        if (BATCH) std::cout << '\n';
        if (!q.Empty())
        {
          Tval = q.Top();
          std::cout << "Top of Stack: " << Tval << '\n';
        }
        else
        {
          std::cout << "Stack is empty\n";
        }
        break;

      case 'e': case 'E':  // int Empty()
        if (BATCH) std::cout << '\n';
        std::cout << "Stack is ";
        if (!q.Empty()) std::cout << "not ";
        std::cout << "empty\n";
        break;

      case 's': case 'S':  // size_t Size()
        if (BATCH) std::cout << '\n';
        std::cout << "Stack size     = "
                  << q.Size()
                  << '\n';
        break;

      case 'd': case 'D':  // display contents of stack
        if (BATCH) std::cout << '\n';
        std::cout << "Stack contents:   ";
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

      case 'u': case 'U':  // display contents of stack
        if (BATCH) std::cout << '\n';
        std::cout << "Stack Dump():\n";
        q.Dump(std::cout);
        std::cout << '\n';
        break;

      case 'm': case 'M': // display menu
        if (BATCH) std::cout << '\n';
        DisplayMenu(); break;

      case '<': // SetDIR(bottom-to-top) - horizontal displays, top at right
        q.SetDIR(+1);
        break;

      case '>': // SetDIR(top-to-bottom) - vertical displays, top on top
        q.SetDIR(-1);
        break;

      case 'q': case 'Q': case 'x': case 'X':
        if (BATCH) std::cout << '\n';
        option = 'q';
        break;
            
      default:
        if (BATCH) std::cout << '\n';
        std::cout << "** Unrecognized command -- please try again.\n";
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
            << "Top()  ..................  T\n"
            << "Empty()  ................  E\n"
            << "Size()  .................  S\n"
            << "Copy tests  .............  =\n"
            << "Display()  ..............  D\n"
            << "SetOFC(ofc)  ............  O 0|b|t|n\n"
            << "SetDIR(+1)  .............  < (horizontal -->)\n"
            << "SetDIR(-1)  .............  > (vertical   ^  )\n"
            << "Dump() ..................  U\n"
            << "Display this menu  ......  M\n";
}
