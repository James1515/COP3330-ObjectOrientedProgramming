//--------------------------------------------------------------
// Author: James Ortiz
// File: product.cpp
// Purpose: Inplementation file for project #2.
//
//--------------------------------------------------------------

#include <product.h>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <iomanip>

//=================================================
//Default constructor:
//Sets name to "#", barcode to 0x00000000, and cost
// to 0.0
//===================================================
Product::Product(): name_(nullptr), code_(0x00000000), cost_ (0.0) 
{
  name_ = new char[2]; //Provides space for two elements
  name_[0] = '#';
  name_[1] = '\0';
}// Default constructor:

//===========================
//3-Argument Constructor:
//===========================
Product::Product(const char * n, uint32_t cde, float cst): name_(nullptr), code_(cde), cost_(cst)
{
  //Adds null-terminating character to 
  //the name using strcpy:
  size_t size = strlen(n);
  name_ = new char[1 + size];
  strcpy(name_, n);
  name_[size] = '\0';

}//End 3-Argument Constructor:

//=====================================================
//Destructor:
//Performs termination housekeeping and restores memory
// back to operating system.
//=====================================================
Product::~Product()
{

  if(name_ != NULL)
  {
    delete[] name_;
  }
}

//=====================================================
//Copy Constructor:
//=====================================================
Product::Product(const Product& a): name_(nullptr), code_(a.code_), cost_(a.cost_)
{
  size_t size = strlen(a.GetName());
  name_ = new char[1 + size];
  code_ = a.GetBarCode();
  cost_ = a.GetCost();
  strcpy(name_, a.GetName());
  name_[size] = '\0';

}//copy constructor:

//===============================================
//Assignment Operator:
//===============================================
Product& Product::operator =(const Product& a)
{

  if (this != &a)
  {
    delete [] name_;
    size_t size = strlen(a.GetName());
    name_ = new char[1 + size];
    name_[size] = '\0';
    strcpy(name_, a.GetName());
    code_ = a.GetBarCode();
    cost_ = a.GetCost();

  }
  return *this;
}//end Assignment Operator

//---------------------------------------------
// Getter and Setter Function Implementation
//---------------------------------------------
//=========================
//Function: SetName
//=========================
void Product::SetName(const char* name)
{
  //Checks if name_ contains a nullptr
  //Otherwise, copies new c-string 
  //name using strcpy with null-terminator 

  if(name_ != nullptr)
  {
    delete[] name_;
  }

  size_t size = strlen(name);
  name_ = new char[1 + size];
  name_[size] = '\0';
  strcpy(name_, name);
}//end SetName

//=========================
//Function: SetBarCode
//=========================
void Product::SetBarCode(uint32_t bCode)
{
  code_ = bCode;
}//End SetBarCode

//=========================
//Function: SetCost
//=========================
void Product::SetCost(float cst)
{
  cost_ = cst;
}//end SetCost

//=========================
//Function: GetName
//=========================
const char* Product::GetName() const
{
  return name_;
}

//=============================
//Function: GetBarCode() const
//=============================
uint32_t Product::GetBarCode() const
{
  return code_;
} 

//==============================
//Function: GetCost() const
//==============================
float Product::GetCost() const
{
  return cost_;
}

//----------------------------------------------------------------

//=================================================================
//Output operator overloader:
//=================================================================
std::ostream& operator << ( std::ostream& os , const Product& p)
{
  std::ios_base::fmtflags flags = os.flags();
  os.setf(std::ios::fixed | std::ios::showpoint); // prep for $ output
  os.precision(2);
  os << p.GetName() << '\t' 
     << std::hex << std::uppercase << std::setfill('0') << std::setw(8) // prep
                                                                        // for
                                                                        // hex
                                                                        // output
     << p.GetBarCode() 
     << std::dec << std::setfill(' ') << '\t'          // return dec output
     << p.GetCost();
  os.setf(flags); // return flags to previous states
  return os;
}// operator overloader

