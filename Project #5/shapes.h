//---------------------------------------
// Author: James Anthony Ortiz
// File: shapes.h
// Purpose: Definitions for the following 
// classes: Shape, Box, Cylinder, and 
// Rectangle.
//---------------------------------------

#ifndef _SHAPES_H
#define _SHAPES_H


//==========================================
//Class Shape
//==========================================
class Shape
{
public:
 //Constructors:
  Shape ();
  Shape(float, float, float, bool);

  //Desturctor:
  virtual ~Shape();
 
  virtual const char* Name   () const;  // returns "generic"
  virtual float       Volume () const;  // returns volume of object  
  virtual float       Area   () const;  // returns area of object

protected:
  float x_, y_, z_; // dimensions of shape
  bool  verbose_;   // default value 0 given in constructor prototype

private:
  //Copy Constructor:
  Shape               (const Shape& s);

  //Assignment Operator:
  Shape& operator=    (const Shape& s); 
};// Class Shape

//====================================
//Class Box inherits from Shape:
//====================================
class Box: public Shape
{
public:
  //Constructors:
  Box();
  Box(float, float, float, bool);

  //Destructor:
  virtual ~Box();

  virtual const char* Name   () const;  // returns "box"
  virtual float       Volume () const;  // returns volume of box object  
  virtual float       Area   () const;  // returns surface area of box object

private:
  // Copy Constructor:
  Box                (const Box& b); 
  //Assignment Operator:
  Box& operator=     (const Box& b);

};// Class Box

//=====================================
//Class Cylinder inherits from Shape:
//=====================================
class Cylinder: public Shape
{
public:
  //Constructors:
  Cylinder();
  Cylinder(float x_, float z_, bool verbose_); //X, Z, V

  //Destructor:
  virtual ~Cylinder();

  virtual const char* Name   () const;  // returns "cylinder"
  virtual float       Volume () const;  // returns volume of cylinder object  
  virtual float       Area   () const;  // returns surface area of cylinder object

private:
  //Copy Constructor:
  Cylinder            (const Cylinder& c);
  //Assignment Operator:
  Cylinder& operator= (const Cylinder& c);
};//Class Cylinder:


//=====================================
//Class Rectangle inherits from Shape:
//=====================================
class Rectangle: public Shape
{
public: 
  //Constructors:
  Rectangle();
  Rectangle(float, float, bool);

  //Destructor:
  virtual ~Rectangle();

  virtual const char* Name   () const;  // returns "rectangle"
  virtual float       Area   () const;  // returns area of rectangle object

private:
  //Copy Consturctor:
  Rectangle            (const Rectangle& r);
  //Assignment Constuctor:
  Rectangle& operator= (const Rectangle& r);
};//Class Rectangle:

#endif
