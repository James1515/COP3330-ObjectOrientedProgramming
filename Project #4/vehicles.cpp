//------------------------------------------
// Author: James Anthony Ortiz
// File: vehicles.cpp
// Purpose: Implementation of vehicles.h
//
//------------------------------------------

#include <iostream>
#include "vehicles.h"
#include "shapes.h"
#include <cmath>
#include <cstring>
//=====================================
//Vehicle Class:
//=====================================

//Constructor #1:
Vehicle::Vehicle (): serialNumber_(NULL), passengerCapacity_(0), verbose_(0)
{ 
  const char* smPtr = "nullptr"; //holds value to copy into serialNumber_
  
  //value of smPtr is copied
  serialNumber_ = new char[8];
  serialNumber_[8] = '\0';
  strcpy(serialNumber_, smPtr);
}

//Constructor #2:
Vehicle::Vehicle (const char* serialNumber, unsigned int passengerCapacity, bool verbose): serialNumber_(NULL), passengerCapacity_(passengerCapacity), verbose_(verbose)
{

  if (serialNumber_ != NULL)
  {
    delete[] serialNumber_;
  }

  size_t size = strlen(serialNumber);
  serialNumber_ = new char[1+size];
  serialNumber_[size] = '\0';
  strcpy(serialNumber_, serialNumber);

  if (verbose_ == 1)
    std::cout << "Vehicle()\n";
}

//Destructor for Vehicle:
Vehicle::~Vehicle()
{
  if(Vehicle::verbose_ == 1)
  {
    std::cout << "~Vehicle()\n";
  }
  if(serialNumber_ != NULL)
  {
    delete[] serialNumber_;
  }

}//Destructor:

//Function serialNumber
const char* Vehicle::SerialNumber() const
{
  return serialNumber_;
}

//Function PassengerCapacity 
unsigned int Vehicle::PassengerCapacity() const
{
  return passengerCapacity_;
}

//Function LoadCapacity
float Vehicle::LoadCapacity() const
{
  return 0;
}

//Function ShortName
const char* Vehicle::ShortName() const
{
  return "UNK";
}

float Vehicle::Toll() const
{
  //Toll value for Cars:
  return 2.00; 
}

VehicleType Vehicle::SnDecode(const char* sn)
{
  switch(sn[0])
  {
    case '0':
      return badSn;
    case '1':
      return vehicle;
    case '2':
      return car;
    case '3':
      return truck;
    case '4':
      return van;
    case '5':
      return tanker;
    case '6':
      return flatbed;
    default:
      return badSn;
  }
}//SNDecode


Car::Car(): Vehicle()
{
  
}

Car::Car(const char* serialNumber, unsigned int passengerCapacity, bool verbose): Vehicle(serialNumber, passengerCapacity, verbose)
{
  if(Vehicle::verbose_ == 1)
  {
    std::cout << "Car()\n";
  }
}

//Destructor
Car::~Car()
{
  if(Vehicle::verbose_ == 1)
  {
    std::cout << "~Car()\n";
  }
}

const char* Car::ShortName() const 
{
  return "CAR";
}

//=================Truck================//

//Truck Constructor #1:
Truck::Truck(): Vehicle(), DOTLicense_(NULL)
{
  const char* snPtr = "nullptr";

  DOTLicense_ = new char[8];
  DOTLicense_[8] = '\0';
  strcpy(DOTLicense_, snPtr);
}


//Truck Constructor #2:
Truck::Truck(const char* serialNumber, unsigned int passengerCapacity, const char* DOTLicense, bool verbose): Vehicle(serialNumber, passengerCapacity, verbose), DOTLicense_(NULL)
{
  if(DOTLicense_ != NULL)
  {
    delete[] DOTLicense_;
  }

  size_t size = strlen(DOTLicense);
  DOTLicense_ = new char[1 + size];
  DOTLicense_[size] = '\0';
  strcpy(DOTLicense_, DOTLicense);

  if(Vehicle::verbose_ == 1)
  {
    std::cout << "Truck()\n";
  }
}

//Truck Destructor:
Truck::~Truck()
{
  if(Vehicle::verbose_ == 1)
  {
    std::cout << "~Truck()\n";
  }

  if(DOTLicense_ != NULL)
  {
    delete[] DOTLicense_;
  }
}

//Truck ShortName()
const char* Truck::ShortName() const
{
  return "TRK";
}

//Truck Toll

float Truck::Toll() const 
{
  return 10.00;
}

const char* Truck::DOTLicense() const 
{
  return DOTLicense_;
}

//===================Van===================//

//Van Constructor #1:
Van::Van(): Truck(), Box()
{
}//Constructor #1:

//Van Constructor#2:

Van::Van(const char* serialNumber, unsigned int passengerCapacity, const char* DOTLicense, float length, float width, float height, bool verbose):
  Truck(serialNumber, passengerCapacity, DOTLicense, verbose), Box (length, width, height, verbose)
{
  if(Vehicle::verbose_ == 1)
  {
    std::cout << "Van()\n";
  }
}

//Destructor: Van
Van::~Van() 
{
  if(Vehicle::verbose_ == 1)
  {
    std::cout << "~Van()\n";
  }
}//Destructor

float Van::LoadCapacity() const
{
  float capacity = Box::Volume();
  return capacity;
}

const char* Van::ShortName() const
{
  return "VAN";
}

//====================Tanker=====================//

//Tanker Constructor #1:

Tanker::Tanker(): Truck(), Cylinder()
{

}//Constructor #1

//Tanker Constructor #2:
Tanker::Tanker(const char* serialNumber, unsigned int passengerCapacity, const char* DOTLicense, float length, float radius, bool verbose):
  Truck(serialNumber, passengerCapacity, DOTLicense, verbose), Cylinder(length, radius, verbose)
{
  if(Vehicle::verbose_ == 1)
  {
    std::cout << "Tanker()\n";
  }
}

//Tanker Destructor:
Tanker::~Tanker()
{
  if(Vehicle::verbose_ == 1)
  {
    std::cout << "~Tanker()\n";
  }
}//Destructor:


//Function: LoadCapacity
float Tanker::LoadCapacity() const
{
  float capacity = Cylinder::Volume();
  return capacity;
}//LoadCapacity

const char* Tanker::ShortName() const
{
  return "TNK";
}

//=================Flatbed====================//

//Flatbed Constructor:
Flatbed::Flatbed(): Truck(), Rectangle()
{
}

Flatbed::Flatbed(const char* serialNumber, unsigned int passengerCapacity, const char* DOTLicense, float length, float width, bool verbose):
  Truck(serialNumber, passengerCapacity, DOTLicense, verbose), Rectangle(length, width, verbose)
{
  if(Vehicle::verbose_ == 1)
  {
    std::cout << "Flatbed()\n";
  }
}

Flatbed::~Flatbed()
{
  if(Vehicle::verbose_ == 1)
  {
    std::cout<< "~Flatbed()\n";
  }
}

float Flatbed::LoadCapacity() const
{
  float capacity = Rectangle::Area();
  return capacity;
}

const char* Flatbed::ShortName() const
{
  return "FLT";
}









  
