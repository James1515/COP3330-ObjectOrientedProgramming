//==================================================
// Author: James Anthony Ortiz
// File: tracker.cpp
// Purpose: implementation file for tracker.cpp
//==================================================

//Pre-processor directives including .h files:
#include <vehicles.h>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <fstream>


//Global Constants to be used later in the program:
const unsigned int cst1=6, 
  cst2 = 7, 
  cst3 = 10, 
  cst4 = 10, 
  c5 = 2, 
  c6 = 2;

//main
//Parameters are used by the command line:
int main (int argc, char* argv[])
{

  //Variable declarations 
  unsigned int maxDOTLength = 0;
  unsigned int maxSNLength = 0;
  const int vMax = 100; //Hold maximum number of vehicles
  const int snMax = 50; //Holds maximum number of sn values
  const int DOTMax = 50; //Holds maximum number of DOT values


  Vehicle*  vehArray[vMax]; //array of type Vehicle * to hold segment objects

  std::cout<< "\nSunPass Tracker started...\n\n";

  std::ifstream ifs; //declare an istream object to read input

  if (argc > 1)
  {
    ifs.open(argv[1]); //if a filename is presented in the c-line, open it
    if (ifs.fail())
    {
      std::cout << " ** cannot open command file " << argv[1] << '\n';
      exit (EXIT_FAILURE);
    }
  } //Otherwise, exit if unable to open file


  unsigned int segSize;
  char sn[snMax];
  unsigned int pc;
  char DOTL[DOTMax];
  float d1, d2, d3;
  VehicleType veh; //veh used to represent vehicle types 

  //Do while loop used to gain information about each type of vehicle
  //from files.
 do
 {

   //Variables meant to hold total values for vehicle types:
   int badSnTotal = 0, 
     vehicleTotal = 0, 
     carTotal = 0, 
     truckTotal = 0, 
     vanTotal =0, 
     tankerTotal = 0, 
     flatbedTotal = 0;

   float totalTonnage = 0.00, 
     totalToll = 0.00;

   std::cin >> segSize; //stream extraction of segment size

   if (segSize == 0 || segSize > vMax) //(segSize == 0 || segSize > 100)
   {
     break; //If segment size is out of range, break from the loop.
   }

   //For-loop, to go through the segment and recieve information 
   //about each vehicle.
   for (size_t i = 0; i < segSize; ++i)
   {
     std::cin >> sn; //extract the sn from the stream
     veh = Vehicle::SnDecode(sn); 

     //Switch statement used to select a particular vehicle type,
     //create new objects, maintain a count of each object, 
     //as well as acessing the toll price for each vehicle.
     switch (veh)
     {
       case badSn:
         std::cin >> pc; //extract pc from the stream
         ++badSnTotal;
         vehArray[i] = new Vehicle(sn, pc, 0); //create object and insert into
                                             //array
         totalToll += (vehArray[i])->Toll();
         break;

       case vehicle:
         std::cin >> pc; //extract pc from the stream
         ++vehicleTotal;
         vehArray[i] = new Vehicle(sn, pc, 0); //create object and insert into
                                             //array
         totalToll += (vehArray[i])->Toll();
         break;

       case car:
         std::cin >> pc; //extract pc from the stream
         ++carTotal;
         vehArray[i] = new Car(sn, pc, 0); //create object and insert into array
         totalToll += (vehArray[i])->Toll();
         break;

       case truck:
         std::cin >> pc >> DOTL;
         ++truckTotal;
         vehArray[i] = new Truck (sn, pc, DOTL, 0);
         totalToll += (vehArray[i])->Toll();
         break;

       case van:
         std::cin >> pc >> DOTL >> d1 >> d2 >> d3;
         ++vanTotal;
         vehArray[i] = new Van (sn, pc, DOTL, d1, d2, d3, 0);
         totalToll += (vehArray[i])->Toll();
         totalTonnage += vehArray[i] -> LoadCapacity();
         //array obj 'van' accesses its LoadCapacity function thru ptr notation
         break;

       case tanker:
         std::cin >> pc >> DOTL >> d1 >> d2;
         ++tankerTotal;
         vehArray[i] = new Tanker (sn, pc, DOTL, d1, d2, 0);
         totalToll += (vehArray[i])->Toll();
         totalTonnage += vehArray[i] -> LoadCapacity();
         //array obj 'tanker' accesses its LoadCapacity function thru ptr
         //notation
         break;

       case flatbed:
         std::cin >> pc >> DOTL >> d1 >> d2;
         ++flatbedTotal;
         vehArray[i] = new Flatbed (sn, pc, DOTL, d1, d2, 0);
         totalToll += (vehArray[i])->Toll();
         totalTonnage += vehArray[i] -> LoadCapacity();
         //array obj 'flatbed' is acessed through pointer notation 
         break;

       default:
         std::cerr << "**ERROR: bad serial number passed to decision logic\n";
         break;
     }
   }

   for (size_t i = 0; i < segSize; ++i)
   {
     unsigned int temp  = strlen(vehArray[i]->SerialNumber());
     if (maxSNLength < temp)
     {
       maxSNLength = temp;
     }
   }

   for (size_t i = 0; i < segSize; ++i)
   {
     if (truck <= Vehicle::SnDecode((vehArray[i])->SerialNumber()))
     {
       unsigned int temp = strlen(dynamic_cast<Truck*>(vehArray[i])->DOTLicense());
       if (maxDOTLength < temp)
       {
         maxDOTLength = temp;
       }
     }
   }

   if (maxDOTLength < 11)
   {
     maxDOTLength = 11;
   }

   if (maxSNLength < 13)
   {
     maxSNLength = 13;
   }

   //Constants used for setting width when displaying information
   //to the screen.
   const unsigned int cst5 = maxDOTLength + c5;
   const unsigned int cst6 = maxSNLength + c6;

   //Selection Display Printed to Screen:
   std::cout << "Segment Summary\n===============\n\n";
   std::cout << "  Cars:     " << carTotal;
   std::cout << "\n  Trucks:   " << truckTotal;
   std::cout << "\n  Vans:     " << vanTotal;
   std::cout << "\n  Tankers:  " << tankerTotal;
   std::cout << "\n  Flatbeds: " << flatbedTotal;
   std::cout << "\n  Unknowns: " << vehicleTotal;
   std::cout << "\n  BadSns:   " << badSnTotal;
   std::cout << "\n  Tonnage:  " << totalTonnage;
   std::cout << "\n  Tolls:    $" << std::fixed << std::setprecision(2) << totalToll;

   std::cout << "\n\nSegment Details\n===============\n\n";
   std::cout << std::setw(cst1) << "Type" << std::setw(cst2) << "Toll" << std::setw(cst3) 
             << "Pass Cap" << std::   setw(cst4) << "Load Cap" 
             << std::setw(cst5) << "DOT License" << std::setw(cst6) << "Serial Number";
   std::cout << '\n';
   std::cout << std::setw(cst1) << "----" << std::setw(cst2) << "----" << std::setw(cst3) 
             << "--------" << std::setw(cst4) << "--------" << std::setw(cst5)    
             << "-----------" << std::setw(cst6) << "-------------";
   std::cout << '\n';


   //For loop used to display  additional information about trucks.
   for (size_t i = 0; i < segSize; ++i)
   {
     std::cout << std::setw(cst1) << (vehArray[i])->ShortName() << std::setw(cst2) 
               << std::setprecision(2) << (vehArray[i])->Toll() << std::setw(cst3) 
               << (vehArray[i])->PassengerCapacity() << std::setw(cst4) << (vehArray[i])->LoadCapacity();
     if (truck <= Vehicle::SnDecode((vehArray[i])->SerialNumber()))
     {
       std::cout << std::setw(cst5)<< dynamic_cast<Truck*>((vehArray[i]))->DOTLicense();
     }
     else
       std::cout << std::setw(cst5) << "(NA)";

     std::cout << std::setw(cst6) << (vehArray[i])->SerialNumber() << "\n";
   }
   maxDOTLength = 0;
   maxSNLength = 0;
   std::cout << "\n";
 } while (segSize != 0); //End of Do-While loop.

 std::cout << "\n...Thank you for using SunPass Tracker.\n\n";
}//End Main
