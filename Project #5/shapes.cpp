//-------------------------------------------
// Author: James Anthony Ortiz
// File: shapes.cpp
// Purpose: Implementation for the classes
// Shape, Box, Cylinder, Rectangle.
//--------------------------------------------


#include <shapes.h>
#include <iostream>
#include <cmath>


//==============Shape======================//

//Constructor:
Shape::Shape(): x_(0), y_(0) , z_(0), verbose_(0)
{
}//End Constuctor:

//Parameterized Constuctor:
Shape::Shape(float length, float width, float height, bool verbose):
  x_(length), y_(width), z_(height), verbose_(verbose)
{

  if(verbose_ == 1)
  {
    std::cout << "Shape(" << Shape::x_ << "," << Shape::y_<< "," << Shape::z_ << "," << Shape::verbose_ << ")\n";
  }

}//End Parameterized Constructor:

//Destuctor:
Shape::~Shape()
{
  std::cout << "~Shape()\n";
}

//Returns "generic"
const char* Shape::Name() const
{
  return "generic";
}

//Returns Volume of an object
float Shape::Volume() const
{
  return 0.0;
}

//Returns Area of an Object
float Shape::Area() const
{
  return 0.0;
}

//--------------------------

//==========Box=============//

//Constructor
Box::Box(): Shape()
{

}//Constuctor:

//Par. Constuctor:
Box::Box(float length, float width, float height, bool verbose): 
  Shape(length, width, height, verbose)
{
  if(verbose_ == 1)
  {
    std::cout << "Box(" << Box::x_ << "," << Box::y_<< "," << Box::z_ << "," << Box::verbose_ << ")\n";
  }

}

Box::~Box()
{
  if(verbose_ == 1)
  {
    std::cout << "~Box()\n";
  }
}

const char* Box::Name() const
{
  return "box";
}

float Box::Volume() const
{
  float vol;
  vol = x_ * y_ * z_; //L* W *H
  return vol;
}

float Box::Area() const
{
  //x_ = L, y_ = W, z_ = H
  //SA = 2(H x W) + 2(H x L) + 2(W x L)
  
  return 2*(z_ * y_) + 2*(z_ * x_) + 2*(y_ * x_);
   
}

//-----------------------------------//

//===========Cylinder================//

//Constructor:
Cylinder::Cylinder(): Shape()
{
}//Constructor:

//Par. Constructor:
Cylinder::Cylinder(float x_, float z_, bool verbose_): 
  Shape(x_, 0, z_, verbose_)
{

  if(Shape::verbose_ == 1)
  {
    std::cout << "Cylinder(" <<  Cylinder::x_ << "," << Cylinder::z_ << "," << Cylinder::verbose_  << ")\n";
  }

}//Par. Constructor

//Destructor:
Cylinder::~Cylinder() 
{
  if(Shape::verbose_ == 1)
  {
    std::cout << "~Cylinder()\n";
  }
}//End Destructor:

//Function Name()
const char* Cylinder::Name() const
{
  return "cylinder";
}//End Cylinder Name()

//Function Volume()
float Cylinder::Volume() const
{
  //Volume of a cylinder:
  //Radius = x_ 
  //vol = PI * r * r * h
  float vol;
  vol = M_PI * x_ * x_ * z_;
  return vol; 
}//Cylinder Volume

//Function Area()
float Cylinder::Area() const
{

  //Area of a cylinder:
  //A = 2 * PI * r * h + 2 * PI * r * h
  float area;
  area = 2 * M_PI * x_ * z_ + 2 * M_PI * x_ * x_;
  return area;
}//Cylinder Area


//------------------------------------

//==============Rectangle====================//

//Constructors:

Rectangle::Rectangle(): Shape()
{
}//Rectangle

Rectangle::Rectangle(float x_, float y_, bool verbose_): 
  Shape(x_, y_, 0, verbose_)
{
  if(verbose_ == 1)
  {
    std::cout << "Rectangle(" <<  Rectangle::x_ << "," << Rectangle::y_ << "," << Rectangle::verbose_ <<  ")\n";
  }
}//Par. Rectangle Constructor

//Destructor:
Rectangle::~Rectangle()
{
  if(verbose_ == 1)
  {
    std::cout << "~Rectangle()\n";
  }
}

//Function Name()
const char* Rectangle::Name() const
{
  return "rectangle";
}//Rectangle Name()


//Function Area()
float Rectangle::Area() const
{
  float Area;
  //Area = width * length;
  Area = x_ * y_;
  return Area;
}//Rectangle Area()


//-------------------------------------//


