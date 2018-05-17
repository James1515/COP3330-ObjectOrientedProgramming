//----------------------------------------
// Author: James Anthony Ortiz
// File: vehicles.h
// Purpose: Definition of the classes
// Vehicle, Car, Truck, Van, Tanker, 
// Flatbed
//----------------------------------------

#ifndef _VEHICLES_H
#define _VEHICLES_H
#include <iostream>
#include "shapes.h"
#include <cmath> //For PI

//Elements for VehicleType:
enum VehicleType {badSn, vehicle, car, truck, van, tanker, flatbed};

//=============================================
//Class Vehicle:
//=============================================
class Vehicle
{
public:
  //Constructors:
  Vehicle                                  ();

  Vehicle          (const char* serialNumber_, unsigned int passengerCapacity_, bool verbose_);

  //Destructor:
  virtual ~Vehicle                         ();

  const char*           SerialNumber       () const; // returns serial number 
  virtual unsigned int  PassengerCapacity  () const; // returns passenger capacity 
  virtual float         LoadCapacity       () const; // returns 0
  virtual const char*   ShortName          () const; // returns "UNK"
  virtual float         Toll               () const; // returns toll using fee schedule
  static  VehicleType   SnDecode           (const char* sn);

private:
  //Copy Constuctor:
  Vehicle (const Vehicle& v); 

  //Assignment Constructor:
  Vehicle& operator= (const Vehicle& t);

  //Private Variables:
  char*        serialNumber_;
  unsigned int passengerCapacity_;
protected:
  bool verbose_;

};

//================================================
//Class Car Derived from Vehicle:
//================================================

class Car: public Vehicle
{
public: 
  //Consturctors:
  Car();

  Car(const char*, unsigned int, bool);

  //Destuctor:
  virtual ~Car();

  virtual const char* ShortName() const; //return "CAR"
private:
  //Copy Constructor:
  Car(const Car& c);

  //Assignment Operator:
  Car& operator= (const Car& c);

};//Class Car

//================================================
//Class Truck Derived from Vehicle:
//================================================

class Truck: public Vehicle
{
public:
  //Constructors:
  Truck();
  Truck(const char*, unsigned int, const char*,  bool);
  //Destructor:
  virtual ~Truck();

  virtual const char*   ShortName          () const;  // returns "TRK"
  virtual float         Toll               () const;  // returns toll using fee schedule           
  virtual const char*   DOTLicense         () const;  // returns the license number  
private:
  //Copy Constructor:
  Truck(const Truck& t);
  //Assignment Operator:
  Truck& operator= (const Truck& t);

  //Private Variable:
  char* DOTLicense_;

};//Class Truck


//================================================
//Class Van Derived from Vehicles: Truck & Box
//================================================

class Van: public Truck, Box
{
public:
  //Constructors:
  Van();
  Van(const char*, unsigned int, const char*, float, float, float, bool);

  //Destructor:
  virtual ~Van();

 
  virtual float         LoadCapacity       () const;  // returns volume of box  
  virtual const char*   ShortName          () const;  // returns "VAN"

private:

  //Copy Constructor:
  Van(const Van& v);

  //Assignment Operator:
  Van& operator= (const Van& v);


};//Class Van

//=================================================
//Class Tanker: Derived from Truck & Cylinder
//================================================

class Tanker: public Truck, Cylinder
{
public:
  //Constructor:
  Tanker();
  Tanker(const char*, unsigned int, const char*, float, float, bool);

  //Destructor:
  virtual ~Tanker();

  virtual float         LoadCapacity       () const;  // returns volume of cylinder  
  virtual const char*   ShortName          () const;  // returns "TNK"

private:
  //Copy Constructor:
  Tanker(const Tanker& t);

  //Assignment Operator:
  Tanker& operator= (const Tanker& t);

};//Class Tanker

//=================================================
//Class Flatbed: Derived from Truck & Rectangle
//=================================================

class Flatbed: public Truck, Rectangle
{
public:
  //Constructors:
  Flatbed();
  Flatbed(const char*, unsigned int, const char*, float, float, bool);

  //Destructor:
  virtual ~Flatbed();

  virtual float         LoadCapacity       () const;  // returns area of rectangle  
  virtual const char*   ShortName          () const;  // returns "FLT"

private:
  //Copy Constructor:
  Flatbed(const Flatbed& f);

  //Assignment Constructor:
  Flatbed& operator= (const Flatbed& f); 
};// Class Flatbed


#endif
