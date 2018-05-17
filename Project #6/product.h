//---------------------------------------------------
// Author: James Ortiz
// File: product.h
// Purpose: Class definition header file for project
// #2.
//----------------------------------------------------

#ifndef _PRODUCT_H //morph of the filename into a legal identifier 
#define _PRODUCT_H

#include <cstdlib>
#include <iostream>
#include <cstdint>
#include <cstringdiff.h> //#include <cstringsort.h>

class Product //class Product:
{
public:
  Product            ();          //Default constructor:
  Product            (const char * n, uint32_t cde, float cst); //3-argument
                                                          //constructor:

  ~Product           ();                 //Destructor:
  Product            (const Product& a); //Copy constructor:
  Product& operator= (const Product& a); //assignment operator:
  
  //--------------------------------------------------------
  //Setter & Getter member functions:
  //--------------------------------------------------------
  void SetName        ( const char* name ); //sets the name field
  void SetBarCode     ( uint32_t bCode);    //sets the bar code field
  void SetCost        ( float cst );       //sets the cost field
  const char* GetName () const;        //returns a const pointer to the name field
  uint32_t GetBarCode () const;        //returns the bar code by value 
  float GetCost       () const;        //returns cost by value
private:  //Private member variables:
  char * name_;       //the product name
  uint32_t code_;     //the product bar code
  float cost_;        //the product cost
};//class Product

//================================================================//
//Overloaded operators:
//================================================================//

//Output operator overloader: 
std::ostream& operator << (std::ostream& os, const Product& p);


//***Added to class Product for Project #6***//

//Input operator overloader:
std::istream& operator >> ( std::istream& is , Product& p );

//Boolean operator overloader:
bool          operator <  ( const Product& p1 , const Product& p2 );

//================================================================//
#endif
